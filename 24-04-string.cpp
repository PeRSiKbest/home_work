#include <iostream>
#include <cstring>
using namespace std;

class String {
protected:
    char* str;
    size_t length;

public:
    // Конструктор без параметров
    String() : str(nullptr), length(0) {}

    // Конструктор, что принимает C-рядок
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    // Оператор присваивания
    String& operator=(const String& other) {
        if (this == &other) return *this;
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
        return *this;
    }

    // Длина рядка
    size_t getLength() const {
        return length;
    }

    // Очистка рядка
    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    virtual ~String() {
        delete[] str;
    }

    // + і +=
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy_s(result.str, result.length + 1, str);
        strcat_s(result.str, result.length + 1, other.str);
        return result;
    }

    String& operator+=(const String& other) {
        char* newStr = new char[length + other.length + 1];
        strcpy_s(newStr, length + other.length + 1, str);
        strcat_s(newStr, length + other.length + 1, other.str);
        delete[] str;
        str = newStr;
        length += other.length;
        return *this;
    }

    // == і !=
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return strcmp(str, other.str) != 0;
    }

    void print() const {
        if (str) {
            cout << str;
        }
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) : String() {
        bool isValid = true;
        for (size_t i = 0; i < strlen(s); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            length = strlen(s);
            str = new char[length + 1];
            strcpy_s(str, length + 1, s);
        }
        else {
            clear();
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        if (this == &other) return *this;
        String::operator=(other);
        return *this;
    }

    // Переход числа в доп. код
    void negate() {
        for (size_t i = 0; i < length; ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
        // Добавляем 1 к результату
        bool carry = true;
        for (int i = length - 1; i >= 0 && carry; --i) {
            if (str[i] == '1') {
                str[i] = '0';
            }
            else {
                str[i] = '1';
                carry = false;
            }
        }
    }

    // + і +=
    BitString operator+(const BitString& other) const {
        BitString result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy_s(result.str, result.length + 1, str);
        strcat_s(result.str, result.length + 1, other.str);
        return result;
    }

    BitString& operator+=(const BitString& other) {
        char* newStr = new char[length + other.length + 1];
        strcpy_s(newStr, length + other.length + 1, str);
        strcat_s(newStr, length + other.length + 1, other.str);
        delete[] str;
        str = newStr;
        length += other.length;
        return *this;
    }

    // == і !=
    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    s1 += s2;

    s1.print();  // HelloWorld
    cout << endl;
    s3.print();  // HelloWorld
    cout << endl << endl;

    BitString b1("101010");
    BitString b2("010101");
    BitString b3 = b1 + b2;
    b1 += b2;

    b1.print();
    cout << endl;
    b3.print();
    cout << endl;

    b1.negate();
    b1.print();
    cout << endl;

    return 0;
}