#include <iostream>
#include <string>

using namespace std;

// ������� ���� Pet
class Pet {
protected:
    string name;
public:
    Pet(const string& petName) : name(petName) {}
    virtual void Sound() const = 0;  // ³�������� ������� ��� ����� �������
    virtual void Show() const = 0;   // ³�������� ������� ��� ������ ���� �������
    virtual void Type() const = 0;   // ³�������� ������� ��� ������ ������ �������
    virtual ~Pet() {}                // ³��������� ����������
};

// ���� Dog, ���� ��������� Pet
class Dog : public Pet {
public:
    Dog(const string& petName) : Pet(petName) {}

    void Sound() const override {
        cout << "Dog " << name << " says: Woof!" << endl;
    }

    void Show() const override {
        cout << "Pet name: " << name << endl;
    }

    void Type() const override {
        cout << "Type: Dog" << endl;
    }
};

// ���� Cat, ���� ��������� Pet
class Cat : public Pet {
public:
    Cat(const string& petName) : Pet(petName) {}

    void Sound() const override {
        cout << "Cat " << name << " says: Meow!" << endl;
    }

    void Show() const override {
        cout << "Pet name: " << name << endl;
    }

    void Type() const override {
        cout << "Type: Cat" << endl;
    }
};

// ���� Parrot, ���� ��������� Pet
class Parrot : public Pet {
public:
    Parrot(const string& petName) : Pet(petName) {}

    void Sound() const override {
        cout << "Parrot " << name << " says: Squawk!" << endl;
    }

    void Show() const override {
        cout << "Pet name: " << name << endl;
    }

    void Type() const override {
        cout << "Type: Parrot" << endl;
    }
};

// ���� Hamster, ���� ��������� Pet
class Hamster : public Pet {
public:
    Hamster(const string& petName) : Pet(petName) {}

    void Sound() const override {
        cout << "Hamster " << name << " says: Squeak!" << endl;
    }

    void Show() const override {
        cout << "Pet name: " << name << endl;
    }

    void Type() const override {
        cout << "Type: Hamster" << endl;
    }
};

int main() {
    Pet* dog = new Dog("Bim");
    Pet* cat = new Cat("Murka");
    Pet* parrot = new Parrot("Kesha");
    Pet* hamster = new Hamster("Lari");

    dog->Show();
    dog->Type();
    dog->Sound();
    cout << endl;

    cat->Show();
    cat->Type();
    cat->Sound();
    cout << endl;

    parrot->Show();
    parrot->Type();
    parrot->Sound();
    cout << endl;

    hamster->Show();
    hamster->Type();
    hamster->Sound();

    //������� ���������
    delete dog;
    delete cat;
    delete parrot;
    delete hamster;

    return 0;
}
