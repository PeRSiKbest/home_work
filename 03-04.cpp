#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    static int count;
    char* str;
    int length;

public:
    // Конструктор за замовчуванням
    String(int len = 80) {
        length = len;
        str = new char[length + 1];
        count++;
    }

    // Конструктор з параметром для ініціалізації рядка
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
        count++;
    }

    ~String() {
        delete[] str;
        count--;
    }

    static int getCount() {
        return count;
    }

    // Введення рядка
    void input() {
        cout << "Enter a string: ";
        cin.getline(str, length + 1);
    }

    // Виведення рядка
    void output() {
        cout << "String: " << str << endl;
    }
};

int String::count = 0;

int main() {

    cout << "1. Default" << endl;
    String s1; // Конструктор за замовчуванням
    s1.input();
    s1.output();
    cout << endl << "2.  Parameter" << endl;
    String s2(100); // Конструктор з параметром
    s2.input();
    s2.output();
    cout << endl << "3. String" << endl;
    String s3("Hello"); // Конструктора з параметром для ініціалізації рядка
    s3.output();

    cout << "Number of created objects: " << String::getCount() << endl; //

    return 0;
}
