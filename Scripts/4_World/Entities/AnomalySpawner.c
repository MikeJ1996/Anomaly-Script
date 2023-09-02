class AnomalySpawner
{
    // Constructor
    void AnomalySpawner()
    {
        // You can add initialization code here if needed
    }

    // Function to spawn the Totem_Pole anomaly
    void SpawnTotemPoleAnomaly(vector position)
    {
        if (GetGame())
        {
            GetGame().CreateObject("Totem_Pole", position, false, true, true);
        }
    }
}