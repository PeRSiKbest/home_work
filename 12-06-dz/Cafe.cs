using System;
using System.Collections;
using System.Collections.Generic;

// Баз. класс
public class CafeEmployee
{
    public string Name { get; set; } //Имя
    public string Position { get; set; } //Должность

    public CafeEmployee(string name, string position)
    {
        Name = name;
        Position = position;
    }

    public override string ToString()
    {
        return $"{Name} ({Position})";
    }
}

// Разные работники
public class Barista : CafeEmployee
{
    public Barista(string name) : base(name, "Barista") { }
}

public class Chef : CafeEmployee
{
    public Chef(string name) : base(name, "Chef") { }
}

public class Waiter : CafeEmployee
{
    public Waiter(string name) : base(name, "Waiter") { }
}

// Кафе
public class Cafe : IEnumerable<CafeEmployee>
{
    private List<CafeEmployee> employees = new List<CafeEmployee>();

    public void AddEmployee(CafeEmployee employee)
    {
        employees.Add(employee);
    }

    public IEnumerator<CafeEmployee> GetEnumerator()
    {
        return employees.GetEnumerator();
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
        Cafe cafe = new Cafe();

        // Работники
        cafe.AddEmployee(new Barista("Alice"));
        cafe.AddEmployee(new Chef("Bob"));
        cafe.AddEmployee(new Waiter("Charlie"));

        foreach (var employee in cafe)
        {
            Console.WriteLine(employee);
        }
    }
}