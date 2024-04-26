#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    static int count;
    char* str;
    int length;

public:
    // ����������� �� �������������
    String(int len = 80) {
        length = len;
        str = new char[length + 1];
        count++;
    }

    // ����������� � ���������� ��� ����������� �����
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

    // �������� �����
    void input() {
        cout << "Enter a string: ";
        cin.getline(str, length + 1);
    }

    // ��������� �����
    void output() {
        cout << "String: " << str << endl;
    }
};

int String::count = 0;

int main() {

    cout << "1. Default" << endl;
    String s1; // ����������� �� �������������
    s1.input();
    s1.output();
    cout << endl << "2.  Parameter" << endl;
    String s2(100); // ����������� � ����������
    s2.input();
    s2.output();
    cout << endl << "3. String" << endl;
    String s3("Hello"); // ������������ � ���������� ��� ����������� �����
    s3.output();

    cout << "Number of created objects: " << String::getCount() << endl; //

    return 0;
}
