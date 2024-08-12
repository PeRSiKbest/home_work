using System;
using System.Linq;

namespace RecordExample
{
    public record Person(string FirstName, string LastName, int Age);

    public static class PersonExtensions
    {
        // Средний возраст
        public static double AverageAge(this Person[] people)
        {
            return people.Average(p => p.Age);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person[] people = new Person[]
            {
                new Person("Name1", "Surname1", 25),
                new Person("Name2", "Surname2", 30),
                new Person("Name3", "Surname3", 40),
                new Person("Name4", "Surname4", 22),
                new Person("Name5", "Surname5", 35)
            };

            // Мин. возраст
            Person youngest = people.OrderBy(p => p.Age).First();
            Console.WriteLine($"Youngest person: {youngest.FirstName} {youngest.LastName}, Age: {youngest.Age}");

            // Макс. возраст
            Person oldest = people.OrderByDescending(p => p.Age).First();
            Console.WriteLine($"Oldest person: {oldest.FirstName} {oldest.LastName}, Age: {oldest.Age}");

            // Средний возраст
            double averageAge = people.AverageAge();
            Console.WriteLine($"Average age: {averageAge}");
        }
    }
}