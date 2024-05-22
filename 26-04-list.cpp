#include <iostream>
#include <vector>
using namespace std;

class List {
public:
    virtual void insert(int value) = 0;  // вставка
    virtual int remove() = 0;            // удаление
    virtual void display() const = 0;    // отображение
    virtual ~List() {}
};

// Стек
class Stack : public List {
private:
    vector<int> elements;
public:
    void insert(int value) override {
        elements.push_back(value);
    }

    int remove() override {
        if (elements.empty()) {
            throw out_of_range("Stack is empty");
        }
        int value = elements.back();
        elements.pop_back();
        return value;
    }

    void display() const override {
        for (int elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

// Очередь
class Queue : public List {
private:
    vector<int> elements;
public:
    void insert(int value) override {
        elements.push_back(value);
    }

    int remove() override {
        if (elements.empty()) {
            throw out_of_range("Queue is empty");
        }
        int value = elements.front();
        elements.erase(elements.begin());
        return value;
    }

    void display() const override {
        for (int elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    List* stack = new Stack();
    List* queue = new Queue();

    // Тест стека
    stack->insert(1);
    stack->insert(2);
    stack->insert(3);
    cout << "Stack: ";
    stack->display();
    cout << "Removed from stack: " << stack->remove() << endl;
    cout << "Stack after removal: ";
    stack->display();

    // Тест очереди
    queue->insert(1);
    queue->insert(2);
    queue->insert(3);
    cout << "Queue: ";
    queue->display();
    cout << "Removed from queue: " << queue->remove() << endl;
    cout << "Queue after removal: ";
    queue->display();

    delete stack;
    delete queue;

    return 0;
}