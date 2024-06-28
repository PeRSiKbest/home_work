using System;

public class Journal
{
    private int _numberOfEmployees;

    public int NumberOfEmployees
    {
        get { return _numberOfEmployees; }
        set
        {
            if (value < 0)
                throw new ArgumentException("Количество работников не может быть меньше 0.");
            _numberOfEmployees = value;
        }
    }

    public Journal(int numberOfEmployees)
    {
        NumberOfEmployees = numberOfEmployees;
    }

    public static Journal operator +(Journal journal, int employees)
    {
        return new Journal(journal.NumberOfEmployees + employees);
    }

    public static Journal operator -(Journal journal, int employees)
    {
        return new Journal(journal.NumberOfEmployees - employees);
    }

    public static bool operator ==(Journal journal1, Journal journal2)
    {
        if (ReferenceEquals(journal1, null))
            return ReferenceEquals(journal2, null);

        return journal1.Equals(journal2);
    }

    public static bool operator !=(Journal journal1, Journal journal2)
    {
        return !(journal1 == journal2);
    }

    public static bool operator <(Journal journal1, Journal journal2)
    {
        return journal1.NumberOfEmployees < journal2.NumberOfEmployees;
    }

    public static bool operator >(Journal journal1, Journal journal2)
    {
        return journal1.NumberOfEmployees > journal2.NumberOfEmployees;
    }

    public override bool Equals(object obj)
    {
        if (obj is Journal otherJournal)
            return this.NumberOfEmployees == otherJournal.NumberOfEmployees;

        return false;
    }

    public override int GetHashCode()
    {
        return NumberOfEmployees.GetHashCode();
    }
}

class Journals
{
    static void Main()
    {
        Console.Write("Введите к-во работников для 1ого журнала: ");
        int employees1 = Convert.ToInt32(Console.ReadLine());
        Journal journal1 = new Journal(employees1);

        Console.Write("Введите к-во работников для 2ого журнала: ");
        int employees2 = Convert.ToInt32(Console.ReadLine());
        Journal journal2 = new Journal(employees2);

        Console.WriteLine($"Журнал 1: {journal1.NumberOfEmployees} работника(ов)");
        Console.WriteLine($"Журнал 2: {journal2.NumberOfEmployees} работника(ов)");

        Console.WriteLine($"Журнал 1 == Журнал 2: {journal1 == journal2}");
        Console.WriteLine($"Журнал 1 != Журнал 2: {journal1 != journal2}");
        Console.WriteLine($"Журнал 1 < Журнал 2: {journal1 < journal2}");
        Console.WriteLine($"Журнал 1 > Журнал 2: {journal1 > journal2}");

        Console.Write("Введите к-во работников чтоб ДОБАВИТЬ их к 1ому журналу: ");
        int addEmployees1 = Convert.ToInt32(Console.ReadLine());
        journal1 += addEmployees1;
        Console.WriteLine($"Журнал 1 теперь имеет: {journal1.NumberOfEmployees} работника(ов)");

        Console.Write("Введите к-во работников чтоб ОТНЯТЬ их у 2ого журнала: ");
        int subtractEmployees2 = Convert.ToInt32(Console.ReadLine());
        journal2 -= subtractEmployees2;
        Console.WriteLine($"Журнал 2 теперь имеет: {journal2.NumberOfEmployees} работника(ов)");

        Console.WriteLine($"Журнал 1 == Журнал 2: {journal1 == journal2}");
    }
}