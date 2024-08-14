// Африка
using System.Collections.Generic;

public class Africa : Continent
{
    public override List<Herbivore> CreateHerbivores()
    {
        return new List<Herbivore> { new Wildebeest() };
    }

    public override List<Carnivore> CreateCarnivores()
    {
        return new List<Carnivore> { new Lion() };
    }
}

// Северная Америка
public class NorthAmerica : Continent
{
    public override List<Herbivore> CreateHerbivores()
    {
        return new List<Herbivore> { new Bison() };
    }

    public override List<Carnivore> CreateCarnivores()
    {
        return new List<Carnivore> { new Wolf() };
    }
}
