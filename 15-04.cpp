#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

public:
    Array(int initialSize = 0, int growBy = 1)
        : size(0), capacity(initialSize), grow(growBy) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    //�������� ������ �������
    int GetSize() const {
        return capacity;
    }

    //��������� ������� �������
    void SetSize(int newSize, int growBy = 1) {
        grow = growBy;
        if (newSize > capacity) {
            T* newData = new T[newSize];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newSize;
        }
        else if (newSize < capacity) {
            T* newData = new T[newSize];
            for (int i = 0; i < newSize; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newSize;
        }
        if (size > capacity) {
            size = capacity;
        }
    }

    //�������� ������ ���������� ��������
    int GetUpperBound() const {
        return size - 1;
    }

    //������ �� ������
    bool IsEmpty() const {
        return size == 0;
    }

    //������� ������ ������
    void FreeExtra() {
        if (size < capacity) {
            SetSize(size);
        }
    }

    //������� ���
    void RemoveAll() {
        delete[] data;
        data = new T[capacity];
        size = 0;
    }

    //�������� ������� �� ��������
    T GetAt(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    //��������� ������� �� ��������
    void SetAt(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        data[index] = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    //�������� �������
    void Add(const T& value) {
        if (size >= capacity) {
            SetSize(capacity + grow);
        }
        data[size++] = value;
    }

    //����������� ��������
    void Append(const Array<T>& other) {
        for (int i = 0; i < other.size; ++i) {
            Add(other.data[i]);
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        grow = other.grow;
        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    //�������� ����� �������
    T* GetData() const {
        return data;
    }

    //��������� ������� � �������
    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        if (size >= capacity) {
            SetSize(capacity + grow);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    //������� �� �� �������
    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
};

int main() {
    Array<int> arr(10, 5);
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    cout << "Array size: " << arr.GetSize() << endl;
    cout << "Upper bound: " << arr.GetUpperBound() << endl;
    cout << "Is array empty? " << (arr.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Element at index 1: " << arr.GetAt(1) << endl;
    arr.SetAt(1, 20);
    cout << "Element at index 1 after SetAt: " << arr[1] << endl;
    arr.RemoveAt(1);
    cout << "Array size after removing element at index 1: " << arr.GetSize() << endl;
    arr.FreeExtra();
    cout << "Array size after FreeExtra: " << arr.GetSize() << endl;
    return 0;
}