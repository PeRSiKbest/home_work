#include <iostream>
#include <string>

using namespace std;

// Базовий клас Pet
class Pet {
protected:
    string name;
public:
    Pet(const string& petName) : name(petName) {}
    virtual void Sound() const = 0;  // Віртуальна функція для звуку тварини
    virtual void Show() const = 0;   // Віртуальна функція для показу імені тварини
    virtual void Type() const = 0;   // Віртуальна функція для показу підвиду тварини
    virtual ~Pet() {}                // Віртуальний деструктор
};

// Клас Dog, який успадковує Pet
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

// Клас Cat, який успадковує Pet
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

// Клас Parrot, який успадковує Pet
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

// Клас Hamster, який успадковує Pet
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

    //удаляем животинку
    delete dog;
    delete cat;
    delete parrot;
    delete hamster;

    return 0;
}
