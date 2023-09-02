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
        model = "Pole_Anomaly\Data\Pole\Totem_Pole.p3d"; 
        weight = 9999999;
    };
};
