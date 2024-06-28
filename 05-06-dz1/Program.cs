using System;

public class Money
{
    private int fullPart; // Целая часть
    private int miniPart; // Копейки

    public Money(int fullPart, int miniPart)
    {
        this.fullPart = fullPart;
        this.miniPart = miniPart;
        Normalize();
    }

    // Отображение
    public void Display()
    {
        Console.WriteLine($"{fullPart}.{miniPart}");
    }

    // Установить значения
    public void SetValues(int fullPart, int miniPart)
    {
        this.fullPart = fullPart;
        this.miniPart = miniPart;
        Normalize();
    }

    // Превращение копеек в валюту и наоборот
    private void Normalize()
    {
        if (miniPart >= 100)
        {
            fullPart +=miniPart / 100;
            miniPart = miniPart % 100;
        }
        else if (miniPart < 0)
        {
            fullPart -= 1 + miniPart / 100;
            miniPart = 100 - miniPart % 100;
        }
    }

    // Уменьшение цены 
    public void Decrease(int fullPart, int miniPart)
    {
        int totalMiniPart = this.miniPart + this.fullPart * 100;
        int decreaseMiniPart = miniPart + fullPart * 100;
        totalMiniPart -= decreaseMiniPart;

        this.fullPart = totalMiniPart / 100;
        this.miniPart = totalMiniPart % 100;
        Normalize();
    }
}

public class Product
{
    private string name;
    private Money price;

    public Product(string name, Money price)
    {
        this.name = name;
        this.price = price;
    }

    // Уменьшение цены на число
    public void DecreasePrice(int fullPart, int miniPart)
    {
        price.Decrease(fullPart, miniPart);
    }

    // Инфа про продукт
    public void Display()
    {
        Console.Write($"{name}: ");
        price.Display();
    }
}

class Program
{
    static void Main()
    {
        Money money = new Money(10, 450); // 10.450 -> 14.50 пример перевода копеек в целое
        money.Display();

        Product product = new Product("Milk", money);
        product.Display();

        product.DecreasePrice(1, 75); // Уменьшение цены на 1.75
        product.Display();
    }
}