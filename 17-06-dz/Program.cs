using System;

public class Book
{
    public string Title { get; set; }
    public string Author { get; set; }
    public string Genre { get; set; }
    public int Year { get; set; }

    public Book(string title, string author, string genre, int year)
    {
        Title = title;
        Author = author;
        Genre = genre;
        Year = year;
    }

    public override string ToString()
    {
        return $"Book{{ Title='{Title}', Author='{Author}', Genre='{Genre}', Year={Year} }}";
    }
}

public class Node
{
    public Book Data { get; set; }
    public Node Next { get; set; }

    public Node(Book data)
    {
        Data = data;
        Next = null;
    }
}

public class LinkedList
{
    private Node head;

    // Добавить книгу в конец списка
    public void Add(Book book)
    {
        Node newNode = new Node(book);
        if (head == null)
        {
            head = newNode;
        }
        else
        {
            Node temp = head;
            while (temp.Next != null)
            {
                temp = temp.Next;
            }
            temp.Next = newNode;
        }
    }

    // Добавить книгу в начало списка
    public void InsertAtStart(Book book)
    {
        Node newNode = new Node(book);
        newNode.Next = head;
        head = newNode;
    }

    // Вставить книгу в n-ую позицию
    public void InsertAtPosition(Book book, int position)
    {
        Node newNode = new Node(book);
        if (position == 0)
        {
            InsertAtStart(book);
            return;
        }
        Node temp = head;
        for (int i = 0; i < position - 1 && temp != null; i++)
        {
            temp = temp.Next;
        }
        if (temp == null)
        {
            throw new IndexOutOfRangeException("Position out of range");
        }
        newNode.Next = temp.Next;
        temp.Next = newNode;
    }

    // Удаление книги с начала
    public void DeleteFromStart()
    {
        if (head != null)
        {
            head = head.Next;
        }
    }

    // Удаление книги с конца
    public void DeleteFromEnd()
    {
        if (head == null || head.Next == null)
        {
            head = null;
            return;
        }
        Node temp = head;
        while (temp.Next.Next != null)
        {
            temp = temp.Next;
        }
        temp.Next = null;
    }

    // Удаление книги с n-ой позиции
    public void DeleteFromPosition(int position)
    {
        if (position == 0)
        {
            DeleteFromStart();
            return;
        }
        Node temp = head;
        for (int i = 0; i < position - 1 && temp != null; i++)
        {
            temp = temp.Next;
        }
        if (temp == null || temp.Next == null)
        {
            throw new IndexOutOfRangeException("Position out of range");
        }
        temp.Next = temp.Next.Next;
    }

    // Поиск за параметрами
    public Node Search(string title, string author, string genre, int year)
    {
        Node temp = head;
        while (temp != null)
        {
            Book book = temp.Data;
            if ((title == null || book.Title == title) &&
                (author == null || book.Author == author) &&
                (genre == null || book.Genre == genre) &&
                (year == -1 || book.Year == year))
            {
                return temp;
            }
            temp = temp.Next;
        }
        return null;
    }

    // Изменить инфу про книгу
    public void UpdateBook(Node node, string newTitle, string newAuthor, string newGenre, int newYear)
    {
        if (node != null)
        {
            if (newTitle != null) node.Data.Title = newTitle;
            if (newAuthor != null) node.Data.Author = newAuthor;
            if (newGenre != null) node.Data.Genre = newGenre;
            if (newYear != -1) node.Data.Year = newYear;
        }
    }

    // Вывод списка книг
    public void PrintList()
    {
        Node temp = head;
        while (temp != null)
        {
            Console.WriteLine(temp.Data);
            temp = temp.Next;
        }
    }
}

public class BookManagementApp
{
    public static void Main(string[] args)
    {
        LinkedList bookList = new LinkedList();

        // Создаем книги
        bookList.Add(new Book("Book1", "Author1", "Genre1", 2001));
        bookList.Add(new Book("Book2", "Author2", "Genre2", 2002));

        // Вывод книг
        Console.WriteLine("Books in the list:");
        bookList.PrintList();

        // Демонстрация. Вставка книги в начало
        bookList.InsertAtStart(new Book("Book0", "Author0", "Genre0", 2000));
        Console.WriteLine("\nПосле вставки в начало:");
        bookList.PrintList();

        // Демонстрация. Вставка книги на n-ую позицию                            //Позиция
        bookList.InsertAtPosition(new Book("Book1.5", "Author1.5", "Genre1.5", 2001), 2);
        Console.WriteLine("\nПосле вставки в позицию 2:");
        bookList.PrintList();

        // Демонстрация. Удалить книгу с n-ой позиции
        bookList.DeleteFromPosition(1);
        Console.WriteLine("\nПосле удаления с позиции 1:");
        bookList.PrintList();

        // Демонстрация. Поиск книги
        Node foundNode = bookList.Search("Book1.5", null, null, -1);
        Console.WriteLine("\nРезультат поиска:");
        if (foundNode != null)
        {
            Console.WriteLine(foundNode.Data);
        }
        else
        {
            Console.WriteLine("Книга не найдена.");
        }

        // Демонстрация. Изменить инфу про книгу
        if (foundNode != null)
        {
            bookList.UpdateBook(foundNode, "Обновленная Book1.5", null, null, 2020);
        }
        Console.WriteLine("\nПосле обновления информации:");
        bookList.PrintList();

        // Демонстрация. Удаление с начала
        bookList.DeleteFromStart();
        Console.WriteLine("\nПосле удаления с начала:");
        bookList.PrintList();

        // Демонстрация. Удаление с конца
        bookList.DeleteFromEnd();
        Console.WriteLine("\nПосле удаления с конца:");
        bookList.PrintList();
    }
}