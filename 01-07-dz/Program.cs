using System;
using System.IO;
using System.Xml.Serialization;

namespace MagazineApp
{
    [Serializable]
    public class Magazine
    {
        public string Title { get; set; }
        public string Publisher { get; set; }
        public DateTime PublicationDate { get; set; }
        public int NumberOfPages { get; set; }

        public Magazine() { }

        public Magazine(string title, string publisher, DateTime publicationDate, int numberOfPages)
        {
            Title = title;
            Publisher = publisher;
            PublicationDate = publicationDate;
            NumberOfPages = numberOfPages;
        }

        public override string ToString()
        {
            return $"Название: {Title}\nАвтор: {Publisher}\nДата публикации: {PublicationDate.ToShortDateString()}\nК-во страниц: {NumberOfPages}";
        }
    }

    public static class MagazineSerializer
    {
        public static void SerializeToFile(Magazine magazine, string filePath)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(Magazine));
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                serializer.Serialize(writer, magazine);
            }
        }

        public static Magazine DeserializeFromFile(string filePath)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(Magazine));
            using (StreamReader reader = new StreamReader(filePath))
            {
                return (Magazine)serializer.Deserialize(reader);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите информацию про журнал:");

            Console.Write("Название: ");
            string title = Console.ReadLine();

            Console.Write("Издатель: ");
            string publisher = Console.ReadLine();

            Console.Write("Дата публикации (yyyy-mm-dd): ");
            DateTime publicationDate = DateTime.Parse(Console.ReadLine());

            Console.Write("К-во страниц: ");
            int numberOfPages = int.Parse(Console.ReadLine());

            Magazine magazine = new Magazine(title, publisher, publicationDate, numberOfPages);

            Console.WriteLine("\nИнформация о журнале:");
            Console.WriteLine(magazine);

            string filePath = "magazine.xml";

            // Сериаризация в файл
            MagazineSerializer.SerializeToFile(magazine, filePath);
            Console.WriteLine($"\nИнфа о журнале сериализована в {filePath}");

            // Десеаризация из файла
            Magazine deserializedMagazine = MagazineSerializer.DeserializeFromFile(filePath);
            Console.WriteLine("\nДесеаризация инфы о магазине:");
            Console.WriteLine(deserializedMagazine);
        }
    }
}