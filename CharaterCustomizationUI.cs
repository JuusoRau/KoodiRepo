using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    public CharacterCustomization characterCustomization;

    public Dropdown genderDropdown;
    public Slider hairColorSlider;
    public Dropdown clothingDropdown;

    void Start()
    {
        // Initialize UI elements
        genderDropdown.onValueChanged.AddListener(delegate { OnGenderChanged(); });
        hairColorSlider.onValueChanged.AddListener(delegate { OnHairColorChanged(); });
        clothingDropdown.onValueChanged.AddListener(delegate { OnClothingChanged(); });

        // Set default values if necessary
    }

    void OnGenderChanged()
    {
        characterCustomization.ChangeGender((CharacterCustomization.Gender)genderDropdown.value);
    }

    void OnHairColorChanged()
    {
        // Assuming hair color slider gives values from 0 to 1
        float value = hairColorSlider.value;
        Color color = new Color(value, value, value); // Simple grayscale for example
        characterCustomization.ChangeHairColor(color);
    }

    void OnClothingChanged()
    {
        characterCustomization.ChangeClothing(clothingDropdown.value);
    }
}

