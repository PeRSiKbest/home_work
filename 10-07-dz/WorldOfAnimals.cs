using System.Collections.Generic;

public class AnimalWorld
{
    private List<Herbivore> herbivores;
    private List<Carnivore> carnivores;

    public AnimalWorld(Continent continent)
    {
        herbivores = continent.CreateHerbivores();
        carnivores = continent.CreateCarnivores();
    }

    public void MealsHerbivores()
    {
        foreach (var herbivore in herbivores)
        {
            herbivore.EatGrass();
        }
    }

    public void NutritionCarnivores()
    {
        foreach (var carnivore in carnivores)
        {
            foreach (var herbivore in herbivores)
            {
                carnivore.Eat(herbivore);
            }
        }
    }
}