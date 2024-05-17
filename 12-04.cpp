#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    size_t size;

public:
    Array() : data(nullptr), size(0) {}

    Array(size_t size) : size(size) {
        data = new int[size];
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Array(Array&& other) : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    ~Array() {
        delete[] data;
    }

    // Присваивание копированием
    Array& operator=(const Array& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // Присваивание перемещением
    Array& operator=(Array&& other) {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    void resize(size_t newSize) {
        int* newData = new int[newSize];
        for (size_t i = 0; i < (size < newSize ? size : newSize); ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    void fill(int value) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    void display() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }

    void sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    int min() const {
        if (size == 0) throw "Array is empty";
        int minValue = data[0];
        for (size_t i = 1; i < size; ++i) {
            if (data[i] < minValue) {
                minValue = data[i];
            }
        }
        return minValue;
    }

    int max() const {
        if (size == 0) throw "Array is empty";
        int maxValue = data[0];
        for (size_t i = 1; i < size; ++i) {
            if (data[i] > maxValue) {
                maxValue = data[i];
            }
        }
        return maxValue;
    }

    size_t getSize() const {
        return size;
    }

    int& operator[](size_t index) {
        if (index >= size) throw "Index out of range";
        return data[index];
    }

    const int& operator[](size_t index) const {
        if (index >= size) throw "Index out of range";
        return data[index];
    }
};

int main() {
    // Создаем массив пятерок
    Array arr(10);
    arr.fill(5);
    arr.display();

    // Добавляем 2 и 10 для последующей сортировки
    arr[5] = 2;
    arr[3] = 10;
    arr.display();

    // Сама сортировка
    arr.sort();
    arr.display();

    //Вывод мин макс значений
    cout << "\nMin: " << arr.min() << endl;
    cout << "\nMax: " << arr.max() << endl<<endl;

    //Меняем размер массива и заполняем тройками
    cout << endl << "(arr)" << endl; // для наглядности
    arr.resize(15);
    arr.fill(3);
    arr.display();

    // Копируем данные с arr в arr2
    cout << endl << "(arr2)" << endl;
    Array arr2 = arr;
    arr2.display();

    // Выполняем перемещение с arr в arr3
    cout << endl << "(arr3)" << endl;
    Array arr3 = move(arr);
    arr3.display();

    return 0;
}