using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class Poem
{
    public string Title { get; set; }
    public string Author { get; set; }
    public int Year { get; set; }
    public string Text { get; set; }
    public string Theme { get; set; }

    public Poem(string title, string author, int year, string text, string theme)
    {
        Title = title;
        Author = author;
        Year = year;
        Text = text;
        Theme = theme;
    }

    public override string ToString()
    {
        return $"Title: {Title}\nAuthor: {Author}\nYear: {Year}\nTheme: {Theme}\nText:\n{Text}";
    }
}

public class PoemCollection
{
    private List<Poem> poems = new List<Poem>();

    public void AddPoem(Poem poem)
    {
        poems.Add(poem);
    }

    public void RemovePoem(string title)
    {
        Poem poem = poems.FirstOrDefault(p => p.Title.Equals(title, StringComparison.OrdinalIgnoreCase));
        if (poem != null)
        {
            poems.Remove(poem);
        }
    }

    public void UpdatePoem(string title, Poem updatedPoem)
    {
        int index = poems.FindIndex(p => p.Title.Equals(title, StringComparison.OrdinalIgnoreCase));
        if (index != -1)
        {
            poems[index] = updatedPoem;
        }
    }

    public Poem SearchPoem(string keyword)
    {
        return poems.FirstOrDefault(p =>
            p.Title.IndexOf(keyword, StringComparison.OrdinalIgnoreCase) >= 0 ||
            p.Author.IndexOf(keyword, StringComparison.OrdinalIgnoreCase) >= 0 ||
            p.Theme.IndexOf(keyword, StringComparison.OrdinalIgnoreCase) >= 0);
    }


    public void SaveToFile(string filePath)
    {
        using (StreamWriter writer = new StreamWriter(filePath))
        {
            foreach (Poem poem in poems)
            {
                writer.WriteLine($"{poem.Title}|{poem.Author}|{poem.Year}|{poem.Text}|{poem.Theme}");
            }
        }
    }

    public void LoadFromFile(string filePath)
    {
        poems.Clear();
        using (StreamReader reader = new StreamReader(filePath))
        {
            string line;
            while ((line = reader.ReadLine()) != null)
            {
                string[] parts = line.Split('|');
                if (parts.Length == 5)
                {
                    Poem poem = new Poem(parts[0], parts[1], int.Parse(parts[2]), parts[3], parts[4]);
                    poems.Add(poem);
                }
            }
        }
    }

    public void DisplayAllPoems()
    {
        foreach (var poem in poems)
        {
            Console.WriteLine(poem);
            Console.WriteLine("----------");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        PoemCollection collection = new PoemCollection();
        bool exit = false;

        while (!exit)
        {
            Console.WriteLine("1. Добавить стих");
            Console.WriteLine("2. Удалить стих");
            Console.WriteLine("3. Изменить информацию про стих");
            Console.WriteLine("4. Искать стих");
            Console.WriteLine("5. Сохранить стихи в файл");
            Console.WriteLine("6. Загрузить стихи с файла (text1.txt");
            Console.WriteLine("7. Показать все стихи");
            Console.WriteLine("8. Выйти");

            switch (Console.ReadLine())
            {
                case "1":
                    AddPoem(collection);
                    break;
                case "2":
                    RemovePoem(collection);
                    break;
                case "3":
                    UpdatePoem(collection);
                    break;
                case "4":
                    SearchPoem(collection);
                    break;
                case "5":
                    SaveCollection(collection);
                    break;
                case "6":
                    LoadCollection(collection);
                    break;
                case "7":
                    collection.DisplayAllPoems();
                    break;
                case "8":
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Неверный ввод");
                    break;
            }
        }
    }

    static void AddPoem(PoemCollection collection)
    {
        Console.Write("Введите название стиха: ");
        string title = Console.ReadLine();
        Console.Write("Введите Ф.И.О. автора: ");
        string author = Console.ReadLine();
        Console.Write("Введите год написания: ");
        int year = int.Parse(Console.ReadLine());
        Console.Write("Введите текст стиха: ");
        string text = Console.ReadLine();
        Console.Write("Введите тему стиха: ");
        string theme = Console.ReadLine();

        Poem poem = new Poem(title, author, year, text, theme);
        collection.AddPoem(poem);
    }

    static void RemovePoem(PoemCollection collection)
    {
        Console.Write("Введите название стиха, который нужно удалить: ");
        string title = Console.ReadLine();
        collection.RemovePoem(title);
    }

    static void UpdatePoem(PoemCollection collection)
    {
        Console.Write("Введите название стиха, который нужно изменить: ");
        string title = Console.ReadLine();
        Console.Write("Введите новое название стиха: ");
        string newTitle = Console.ReadLine();
        Console.Write("Введите новый Ф.И.О. автора: ");
        string newAuthor = Console.ReadLine();
        Console.Write("Введите новый год написания: ");
        int newYear = int.Parse(Console.ReadLine());
        Console.Write("Введите новый текст стиха: ");
        string newText = Console.ReadLine();
        Console.Write("Введите новую тему стиха: ");
        string newTheme = Console.ReadLine();

        Poem updatedPoem = new Poem(newTitle, newAuthor, newYear, newText, newTheme);
        collection.UpdatePoem(title, updatedPoem);
    }

    static void SearchPoem(PoemCollection collection)
    {
        Console.Write("Введите ключевое слово для поиска: ");
        string keyword = Console.ReadLine();
        Poem poem = collection.SearchPoem(keyword);
        if (poem != null)
        {
            Console.WriteLine(poem);
        }
        else
        {
            Console.WriteLine("Стих не найден.");
        }
    }

    static void SaveCollection(PoemCollection collection)
    {
        Console.Write("Введите путь к файлу для сохранения: ");
        string filePath = Console.ReadLine();
        collection.SaveToFile(filePath);
    }

    static void LoadCollection(PoemCollection collection)
    {
        Console.Write("Введите путь к файлу для загрузки: ");
        string filePath = Console.ReadLine();
        collection.LoadFromFile(filePath);
    }
}