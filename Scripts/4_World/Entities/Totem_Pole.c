class Totem_Pole extends PointLightBase
{
    const static float DEFAULT_RADIUS = 150;
    const static float DEFAULT_BRIGHTNESS = 600;

    Particle p;
    protected SoundOnVehicle m_soundIdleLoop;

    void Totem_Pole()
    {
        SetVisibleDuringDaylight(true);
        SetRadiusTo(DEFAULT_RADIUS);
        SetBrightnessTo(DEFAULT_BRIGHTNESS);
        SetFlareVisible(false);
        SetAmbientColor(0.2, 0.2, 1.0);
        SetDiffuseColor(0.2, 0.2, 1.0);
        SetLifetime(5);
        SetDisableShadowsWithinRadius(-1);
        
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SpawnParticleEffect, 7.5 * 1000, false);
        }
    }

    void ~Totem_Pole()
    {
        if (GetGame())
        {
            if (p)
                p.Stop();
        }
    }

    void SpawnParticleEffect()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            p = Particle.PlayInWorld(ParticleList.Totem_Pole, GetPosition());
        }
    }
}
