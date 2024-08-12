using System;

namespace Point3DExample
{
    public record Point3D(double X, double Y, double Z);

    public static class Point3DExtensions
    {

        public static double DistanceTo(this Point3D point1, Point3D point2)
        {
            double deltaX = point1.X - point2.X;
            double deltaY = point1.Y - point2.Y;
            double deltaZ = point1.Z - point2.Z;

            return Math.Sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Массив точек
            Point3D[] points = new Point3D[]
            {
                new Point3D(0, 0, 0),
                new Point3D(1, 2, 2),
                new Point3D(3, 5, 1),
                new Point3D(-1, -3, 4),
                new Point3D(2, 2, 2)
            };

            double maxDistance = 0;
            Point3D point1WithMaxDistance = null;
            Point3D point2WithMaxDistance = null;

            // Поиск точек с макс. расстоянием
            for (int i = 0; i < points.Length; i++)
            {
                for (int j = i + 1; j < points.Length; j++)
                {
                    double distance = points[i].DistanceTo(points[j]);
                    if (distance > maxDistance)
                    {
                        maxDistance = distance;
                        point1WithMaxDistance = points[i];
                        point2WithMaxDistance = points[j];
                    }
                }
            }

            Console.WriteLine($"Maximum distance: {maxDistance}");
            Console.WriteLine($"Between points:");
            Console.WriteLine($"Point 1: ({point1WithMaxDistance.X}, {point1WithMaxDistance.Y}, {point1WithMaxDistance.Z})");
            Console.WriteLine($"Point 2: ({point2WithMaxDistance.X}, {point2WithMaxDistance.Y}, {point2WithMaxDistance.Z})");
        }
    }
}