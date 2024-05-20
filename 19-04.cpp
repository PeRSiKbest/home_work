//
//����� ��������
//
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    int front, rear, size;
    T* queue;
    int capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        queue = new T[capacity];
        front = size = 0;
        rear = capacity - 1;
    }

    ~Queue() {
        delete[] queue;
    }

    // �� ����� �������
    bool IsEmpty() {
        return (size == 0);
    }

    // �� ����� ���������
    bool IsFull() {
        return (size == capacity);
    }

    // ��������� ��������
    void Enqueue(T item) {
        if (IsFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
        cout << item << " enqueued to queue\n";
    }

    // ��������� ��������
    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        T item = queue[front];
        front = (front + 1) % capacity;
        size--;
        cout << item << " dequeued from queue\n";
    }

    // ³���������� ��� ��������
    void Show() {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements are: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q(5);

    // ������ ��������
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Show();

    // ��������� ��� ��������
    q.Dequeue();
    q.Dequeue();

    q.Show();

    // ������ ��� ��������
    q.Enqueue(60);
    q.Enqueue(70);

    q.Show();

    return 0;
}


//
//����� �������� (������������ �� �� ������)
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct Element {
        T value;
        int priority;

        bool operator>(const Element& other) const {
            return priority < other.priority;
        }
    };

    vector<Element> queue;
    int capacity;

public:
    PriorityQueue(int capacity) {
        this->capacity = capacity;
    }

    // �� ����� �������
    bool IsEmpty() const {
        return queue.empty();
    }

    // �� ����� ���������
    bool IsFull() const {
        return queue.size() == capacity;
    }

    // ��������� �������� � ����������
    void InsertWithPriority(T value, int priority) {
        if (IsFull()) {
            cout << "Priority queue is full\n";
            return;
        }
        Element element = { value, priority };
        queue.push_back(element);

        sort(queue.begin(), queue.end(), greater<Element>());
        cout << value << " inserted with priority " << priority << "\n";
    }

    // ��������� �������� � �������� ����������
    void PullHighestPriorityElement() {
        if (IsEmpty()) {
            cout << "Priority queue is empty\n";
            return;
        }
        Element highestPriorityElement = queue.front();
        queue.erase(queue.begin());
        cout << highestPriorityElement.value << " with highest priority " << highestPriorityElement.priority << " pulled from queue\n";
    }

    // ���������� �������� � �������� ����������
    T Peek() const {
        if (IsEmpty()) {
            cout << "Priority queue is empty\n";
            throw runtime_error("Priority queue is empty");
        }
        return queue.front().value;
    }

    // ³���������� ��� �������� ����� !� �����������!
    void Show() const {
        if (IsEmpty()) {
            cout << "Priority queue is empty\n";
            return;
        }
        cout << "Priority queue elements are:\n";
        for (const auto& element : queue) {
            cout << "Value: " << element.value << ", Priority: " << element.priority << "\n";
        }
    }
};

int main() {
    PriorityQueue<int> pq(5);

    pq.InsertWithPriority(10, 2);
    pq.InsertWithPriority(20, 1);
    pq.InsertWithPriority(30, 3);
    pq.InsertWithPriority(40, 5);
    pq.InsertWithPriority(50, 4);

    pq.Show();

    // ��������� ������� � �������� ����������
    pq.PullHighestPriorityElement();

    pq.Show();

    // ������ ����� ������� � ���������� �� �����
    pq.InsertWithPriority(60, 1);

    pq.Show();

    cout << "Highest priority element is: " << pq.Peek() << "\n";

    return 0;
}