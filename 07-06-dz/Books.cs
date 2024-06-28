using System;
using System.Collections.Generic;

public class Book
{
    public string Title { get; set; }
    public string Author { get; set; }

    public Book(string title, string author)
    {
        Title = title;
        Author = author;
    }

    public override string ToString()
    {
        return $"{Title} by {Author}";
    }

    public override bool Equals(object obj)
    {
        if (obj is Book otherBook)
        {
            return this.Title == otherBook.Title && this.Author == otherBook.Author;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return (Title, Author).GetHashCode();
    }

    public static bool operator ==(Book book1, Book book2)
    {
        if (ReferenceEquals(book1, null))
            return ReferenceEquals(book2, null);
        return book1.Equals(book2);
    }

    public static bool operator !=(Book book1, Book book2)
    {
        return !(book1 == book2);
    }
}

public class ReadingList
{
    private List<Book> books = new List<Book>();

    public int Count
    {
        get { return books.Count; }
    }

    public Book this[int index]
    {
        get { return books[index]; }
        set { books[index] = value; }
    }

    public void AddBook(Book book)
    {
        if (!books.Contains(book))
        {
            books.Add(book);
            Console.WriteLine($"{book} была добавлена в список для чтения.");
        }
        else
        {
            Console.WriteLine($"{book} уже есть в списке для чтения.");
        }
    }

    public void RemoveBook(Book book)
    {
        if (books.Contains(book))
        {
            books.Remove(book);
            Console.WriteLine($"{book} была удалена со списка для чтения.");
        }
        else
        {
            Console.WriteLine($"{book} не состоит в списке для чтения.");
        }
    }

    public bool Contains(Book book)
    {
        return books.Contains(book);
    }

    public static ReadingList operator +(ReadingList readingList, Book book)
    {
        readingList.AddBook(book);
        return readingList;
    }

    public static ReadingList operator -(ReadingList readingList, Book book)
    {
        readingList.RemoveBook(book);
        return readingList;
    }
}

class Program
{
    static void Main()
    {
        ReadingList readingList = new ReadingList();

        while (true)
        {
            Console.WriteLine("Меню:");
            Console.WriteLine("1. Добавить книгу");
            Console.WriteLine("2. Удалить книгу");
            Console.WriteLine("3. Проверить, есть ли книга в списке для чтения");
            Console.WriteLine("4. Показать все книги со списка");
            Console.WriteLine("0. Выход");
            Console.Write("Выберите действие: ");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    AddBookToList(readingList);
                    break;
                case 2:
                    RemoveBookFromList(readingList);
                    break;
                case 3:
                    CheckBookInList(readingList);
                    break;
                case 4:
                    ShowAllBooks(readingList);
                    break;
                case 0:
                    return;
                default:
                    Console.WriteLine("Неправильный выбор, попробуйте снова.");
                    break;
            }
        }
    }

    static void AddBookToList(ReadingList readingList)
    {
        Console.Write("Введите название книги: ");
        string title = Console.ReadLine();
        Console.Write("Введите автора книги: ");
        string author = Console.ReadLine();
        Book book = new Book(title, author);
        readingList += book;
    }

    static void RemoveBookFromList(ReadingList readingList)
    {
        Console.Write("Введите название книги, подлежащей удалению: ");
        string title = Console.ReadLine();
        Console.Write("Введите автора книги, подлежащей удалению: ");
        string author = Console.ReadLine();
        Book book = new Book(title, author);
        readingList -= book;
    }

    static void CheckBookInList(ReadingList readingList)
    {
        Console.Write("Введите название книги для проверки: ");
        string title = Console.ReadLine();
        Console.Write("Введите автора книги для проверки: ");
        string author = Console.ReadLine();
        Book book = new Book(title, author);
        bool isInList = readingList.Contains(book);
        Console.WriteLine($"Есть ли '{book}' в списке для чтения? {isInList}");
    }

    static void ShowAllBooks(ReadingList readingList)
    {
        Console.WriteLine("Книги в списке для чтения:");
        for (int i = 0; i < readingList.Count; i++)
        {
            Console.WriteLine($"Книга {i + 1}: {readingList[i]}");
        }
    }
}
