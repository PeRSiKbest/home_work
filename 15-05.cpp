#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    int age;

public:
    Student() {}

    // �������� ���� ��� ��������
    void inputInfo() {
        cout << "Enter student's first name: ";
        getline(cin, firstName);
        cout << "Enter student's last name: ";
        getline(cin, lastName);
        cout << "Enter student's age: ";
        cin >> age;
        cin.ignore();
    }

    // ���������� ����� � ����
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << firstName << endl;
            file << lastName << endl;
            file << age << endl;
            file.close();
            cout << "Data successfully saved to file: " << filename << endl;
        }
        else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    // ������������ ����� � �����
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            getline(file, firstName);
            getline(file, lastName);
            file >> age;
            file.ignore();
            file.close();
            cout << "Data successfully loaded from file: " << filename << endl;
        }
        else {
            cout << "Error: Unable to open file for reading." << endl;
        }
    }

    // ��������� ���� ��� ��������
    void displayInfo() {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Student student;

    // ��������
    student.inputInfo();

    // ����������
    student.saveToFile("student.txt");

    // ���������
    Student loadedStudent;

    // ������������
    loadedStudent.loadFromFile("student.txt");

    // ���������
    loadedStudent.displayInfo();

    return 0;
}