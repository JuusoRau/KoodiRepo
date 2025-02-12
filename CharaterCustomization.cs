using UnityEngine;

public class CharacterCustomization : MonoBehaviour
{
    public enum Gender { Male, Female }

    [System.Serializable]
    public class CustomizableOptions
    {
        public Gender gender;
        public Color hairColor;
        public GameObject[] clothingOptions;
    }

    public CustomizableOptions currentOptions;

    public GameObject maleModel;
    public GameObject femaleModel;

    public Renderer hairRenderer;

    private GameObject currentModel;

    void Start()
    {
        // Initialize with default values
        currentOptions.gender = Gender.Male;
        currentOptions.hairColor = Color.black;
        ChangeClothing(0);
        ApplyCustomization();
    }

    public void ChangeGender(Gender gender)
    {
        currentOptions.gender = gender;
        ApplyCustomization();
    }

    public void ChangeHairColor(Color color)
    {
        currentOptions.hairColor = color;
        ApplyCustomization();
    }

    public void ChangeClothing(int index)
    {
        if (index < 0 || index >= currentOptions.clothingOptions.Length)
        {
            Debug.LogError("Invalid clothing index");
            return;
        }

        foreach (var clothing in currentOptions.clothingOptions)
        {
            clothing.SetActive(false);
        }

        currentOptions.clothingOptions[index].SetActive(true);
    }

    void ApplyCustomization()
    {
        // Switch character model based on gender
        if (currentModel != null)
        {
            Destroy(currentModel);
        }

        currentModel = Instantiate(currentOptions.gender == Gender.Male ? maleModel : femaleModel, transform);

        // Apply hair color
        hairRenderer = currentModel.GetComponentInChildren<Renderer>(); // Assuming hair renderer is a child
        hairRenderer.material.color = currentOptions.hairColor;
    }
}

