using System;

class Program
{
    static void Main(string[] args)
    {
        Continent africa = new Africa();
        AnimalWorld worldAfrica = new AnimalWorld(africa);

        Console.WriteLine("Кормим травоядных в Африке:");
        worldAfrica.MealsHerbivores();

        Console.WriteLine("\nУстраиваем охоту в Африке:");
        worldAfrica.NutritionCarnivores();

        Continent northAmerica = new NorthAmerica();
        AnimalWorld worldNorthAmerica = new AnimalWorld(northAmerica);

        Console.WriteLine("\nКормим травоядных в Северной Америке:");
        worldNorthAmerica.MealsHerbivores();

        Console.WriteLine("\nУстраиваем охоту в Северной Америке:");
        worldNorthAmerica.NutritionCarnivores();
    }
}