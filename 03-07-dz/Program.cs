using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        Device[] array1 = new Device[]
        {
            new Device { Name = "Device1", Manufacturer = "ManufacturerA", Price = 100 },
            new Device { Name = "Device2", Manufacturer = "ManufacturerB", Price = 200 },
            new Device { Name = "Device3", Manufacturer = "ManufacturerC", Price = 300 }
        };

        Device[] array2 = new Device[]
        {
            new Device { Name = "Device4", Manufacturer = "ManufacturerB", Price = 150 },
            new Device { Name = "Device5", Manufacturer = "ManufacturerC", Price = 250 },
            new Device { Name = "Device6", Manufacturer = "ManufacturerD", Price = 350 }
        };

        // Разница массивов
        var difference = array1.Except(array2, new DeviceComparer()).ToArray();

        // Пересечение 
        var intersection = array1.Intersect(array2, new DeviceComparer()).ToArray();

        // Обьединение
        var union = array1.Union(array2, new DeviceComparer()).ToArray();

        // Результаты
        Console.WriteLine("Difference(уникальные):");
        foreach (var device in difference)
        {
            Console.WriteLine(device);
        }

        Console.WriteLine("\nIntersection(общие):");
        foreach (var device in intersection)
        {
            Console.WriteLine(device);
        }

        Console.WriteLine("\nUnion(все, без повторов):");
        foreach (var device in union)
        {
            Console.WriteLine(device);
        }
    }
}

public class DeviceComparer : IEqualityComparer<Device>
{
    public bool Equals(Device x, Device y)
    {
        if (x == null || y == null) return false;
        return x.Manufacturer == y.Manufacturer;
    }

    public int GetHashCode(Device obj)
    {
        return obj.Manufacturer.GetHashCode();
    }
}