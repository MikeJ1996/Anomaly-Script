class TotemPoleLight extends PointLightBase
{
    void TotemPoleLight()
    {
        SetRadiusTo(DEFAULT_RADIUS);
        SetBrightnessTo(DEFAULT_BRIGHTNESS);
        SetFlareVisible(false);
        SetAmbientColor(0.2, 0.2, 1.0);
        SetDiffuseColor(0.2, 0.2, 1.0);
        SetLifetime(5);
        SetDisableShadowsWithinRadius(-1);
    }
}
