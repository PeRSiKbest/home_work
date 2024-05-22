#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
    virtual ~Shape() {}
};

// �������
class Square : public Shape {
private:
    int x, y; // �.�. ���
    int side; // �������
public:
    Square(int _x, int _y, int _side) : x(_x), y(_y), side(_side) {}

    void Show() const override {
        cout << "�������: ˳��� ������ ��� (" << x << ", " << y << "), ������� �������: " << side << endl;
    }

    void Save(ofstream& file) const override {
        file << "Square " << x << " " << y << " " << side << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> side;
    }
};

// �����������
class Rectangle : public Shape {
private:
    int x, y; // �.�. ���
    int width, height; // ������ � ������
public:
    Rectangle(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height) {}

    void Show() const override {
        cout << "�����������: ˳��� ������ ��� (" << x << ", " << y << "), ������: " << width << ", ������: " << height << endl;
    }

    void Save(ofstream& file) const override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

//����
class Circle : public Shape {
private:
    int x, y; // �����
    int radius; // �����
public:
    Circle(int _x, int _y, int _radius) : x(_x), y(_y), radius(_radius) {}

    void Show() const override {
        cout << "����: ����� (" << x << ", " << y << "), �����: " << radius << endl;
    }

    void Save(ofstream& file) const override {
        file << "Circle " << x << " " << y << " " << radius << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> radius;
    }
};

//����
class Ellipse : public Shape {
private:
    int x, y; // ���������� ��������� ����� ���� ������������
    int width, height; // ������ � ������ ������������
public:
    Ellipse(int _x, int _y, int _width, int _height)
        : x(_x), y(_y), width(_width), height(_height) {}

    void Show() const override {
        cout << "����: ������ ���� ��� (" << x << ", " << y << "), ������ ������������: "
            << width << ", ������ ������������: " << height << endl;
    }

    void Save(ofstream& file) const override {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};


void SaveShapes(const vector<Shape*>& shapes, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "������� �������� ����� ��� ������." << endl;
        return;
    }

    for (const auto& shape : shapes) {
        shape->Save(file);
    }

    file.close();
}

void LoadShapes(vector<Shape*>& shapes, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������� �������� ����� ��� �������." << endl;
        return;
    }

    string type;
    while (file >> type) {
        Shape* shape = nullptr;
        if (type == "Square") {
            int x, y, side;
            file >> x >> y >> side;
            shape = new Square(x, y, side);
        }
        else if (type == "Rectangle") {
            int x, y, width, height;
            file >> x >> y >> width >> height;
            shape = new Rectangle(x, y, width, height);
        }
        else if (type == "Circle") {
            int x, y, radius;
            file >> x >> y >> radius;
            shape = new Circle(x, y, radius);
        }
        else if (type == "Ellipse") {
            int x, y, majorAxis, minorAxis;
            file >> x >> y >> majorAxis >> minorAxis;
            shape = new Ellipse(x, y, majorAxis, minorAxis);
        }

        if (shape != nullptr) {
            shapes.push_back(shape);
        }
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "");

    vector<Shape*> shapes;


    //=====================
    // ��������� �����
    shapes.push_back(new Square(0, 0, 5));
    shapes.push_back(new Rectangle(2, 3, 6, 4));
    shapes.push_back(new Circle(10, 10, 3));
    shapes.push_back(new Ellipse(-5, -5, 8, 4));

    // ���������� � ����
    SaveShapes(shapes, "shapes.txt");

    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();
    //======================



    // ������������ � �����
    LoadShapes(shapes, "shapes.txt");

    // ��������� ���� ��� ������
    for (const auto& shape : shapes) {
        shape->Show();
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}