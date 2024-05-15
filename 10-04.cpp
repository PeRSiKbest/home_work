#include <iostream>
#include <string>

using namespace std;

class Overcoat {
private:
    string type;
    double price;

public:
    Overcoat(const string& t, double p) : type(t), price(p) {}

    // ���������� ==
    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    // ���������� =
    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    // ���������� >
    bool operator>(const Overcoat& other) const {
        return price > other.price;
    }

    double getPrice() const {
        return price;
    }
};

//======================================

class Flat {
private:
    string address;
    double area;
    double price;

public:
    Flat(const string& a, double ar, double pr) : address(a), area(ar), price(pr) {}

    // ���������� ==
    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    // ���������� =
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            address = other.address;
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    // ���������� >
    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Overcoat coat1("������", 100);
    Overcoat coat2("������", 80);

    // �������� �� ���������
    if (coat1 == coat2) {
        cout << "���� ������ �����\n";
    }
    else {
        cout << "���� ������ �� �����\n";
    }

    // ��������� �� �����
    if (coat1.getPrice() > coat2.getPrice()) {
        cout << "���� ������� ������ ���� ���� �������\n";
    }
    else {
        cout << "���� ������� ������ �� ���� ���� �������\n";
    }

    // ������������
    Overcoat coat3("������", 120);
    cout << "�� ������������: ���� ������� ������ - " << coat1.getPrice() << ", ���� �������� ������ - " << coat3.getPrice() << "\n";
    coat3 = coat1;
    cout << "����� ������������: ���� ������� ������ - " << coat1.getPrice() << ", ���� �������� ������ - " << coat3.getPrice() << "\n";

    //==================================================
    cout << endl;
    Flat flat1("���. ������, 10", 80, 100000);
    Flat flat2("���. ����������, 20", 90, 120000);

    // �������� �� ���������
    if (flat1 == flat2) {
        cout << "����� ������� �����\n";
    }
    else {
        cout << "����� ������� �� �����\n";
    }

    // �������� �� ����
    if (flat1.getPrice() > flat2.getPrice()) {
        cout << "���� ������ �������� ���� ���� ������\n";
    }
    else {
        cout << "���� ������ �������� �� ���� ���� ������\n";
    }

    // ������������
    Flat flat3("���. ������, 5", 85, 110000);
    cout << "�� ������������: ���� ������ �������� - " << flat1.getPrice() << ", ���� ������� �������� - " << flat3.getPrice() << "\n";
    flat3 = flat1;
    cout << "����� ������������: ���� ������ �������� - " << flat1.getPrice() << ", ���� ������� �������� - " << flat3.getPrice() << "\n";

    return 0;
}