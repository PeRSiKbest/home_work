#include <iostream>
#include <cmath>
using namespace std;

class Equation {
public:
    virtual void solve() = 0;
    virtual ~Equation() {}
};

// ˳���� ��������
class LinearEquation : public Equation {
private:
    double a, b; // ax + b = 0
public:
    LinearEquation(double _a, double _b) : a(_a), b(_b) {}

    void solve() override {
        if (a == 0) {
            if (b == 0)
                cout << "г������ �� ����� ����'����.\n";
            else
                cout << "г������ �� �� ����'����.\n";
        }
        else {
            double root = -b / a;
            cout << "����� �������: " << root << endl;
        }
    }
};

// ����������� �������
class QuadraticEquation : public Equation {
private:
    double a, b, c; // ax^2 + bx + c = 0
public:
    QuadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    void solve() override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            cout << "г������ �� �� ������ ������.\n";
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "���� ������ ����� �������: " << root << endl;
        }
        else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "��� ������ ����� �������: " << root1 << " �� " << root2 << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "");

    Equation* eq1 = new LinearEquation(5, -1);
    Equation* eq2 = new QuadraticEquation(1, -4, 3);

    eq1->solve();
    eq2->solve();

    delete eq1;
    delete eq2;

    return 0;
}