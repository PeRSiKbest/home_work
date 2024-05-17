#include <iostream>
using namespace std;

class Employer {
public:
    virtual void Print() const = 0;
    virtual ~Employer() {}
};

// Похідний клас President
class President : public Employer {
public:
    void Print() const override {
        cout << "I am the President." << endl;
    }
};

class Manager : public Employer {
public:
    void Print() const override {
        cout << "I am a Manager." << endl;
    }
};

class Worker : public Employer {
public:
    void Print() const override {
        cout << "I am a Worker.\n" << endl;
    }
};

//==================================

class Shape {
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

// Прямокутник
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double Area() const override {
        return width * height;
    }
};

// Коло
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

// Прямокутний трикутник
class RightTriangle : public Shape {
    double base, height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}
    double Area() const override {
        return 0.5 * base * height;
    }
};

// Трапеція
class Trapezoid : public Shape {
    double base1, base2, height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}
    double Area() const override {
        return 0.5 * (base1 + base2) * height;
    }
};

int main() {
    Employer* president = new President();
    Employer* manager = new Manager();
    Employer* worker = new Worker();

    president->Print();
    manager->Print();
    worker->Print();

    delete president;
    delete manager;
    delete worker;

    Shape* shapes[4];
    shapes[0] = new Rectangle(10.0, 5.0);
    shapes[1] = new Circle(7.0);
    shapes[2] = new RightTriangle(8.0, 12.0);
    shapes[3] = new Trapezoid(4.0, 6.0, 5.0);

    for (int i = 0; i < 4; ++i) {
        cout << "Area of shape " << i + 1 << " is " << shapes[i]->Area() << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }

    return 0;
}