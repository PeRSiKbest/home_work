#include <iostream>
using namespace std;

template <typename T>
class UniquePointer {
private:
    T* ptr;
public:
    explicit UniquePointer(T* p = nullptr) : ptr(p) {}

    ~UniquePointer() {
        delete ptr;
    }

    // Убираем возможность копирования, тк юник "так не умеет"
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Перемещение
    UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Доступ
    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

template <typename T>
class SharedPointer {
private:
    T* ptr;
    int* ref_count;
public:
    explicit SharedPointer(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}

    SharedPointer(const SharedPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
    }

    // Копирование
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    ~SharedPointer() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    int use_count() const {
        return *ref_count;
    }
};

int main() {
    // Тест UniquePointer
    UniquePointer<int> up1(new int(5));
    cout << "UniquePointer Value: " << *up1 << endl;

    UniquePointer<int> up2 = std::move(up1);
    if (up1.get() == nullptr) {
        cout << "up1 is null" << endl;
    }
    cout << "UniquePointer Value: " << *up2 << endl;

    // Тест SharedPointer
    cout << endl;
    SharedPointer<int> sp1(new int(10));
    cout << "SharedPointer Value: " << *sp1 << endl;
    cout << "Reference count: " << sp1.use_count() << endl;

    {
        SharedPointer<int> sp2 = sp1;
        cout << "SharedPointer Value: " << *sp2 << endl;
        cout << "Reference count: " << sp2.use_count() << endl;
    }

    cout << "Reference count after sp2 goes out of scope: " << sp1.use_count() << endl;

    return 0;
}