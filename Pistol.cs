using UnityEngine;

public class Pistol : MonoBehaviour
{
    public int magazineSize = 6;
    public int maxAmmoCapacity = 20;

    private int currentMagazineAmmo;
    private int totalAmmo;

    void Start()
    {
        // Initialize the pistol with a full magazine and the remaining ammo
        currentMagazineAmmo = magazineSize;
        totalAmmo = maxAmmoCapacity - magazineSize;
    }

    // Method to shoot the pistol
    public void Shoot()
    {
        if (currentMagazineAmmo > 0)
        {
            currentMagazineAmmo--;
            Debug.Log("Shot fired! Rounds left in magazine: " + currentMagazineAmmo);
            // Add shooting logic here, like instantiating bullets, playing sound, etc.
        }
        else
        {
            Debug.Log("Magazine is empty! Reload needed.");
        }
    }

    // Method to reload the pistol
    public void Reload()
    {
        if (totalAmmo > 0)
        {
            int ammoNeeded = magazineSize - currentMagazineAmmo;
            int ammoToReload = Mathf.Min(ammoNeeded, totalAmmo);

            currentMagazineAmmo += ammoToReload;
            totalAmmo -= ammoToReload;

            Debug.Log("Reloaded! Current magazine ammo: " + currentMagazineAmmo + ", Total ammo left: " + totalAmmo);
        }
        else
        {
            Debug.Log("No more ammo left to reload!");
        }
    }

    // Method to add ammo (e.g., when picking up ammo packs)
    public void AddAmmo(int amount)
    {
        totalAmmo = Mathf.Min(totalAmmo + amount, maxAmmoCapacity);
        Debug.Log("Ammo added! Total ammo now: " + totalAmmo);
    }

    // Method to get the current ammo status
    public string GetAmmoStatus()
    {
        return "Magazine: " + currentMagazineAmmo + " / " + magazineSize + ", Total Ammo: " + totalAmmo;
    }
}
