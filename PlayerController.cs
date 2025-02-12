public class PlayerController : MonoBehaviour
{
    public Pistol pistol;

    void Update()
    {
        if (Input.GetButtonDown("Fire1"))
        {
            pistol.Shoot();
        }

        if (Input.GetKeyDown(KeyCode.R))
        {
            pistol.Reload();
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            pistol.AddAmmo(10); // Simulate picking up an ammo pack with 10 rounds
        }

        if (Input.GetKeyDown(KeyCode.P))
        {
            Debug.Log(pistol.GetAmmoStatus());
        }
    }
}
