using System;
using System.Collections;
using System.Collections.Generic;

class Book : IComparable
{
    string title;
    string author;
    public Book(string title, string author)
    {
        this.title = title;
        this.author = author;
    }
    public Book() : this("Unknown Title", "Unknown Author") { }
    public void Show()
    {
        Console.WriteLine("\nTitle: {0}, Author: {1}", title, author);
    }
    public int CompareTo(object obj)
    {
        if (obj is Book)
            return title.CompareTo((obj as Book).title);

        throw new ArgumentException("Object is not a Book");
    }
}

class Library : IEnumerable<Book>
{
    string name;
    string address;
    List<Book> books;

    public Library(string name, string address, List<Book> books)
    {
        this.name = name;
        this.address = address;
        this.books = books;
    }

    public IEnumerator<Book> GetEnumerator()
    {
        foreach (var book in books)
        {
            yield return book;
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

class MainClass
{
    public static void Main()
    {
        //Создали массив книг
        Book[] booksArray = new Book[6];
        booksArray[0] = new Book("Book4", "Author4");
        booksArray[1] = new Book("Book6", "Author6");
        booksArray[2] = new Book("Book1", "Author1");
        booksArray[3] = new Book("Book3", "Author3");
        booksArray[4] = new Book("Book2", "Author2");
        booksArray[5] = new Book("Book5", "Author5");

        List<Book> booksList = new List<Book>(booksArray);
        
        //Создали обьект библиотеки
        Library library = new Library("My Library", "123 Library St", booksList);

        //Перебор всех книг
        Console.WriteLine("Books in the library:");
        foreach (var book in library)
        {
            book.Show();
        }
    }
}
