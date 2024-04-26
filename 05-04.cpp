#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    static int count; //Кількість створених об'єктів
    char* str;
    int length;

public:
    // Конструктор за замовчуванням
    MyString() {
        length = 80;
        str = new char[length + 1];
        count++;
    }

    // Створення рядка заданої довжини
    MyString(int len) {
        length = len;
        str = new char[length + 1];
        count++;
    }

    // ініціалізації рядка, отриманого від користувача
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = s[i];
        }
        str[length] = '\0';
        count++;
    }

    ~MyString() {
        delete[] str;
        count--;
    }

    // Ввведення рядка
    void input() {
        cout << "Enter a string: ";
        cin.getline(str, length + 1);
    }

    // Виведення рядка
    void output() {
        cout << "String: " << str << endl;
    }

    // Копіювання рядка
    void MyStrcpy(MyString& obj) {
        for (int i = 0; i < obj.length; ++i) {
            str[i] = obj.str[i];
        }
        str[obj.length] = '\0';
    }

    // Пошук підрядка в рядку
    bool MyStrStr(const char* subStr) {
        int len = strlen(subStr);
        for (int i = 0; i <= length - len; ++i) {
            bool found = true;
            for (int j = 0; j < len; ++j) {
                if (str[i + j] != subStr[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
        return false;
    }

    // Пошук символу в рядку. Повертає індекс, АБО -1, якщо символ не знайдено
    int MyChr(char c) {
        for (int i = 0; i < length; ++i) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    // Довжина рядка
    int MyStrLen() {
        return length;
    }

    // Об'єднання рядків
    void MyStrCat(MyString& b) {
        int lenA = strlen(str);
        int lenB = strlen(b.str);
        char* temp = new char[lenA + lenB + 1];
        int index = 0;
        for (int i = 0; i < lenA; ++i) {
            temp[index++] = str[i];
        }
        for (int i = 0; i < lenB; ++i) {
            temp[index++] = b.str[i];
        }
        temp[index] = '\0';
        delete[] str;
        str = temp;
        length = lenA + lenB;
    }

    // Видалення символу з рядка
    void MyDelChr(char c) {
        int index = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c) {
                str[index++] = str[i];
            }
        }
        str[index] = '\0';
        length = index;
    }

    // Порівняння рядків
    int MyStrCmp(MyString& b) {
        for (int i = 0; i < length && i < b.length; ++i) {
            if (str[i] < b.str[i]) {
                return -1;
            }
            else if (str[i] > b.str[i]) {
                return 1;
            }
        }
        if (length < b.length) {
            return -1;
        }
        else if (length > b.length) {
            return 1;
        }
        return 0;
    }

    // Кількість створених об'єктів
    static int getCount() {
        return count;
    }
};

int MyString::count = 0;

int main() {
    //Zd1-Zd10 написав для кращого поділу в консолі
    cout << "\nZd1";
    cout << "\nDefault constructor:" << endl;
    MyString s1;
    s1.input();
    s1.output();

    cout << "\nZd2";
    cout << "\nConstructor with parameter for specified length:" << endl;
    MyString s2(100);
    s2.input();
    s2.output();

    cout << "\nZd3";
    cout << "\nConstructor with parameter for string initialization:" << endl;
    MyString s3("Hello");
    s3.output();

    cout << "\nZd4";
    cout << "\nCopying string:" << endl;
    MyString s4;
    s4.MyStrcpy(s3);
    s4.output();

    cout << "\nZd5";
    cout << "\nSearch for substring:" << endl;
    cout << "Is 'llo' substring of\n";
    s3.output();
    cout << "?\n" << (s3.MyStrStr("llo") ? "Yes" : "No") << endl;

    cout << "\nZd6";
    cout << "\nSearch for character:" << endl;
    cout << "Index of 'e' in ";
    s3.output();
    cout << "is " << s3.MyChr('e') << endl;

    cout << "\nZd7";
    cout << "\nGetting string length:\n";
    cout << "Length of ";
    s3.output();
    cout << s3.MyStrLen() << endl;

    cout << "\nZd8";
    cout << "\nConcatenation of strings:" << endl;
    MyString s5(" World");
    s3.MyStrCat(s5);
    cout << "Concatenated string: ";
    s3.output();

    cout << "\nZd9";
    cout << "\nDeleting character from string:" << endl;
    char delChar = 'o';
    cout << "Deleting character '" << delChar << "' from string: \n";
    s3.output();
    s3.MyDelChr(delChar);
    s3.output();

    cout << "\nZd10";
    cout << "\nString comparison:" << endl;
    MyString s6("Hello");
    cout << "Comparison result between ";
    s3.output();
    cout << "and";
    s6.output();
    cout << ": " << s3.MyStrCmp(s6) << endl;

    cout << "\nZd11";
    cout << "\nNumber of created objects: " << MyString::getCount() << endl;

    return 0;
}
