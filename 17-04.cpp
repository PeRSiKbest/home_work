#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int maxSize;
    int top;
    char* stackArray;

    // Збільшення розміру масиву
    void resize(int newSize) {
        char* newArray = new char[newSize];
        for (int i = 0; i <= top; ++i) {
            newArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = newArray;
        maxSize = newSize;
    }

public:
    Stack(int size) : maxSize(size), top(-1) {
        stackArray = new char[maxSize];
    }

    ~Stack() {
        delete[] stackArray;
    }

    // Внесення символу
    void push(char ch) {
        if (isFull()) {
            resize(maxSize * 2);
        }
        stackArray[++top] = ch;
    }

    // Видалення символу
    char pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return stackArray[top--];
    }

    // Підрахунок кількості символів
    int size() const {
        return top + 1;
    }

    // Чи стек порожній
    bool isEmpty() const {
        return top == -1;
    }

    // Чи стек повний
    bool isFull() const {
        return top == maxSize - 1;
    }

    // Очищення стеку
    void clear() {
        top = -1;
    }

    // Отримання без видалення верхнього символу в стеці
    char peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return stackArray[top];
    }
};

int main() {
    try {
        Stack stack(2);

        stack.push('A');
        stack.push('B');
        stack.push('C');

        cout << "Top element: " << stack.peek() << endl;
        cout << "Number of elements: " << stack.size() << endl;

        cout << "Popped element: " << stack.pop() << endl;
        cout << "Top element: " << stack.peek() << endl;

        stack.clear();
        cout << "Stack cleared. Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}