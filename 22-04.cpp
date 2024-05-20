#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        DeleteAll();
    }

    //Додавання елемента до голови
    void AddToHead(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    //Додавання елемента до хвоста
    void AddToTail(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    //Видалення елемента з голови
    void DeleteFromHead() {
        if (!head) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //Видалення елемента з хвоста
    void DeleteFromTail() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    //Видалення всіх елементів
    void DeleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Show() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    //Вставлення елемента в задану позицію
    void InsertAtPosition(const T& data, int position) {
        if (position <= 0) {
            AddToHead(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        int currentPosition = 0;
        while (current && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        if (!current) {
            cerr << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    //Видалення елемента із заданої позиції
    void DeleteAtPosition(int position) {
        if (!head || position <= 0) {
            return;
        }
        if (position == 1) {
            DeleteFromHead();
            return;
        }
        Node* current = head;
        int currentPosition = 0;
        while (current && currentPosition < position - 2) {
            current = current->next;
            currentPosition++;
        }
        if (!current || !current->next) {
            cerr << "Position out of range." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    //Пошук
    int Find(const T& data) {
        Node* current = head;
        int position = 1;
        while (current) {
            if (current->data == data) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    //Пошук і заміна
    int Replace(const T& oldData, const T& newData) {
        int count = 0;
        Node* current = head;
        while (current) {
            if (current->data == oldData) {
                current->data = newData;
                count++;
            }
            current = current->next;
        }
        return count;
    }

    //Перевертання списку
    void Reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    List<int> list;
    list.AddToTail(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToTail(4);

    cout << "Original List: ";
    list.Show();

    list.InsertAtPosition(5, 2);
    cout << "After Insertion at position 2: ";
    list.Show();

    list.DeleteAtPosition(4);
    cout << "After Deletion at position 4: ";
    list.Show();

    cout << "Position of element 3: " << list.Find(3) << endl;

    list.Replace(5, 6);
    cout << "After Replacing 5 with 6: ";
    list.Show();

    cout << "Reversed List: ";
    list.Reverse();
    list.Show();

    return 0;
}