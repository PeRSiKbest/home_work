using System;

namespace AllDz
{

    public delegate double Arithmetic(double a, double b);

    class Program
    { 
        //2 задание. Школьная арифметика с инвоком
        static double Add(double a, double b)
        {
            return a + b;
        }

        static double Subtract(double a, double b)
        {
            return a - b;
        }

        static double Multiply(double a, double b)
        {
            return a * b;
        }

        // 3 задание. Проверки с предикатом
        static bool IsEven(int number)
        {
            return number % 2 == 0;
        }

        static bool IsOdd(int number)
        {
            return number % 2 != 0;
        }

        static bool IsPrime(int number)
        {
            if (number <= 1) return false;
            for (int i = 2; i <= Math.Sqrt(number); i++)
            {
                if (number % i == 0) return false;
            }
            return true;
        }

        static bool IsFibonacci(int number)
        {
            int a = 0, b = 1, temp = 0;
            while (temp < number)
            {
                temp = a + b;
                a = b;
                b = temp;
            }
            return number == temp || number == 0;
        }

        static void Main(string[] args)
        {
            // Пример арифм. операций с Инвок
            Arithmetic operation;

            // +
            operation = Add;
            Console.WriteLine("+ using Invoke: " + operation.Invoke(10, 5));

            // -
            operation = Subtract;
            Console.WriteLine("- using Invoke: " + operation.Invoke(10, 5));

            // *
            operation = Multiply;
            Console.WriteLine("* using Invoke: " + operation.Invoke(10, 5));


            Console.WriteLine("\nЗадание 3. Проверка чисел с предикатом");

            Predicate<int> checkEven = IsEven;
            Predicate<int> checkOdd = IsOdd;
            Predicate<int> checkPrime = IsPrime;
            Predicate<int> checkFibonacci = IsFibonacci;

            int number = 13;
            Console.WriteLine($"{number} is even: {checkEven(number)}");
            Console.WriteLine($"{number} is odd: {checkOdd(number)}");
            Console.WriteLine($"{number} is prime: {checkPrime(number)}");
            Console.WriteLine($"{number} is Fibonacci: {checkFibonacci(number)}");

            // Проверка с другим числом
            Console.WriteLine($"\nПроверка с другим числом - 8");
            number = 8;
            Console.WriteLine($"\n{number} is even: {checkEven(number)}");
            Console.WriteLine($"{number} is odd: {checkOdd(number)}");
            Console.WriteLine($"{number} is prime: {checkPrime(number)}");
            Console.WriteLine($"{number} is Fibonacci: {checkFibonacci(number)}");
        }
    }
}