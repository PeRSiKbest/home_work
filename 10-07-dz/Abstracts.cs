// Травоядное
using System.Collections.Generic;

public abstract class Herbivore
{
    public int Weight { get; protected set; }
    public bool Life { get; private set; } = true;

    public abstract void EatGrass();

    // Его скушали
    public void Die()
    {
        Life = false;
    }
}

// Мясоед
public abstract class Carnivore
{
    public int Power { get; protected set; }

    // Мясоед ест травоядного
    public abstract void Eat(Herbivore herbivore);
}

// Континент
public abstract class Continent
{
    public abstract List<Herbivore> CreateHerbivores();
    public abstract List<Carnivore> CreateCarnivores();
}