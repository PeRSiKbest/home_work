#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;
    int age;
    string color;

public:
    Pet(const string& name, int age, const string& color)
        : name(name), age(age), color(color) {}

    virtual void showInfo() const {
        cout << "\nName: " << name << ", Age: " << age << ", Color: " << color << endl;
    }

    virtual ~Pet() {}
};

//Собака
class Dog : public Pet {
    string breed; //Порода

public:
    Dog(const string& name, int age, const string& color, const string& breed)
        : Pet(name, age, color), breed(breed) {}

    void showInfo() const override {
        Pet::showInfo();
        cout << "Breed: " << breed << endl;
    }
};

//Кот
class Cat : public Pet {
    bool likesMice; //Любит мышей

public:
    Cat(const string& name, int age, const string& color, bool likesMice)
        : Pet(name, age, color), likesMice(likesMice) {}

    void showInfo() const override {
        Pet::showInfo();
        cout << "Likes mice: " << (likesMice ? "Yes" : "No") << endl;
    }
};

//Попу гай
class Parrot : public Pet {
    bool canTalk; //Умеет говорить

public:
    Parrot(const string& name, int age, const string& color, bool canTalk)
        : Pet(name, age, color), canTalk(canTalk) {}

    void showInfo() const override {
        Pet::showInfo();
        cout << "Can talk: " << (canTalk ? "Yes" : "No") << endl;
    }
};

int main() {
    Dog Dog("Bim", 12, "Black", "Taksa");
    Cat Cat("Murka", 6, "White", true);
    Parrot Parrot("Kesha", 2, "Green", true);

    Dog.showInfo();
    Cat.showInfo();
    Parrot.showInfo();

    return 0;
}
