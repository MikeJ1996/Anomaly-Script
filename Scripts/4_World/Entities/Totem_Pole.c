class Totem_Pole extends Building
{
    const static float DEFAULT_RADIUS = 150;
    const static float DEFAULT_BRIGHTNESS = 600;

    Particle p;
    protected SoundOnVehicle m_soundIdleLoop;
    private ref PointLight m_LightSource; // Light source

    void Totem_Pole()
    {
        // Initialize the light source
        m_LightSource = PointLight.Cast(GetGame().CreateObject("PointLight", GetPosition(), false, true, true));
        if (m_LightSource)
        {
            m_LightSource.SetRadius(DEFAULT_RADIUS);
            m_LightSource.SetBrightness(DEFAULT_BRIGHTNESS);
            m_LightSource.SetFlareVisible(false);
            m_LightSource.SetAmbientColor(0.2, 0.2, 1.0);
            m_LightSource.SetDiffuseColor(0.2, 0.2, 1.0);
            m_LightSource.SetLifetime(5);
            m_LightSource.SetDisableShadowsWithinRadius(-1);
            m_LightSource.AttachTo(this); // Attach the light source to the Totem_Pole
        }
        
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

            // Ensure the light source is deleted when the Totem_Pole is deleted
            if (m_LightSource)
                GetGame().ObjectDelete(m_LightSource);
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