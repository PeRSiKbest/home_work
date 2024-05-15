#include <iostream>
#include <string>

using namespace std;

class Overcoat {
private:
    string type;
    double price;

public:
    Overcoat(const string& t, double p) : type(t), price(p) {}

    // перегрузка ==
    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    // перегрузка =
    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    // перегрузка >
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

    // перегрузка ==
    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    // перегрузка =
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            address = other.address;
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    // перегрузка >
    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Overcoat coat1("пальто", 100);
    Overcoat coat2("куртка", 80);

    // Проверка на равенство
    if (coat1 == coat2) {
        cout << "Типы одежды равны\n";
    }
    else {
        cout << "Типы одежды не равны\n";
    }

    // Сравнение за ценой
    if (coat1.getPrice() > coat2.getPrice()) {
        cout << "Цена первого пальто выше цены второго\n";
    }
    else {
        cout << "Цена первого пальто не выше цены второго\n";
    }

    // Присваивание
    Overcoat coat3("пальто", 120);
    cout << "До присваивания: цена первого пальто - " << coat1.getPrice() << ", цена третьего пальто - " << coat3.getPrice() << "\n";
    coat3 = coat1;
    cout << "После присваивания: цена первого пальто - " << coat1.getPrice() << ", цена третьего пальто - " << coat3.getPrice() << "\n";

    //==================================================
    cout << endl;
    Flat flat1("вул. Пушкіна, 10", 80, 100000);
    Flat flat2("вул. Лермонтова, 20", 90, 120000);

    // Проверка на равенство
    if (flat1 == flat2) {
        cout << "Площи квартир равны\n";
    }
    else {
        cout << "Площи квартир не равны\n";
    }

    // Проверка по цене
    if (flat1.getPrice() > flat2.getPrice()) {
        cout << "Цена первой квартиры выше цены второй\n";
    }
    else {
        cout << "Цена первой квартиры не выше цены второй\n";
    }

    // Присваивание
    Flat flat3("вул. Гоголя, 5", 85, 110000);
    cout << "До присваивания: цена первой квартиры - " << flat1.getPrice() << ", цена третьей квартиры - " << flat3.getPrice() << "\n";
    flat3 = flat1;
    cout << "После присваивания: цена первой квартиры - " << flat1.getPrice() << ", цена третьей квартиры - " << flat3.getPrice() << "\n";

    return 0;
}