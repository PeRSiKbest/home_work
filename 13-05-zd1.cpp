#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        clear();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    void addToFront(int value) {
        Node* newNode;
        try {
            newNode = new Node(value);
        }
        catch (const bad_alloc&) {
            throw runtime_error("Failed to allocate memory for new node");
        }

        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToBack(int value) {
        Node* newNode;
        try {
            newNode = new Node(value);
        }
        catch (const bad_alloc&) {
            throw runtime_error("Failed to allocate memory for new node");
        }

        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFromFront() {
        if (!head) {
            throw underflow_error("Attempted to remove from an empty list");
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void removeFromBack() {
        if (!tail) {
            throw underflow_error("Attempted to remove from an empty list");
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    int front() const {
        if (!head) {
            throw underflow_error("Attempted to access front of an empty list");
        }
        return head->data;
    }

    int back() const {
        if (!tail) {
            throw underflow_error("Attempted to access back of an empty list");
        }
        return tail->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

void menu() {

    cout << endl << "1. Add to front" << endl;
    cout << "2. Add to back" << endl;
    cout << "3. Remove from front" << endl;
    cout << "4. Remove from back" << endl;
    cout << "5. View front" << endl;
    cout << "6. View back" << endl;
    cout << "7. Check if empty" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    List list;
    int choice, value;

    while (true) {
        menu();
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter value to add to front: ";
                cin >> value;
                list.addToFront(value);
                cout << "Added to front." << endl;
                break;
            case 2:
                cout << "Enter value to add to back: ";
                cin >> value;
                list.addToBack(value);
                cout << "Added to back." << endl;
                break;
            case 3:
                list.removeFromFront();
                cout << "Removed from front." << endl;
                break;
            case 4:
                list.removeFromBack();
                cout << "Removed from back." << endl;
                break;
            case 5:
                cout << "Front value: " << list.front() << endl;
                break;
            case 6:
                cout << "Back value: " << list.back() << endl;
                break;
            case 7:
                if (list.isEmpty()) {
                    cout << "The list is empty." << endl;
                }
                else {
                    cout << "The list is not empty." << endl;
                }
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }
    }

    return 0;
}