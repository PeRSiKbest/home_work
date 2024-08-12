using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Text.Json;
using System.Threading.Tasks;

namespace IPInfoFetcher
{
    public class IPInfo
    {
        public string Ip { get; set; }
        public string City { get; set; }
        public DateTime Date { get; set; }
    }

    class Program
    {
        static async Task Main(string[] args)
        {
            var ipAddresses = new List<string>();

            Console.WriteLine("Введіть IP адреси (введіть 'exit' щоб завершити):");
            while (true)
            {
                var input = Console.ReadLine();
                if (input.ToLower() == "exit") break;
                ipAddresses.Add(input);
                Console.WriteLine($"Додано IP: {input}"); // Перевірка введених IP
            }

            var ipInfoList = new List<IPInfo>();

            using (HttpClient client = new HttpClient())
            {
                foreach (var ip in ipAddresses)
                {
                    try
                    {
                        var response = await client.GetStringAsync($"https://ipwhois.app/json/{ip}");
                        var jsonDoc = JsonDocument.Parse(response);

                        if (jsonDoc.RootElement.TryGetProperty("city", out JsonElement cityElement))
                        {
                            var city = cityElement.GetString();
                            var ipInfo = new IPInfo
                            {
                                Ip = ip,
                                City = city,
                                Date = DateTime.Now
                            };

                            ipInfoList.Add(ipInfo);
                            Console.WriteLine($"IP: {ip}, City: {city}");
                        }
                        else
                        {
                            Console.WriteLine($"Не вдалося отримати інформацію про місто для IP: {ip}");
                        }
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Помилка під час обробки IP {ip}: {ex.Message}");
                    }
                }
            }

            var jsonString = JsonSerializer.Serialize(ipInfoList, new JsonSerializerOptions { WriteIndented = true });
            await File.WriteAllTextAsync("ip_date.json", jsonString);

            Console.WriteLine("Результати збережено у файл ip_date.json");
        }
    }
}
