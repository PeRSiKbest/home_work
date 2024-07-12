using System;
using System.Collections;
using System.Collections.Generic;


public class OceanInhabitant
{
    public string Name { get; set; } //Имя 
    public string Species { get; set; } // Вид

    public OceanInhabitant(string name, string species)
    {
        Name = name;
        Species = species;
    }

    public override string ToString()
    {
        return $"{Name} ({Species})";
    }
}

// Рибка
public class Fish : OceanInhabitant
{
    public Fish(string name) : base(name, "Fish") { }
}

//Акулка
public class Shark : OceanInhabitant
{
    public Shark(string name) : base(name, "Shark") { }
}

//Дельфин
public class Dolphin : OceanInhabitant
{
    public Dolphin(string name) : base(name, "Dolphin") { }
}

// Океанариум
public class Oceanarium : IEnumerable<OceanInhabitant>
{
    private List<OceanInhabitant> inhabitants = new List<OceanInhabitant>();

    public void AddInhabitant(OceanInhabitant inhabitant)
    {
        inhabitants.Add(inhabitant);
    }

    public IEnumerator<OceanInhabitant> GetEnumerator()
    {
        return inhabitants.GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

public class Program
{
    public static void Main()
    {
        Oceanarium oceanarium = new Oceanarium();

        // Жители
        oceanarium.AddInhabitant(new Fish("Nemo"));
        oceanarium.AddInhabitant(new Shark("Jaws"));
        oceanarium.AddInhabitant(new Dolphin("Flipper"));

        foreach (var inhabitant in oceanarium)
        {
            Console.WriteLine(inhabitant);
        }
    }
}