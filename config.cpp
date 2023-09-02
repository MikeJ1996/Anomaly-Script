class CfgPatches
{
    class Totem_Pole
    {
        units[] = {"Totem_Pole"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "DZ_Data",
            "DZ_Sounds_Effects",
            "DZ_Weapons_Explosives"
        };
    };
};

class CfgMods
{
    class Totem_Pole
    {
        author = "MikeJ";
        type = "mod";
        dependencies[] = {
            "Game",
            "World"
        };
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {
                    "Pole_Anomaly\scripts\3_Game"
                };
            };
            class worldScriptModule
            {
                value = "";
                files[] = {
                    "Pole_Anomaly\scripts\4_World"
                };
            };
        };
    };
};

class CfgVehicles
{
    class HouseNoDestruct;
    class Totem_Pole : HouseNoDestruct
    {
        scope = 2;
        displayName = "Totem Pole Anomaly";
        descriptionShort = "Totem Pole shaped anomaly";
        model = "\dz\weapons\explosives\fakeexplosion.p3d"; 
        weight = 9999999;
    };
};
class CfgAmmo
{
	class DefaultAmmo;

	class Totem_Pole: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=1;
		indirectHitRangeMultiplier=1;
		explosive=1;
		typicalSpeed=1;
		initSpeed=1;
		simulation="shotShell";
		simulationStep=0.050000001;
        effect="Totem_PoleEffectParticle";
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=0;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=10;
			};
		};
		class NoiseExplosion
		{
			strength=210;
			type="shot";
		};
	};
};