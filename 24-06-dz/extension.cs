using System;

namespace ExtensionMethods
{
    public static class StringExtensions
    {
        public static int CountVowels(this string str)
        {
            int count = 0;
            string vowels = "aeiouAEIOU";

            foreach (char c in str)
            {
                if (vowels.Contains(c))
                {
                    count++;
                }
            }

            return count;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Тестирование
            string text1 = "Hello, World!";
            string text2 = "Programming is fun.";

            Console.WriteLine($"Number of vowels in '{text1}': {text1.CountVowels()}");  // Виведе: Number of vowels in 'Hello, World!': 3
            Console.WriteLine($"Number of vowels in '{text2}': {text2.CountVowels()}");  // Виведе: Number of vowels in 'C# programming is fun.': 7
        }
    }
}
