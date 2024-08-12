using System;
using System.Linq;

public class Device
{
    public string Name { get; set; }
    public string Manufacturer { get; set; }
    public decimal Price { get; set; }

    public override string ToString()
    {
        return $"{Name} ({Manufacturer}) - ${Price}";
    }
}
