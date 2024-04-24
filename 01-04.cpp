#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   // ���������
    int denominator; // ���������

public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    // ����������� � �����������
    Fraction(int num, int denom) {
        numerator = num;
        if (denom != 0)
            denominator = denom;
        else {
            cout << "Error: The denominator cannot be zero. The value is set to 1." << endl;
            denominator = 1;
        }
    }

    // ��������� �����
    void print() const {
        cout << numerator << "/" << denominator;
    }

    // ��������� �����
    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // ³������� �����
    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // �������� �����
    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // ĳ����� �����
    Fraction divide(const Fraction& other) const {
        if (other.numerator != 0) {
            int num = numerator * other.denominator;
            int denom = denominator * other.numerator;
            return Fraction(num, denom);
        }
        else {
            cout << "Error: Division by zero." << endl;
            return Fraction();
        }
    }
};

int main() {
    int num1, denom1, num2, denom2;

    // �������� ������� �����
    cout << "Enter the numerator of the first fraction: ";
    cin >> num1;
    cout << "Enter the denominator of the first fraction: ";
    cin >> denom1;

    // �������� ������� �����
    cout << "Enter the numerator of the second fraction: ";
    cin >> num2;
    cout << "Enter the denominator of the second fraction: ";
    cin >> denom2;

    // ��������� ��'���� ����� � ��������� ����������
    Fraction frac1(num1, denom1);
    Fraction frac2(num2, denom2);

    cout << endl;
    frac1.print();
    cout << endl;
    frac2.print();
    cout << endl << endl;

    // ���������
    Fraction resultAdd = frac1.add(frac2);
    cout << "Sum: ";
    resultAdd.print();
    cout << endl;

    // ³�������
    Fraction resultSub = frac1.subtract(frac2);
    cout << "Difference: ";
    resultSub.print();
    cout << endl;

    // ��������
    Fraction resultMul = frac1.multiply(frac2);
    cout << "Product: ";
    resultMul.print();
    cout << endl;

    // ĳ�����
    Fraction resultDiv = frac1.divide(frac2);
    cout << "Quotient: ";
    resultDiv.print();
    cout << endl;

    return 0;
}
