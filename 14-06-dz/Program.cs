using System;
using System.Collections.Generic;


//Створіть додаток, що емулює чергу в популярне кафе. Відвідувачі кафе приходять та потрапляють у чергу, якщо немає вільного місця.
//Коли столик в кафе стає вільним, перший відвідувач з черги займає його.
//Якщо приходить відвідувач, який резервував столик на певний час,
//він отримує зарезервований столик позачергово.

class Visitor
{
    public string Name { get; set; }
    public bool HasReservation { get; set; }
    public DateTime ReservationTime { get; set; }

    public Visitor(string name, bool hasReservation = false, DateTime reservationTime = default)
    {
        Name = name;
        HasReservation = hasReservation;
        ReservationTime = reservationTime;
    }
}

class CafeQueue
{
    private Queue<Visitor> queue;
    private List<Visitor> reservedVisitors;
    private int availableTables;

    public CafeQueue(int tableCount)
    {
        queue = new Queue<Visitor>();
        reservedVisitors = new List<Visitor>();
        availableTables = tableCount;
    }

    public void AddVisitor(Visitor visitor)
    {
        if (visitor.HasReservation)
        {
            reservedVisitors.Add(visitor);
            Console.WriteLine($"{visitor.Name} добавлен в список бронирования на {visitor.ReservationTime}.");
        }
        else
        {
            queue.Enqueue(visitor);
            Console.WriteLine($"{visitor.Name} добавлен в очередь.");
        }

        AllocateTables();
    }

    public void FreeTable()
    {
        availableTables++;
        Console.WriteLine("Столик освободился.");
        AllocateTables();
    }

    private void AllocateTables()
    {
        while (availableTables > 0 && (reservedVisitors.Count > 0 || queue.Count > 0))
        {
            if (reservedVisitors.Count > 0 && reservedVisitors[0].ReservationTime <= DateTime.Now)
            {
                var reservedVisitor = reservedVisitors[0];
                reservedVisitors.RemoveAt(0);
                availableTables--;
                Console.WriteLine($"{reservedVisitor.Name} с бронированием занял столик.");
            }
            else if (queue.Count > 0)
            {
                var visitor = queue.Dequeue();
                availableTables--;
                Console.WriteLine($"{visitor.Name} из очереди занял столик.");
            }
        }
    }

    public void DisplayQueue()
    {
        Console.WriteLine("Очередь:");
        foreach (var visitor in queue)
        {
            Console.WriteLine(visitor.Name);
        }

        Console.WriteLine("Забронированные:");
        foreach (var visitor in reservedVisitors)
        {
            Console.WriteLine($"{visitor.Name} на {visitor.ReservationTime}");
        }
    }
}

class Program
{
    static void Main()
    {
        CafeQueue cafeQueue = new CafeQueue(3);  // Указываем количество столиков в кафе

        while (true)
        {
            Console.WriteLine("\nМеню:");
            Console.WriteLine("1. Добавить посетителя без бронирования");
            Console.WriteLine("2. Добавить посетителя с бронированием");
            Console.WriteLine("3. Освободить столик");
            Console.WriteLine("4. Показать очередь");
            Console.WriteLine("5. Выход");
            Console.Write("Выберите опцию: ");

            int choice;
            if (int.TryParse(Console.ReadLine(), out choice))
            {
                switch (choice)
                {
                    case 1:
                        Console.Write("Введите имя посетителя: ");
                        string visitorName = Console.ReadLine();
                        cafeQueue.AddVisitor(new Visitor(visitorName));
                        break;
                    case 2:
                        Console.Write("Введите имя посетителя: ");
                        string reservedVisitorName = Console.ReadLine();
                        Console.Write("Введите время бронирования (yyyy-MM-dd HH:mm): ");
                        DateTime reservationTime;
                        if (DateTime.TryParse(Console.ReadLine(), out reservationTime))
                        {
                            cafeQueue.AddVisitor(new Visitor(reservedVisitorName, true, reservationTime));
                        }
                        else
                        {
                            Console.WriteLine("Неверный формат времени.");
                        }
                        break;
                    case 3:
                        cafeQueue.FreeTable();
                        break;
                    case 4:
                        cafeQueue.DisplayQueue();
                        break;
                    case 5:
                        return;
                    default:
                        Console.WriteLine("Неверная опция. Попробуйте еще раз.");
                        break;
                }
            }
            else
            {
                Console.WriteLine("Неверный ввод. Попробуйте еще раз.");
            }
        }
    }
}