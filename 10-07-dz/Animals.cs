// Антилопа
using System;

public class Wildebeest : Herbivore
{
    public Wildebeest()
    {
        Weight = 150;
    }

    public override void EatGrass()
    {
        if (Life)
        {
            Weight += 10;
            Console.WriteLine("Антилопа сьела травку и стала сильнее.");
        }
    }
}

// Бизон
public class Bison : Herbivore
{
    public Bison()
    {
        Weight = 200;
    }

    public override void EatGrass()
    {
        if (Life)
        {
            Weight += 10;
            Console.WriteLine("Бизон сьел травку и стал сильнее.");
        }
    }
}

// Лев
public class Lion : Carnivore
{
    public Lion()
    {
        Power = 300;
    }

    public override void Eat(Herbivore herbivore)
    {
        if (herbivore.Life && Power > herbivore.Weight)
        {
            Power += 10;
            herbivore.Die(); // "Убиваем" сьеденного травоядного
            Console.WriteLine("Лев поохотился и стал сильнее.");
        }
        else
        {
            Power -= 10;
            Console.WriteLine("Лев провалил охоту и был ранен, ослаб.");
        }
    }
}

// Волк
public class Wolf : Carnivore
{
    public Wolf()
    {
        Power = 100;
    }

    public override void Eat(Herbivore herbivore)
    {
        if (herbivore.Life && Power > herbivore.Weight)
        {
            Power += 10;
            herbivore.Die();
            Console.WriteLine("Волк поохотился и стал сильнее.");
        }
        else
        {
            Power -= 10;
            Console.WriteLine("Волк провалил охоту и был ранен, ослаб.");
        }
    }
}