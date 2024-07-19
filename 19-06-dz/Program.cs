using System;
using System.Collections.Generic;

public class Performance : IDisposable
{
    public string Title { get; private set; }
    public string TheaterName { get; private set; }
    public string Genre { get; private set; }
    public TimeSpan Duration { get; private set; }
    public List<string> Cast { get; private set; }

    public Performance(string title, string theaterName, string genre, TimeSpan duration, List<string> cast)
    {
        Title = title;
        TheaterName = theaterName;
        Genre = genre;
        Duration = duration;
        Cast = cast;
    }

    // Добавить актера
    public void AddActor(string actor)
    {
        Cast.Add(actor);
    }

    // Удалить актера
    public void RemoveActor(string actor)
    {
        Cast.Remove(actor);
    }

    // Интерфейс IDisposable
    public void Dispose()
    {
        // Освобождаем ресурсы, если это необходимо
        Console.WriteLine("Вызов метода Dispose");
    }

    // Деструктор
    ~Performance()
    {
        Dispose();
        Console.WriteLine("Вызов деструктора");
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        List<string> actors = new List<string> { "Actor1", "Actor2" };
        Performance performance = new Performance("Romeo and Juliet", "National Theater", "Tragedy", new TimeSpan(2, 30, 0), actors);

        performance.AddActor("Actor3");
        performance.RemoveActor("Actor1");

        Console.WriteLine($"Название: {performance.Title}");
        Console.WriteLine($"Название театра: {performance.TheaterName}");
        Console.WriteLine($"Жанр: {performance.Genre}");
        Console.WriteLine($"Продолжительность: {performance.Duration}");
        Console.WriteLine("Актерский состав:");
        foreach (var actor in performance.Cast)
        {
            Console.WriteLine(actor);
        }

        // Вызов метода Dispose вручную
        performance.Dispose();
    }
}