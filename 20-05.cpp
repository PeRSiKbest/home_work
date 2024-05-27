#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Мин значение
class FindMin {
public:
    int operator()(const vector<int>& vec) const {
        return *min_element(vec.begin(), vec.end());
    }
};

// Макс значение
class FindMax {
public:
    int operator()(const vector<int>& vec) const {
        return *max_element(vec.begin(), vec.end());
    }
};

// Сортировка на спад
class SortDescending {
public:
    static bool compare(int a, int b) {
        return a > b;
    }

    void operator()(vector<int>& vec) const {
        sort(vec.begin(), vec.end(), compare);
    }
};

// Сортировка на вырост
class SortAscending {
public:
    void operator()(vector<int>& vec) const {
        sort(vec.begin(), vec.end());
    }
};

// Увеличение значений на константу
class IncreaseByConstant {
    int constant;
public:
    IncreaseByConstant(int c) : constant(c) {}

    void operator()(vector<int>& vec) const {
        transform(vec.begin(), vec.end(), vec.begin(),
            [this](int value) { return value + this->constant; });
    }
};

// Уменьшение значений на константу
class DecreaseByConstant {
    int constant;
public:
    DecreaseByConstant(int c) : constant(c) {}

    void operator()(vector<int>& vec) const {
        transform(vec.begin(), vec.end(), vec.begin(),
            [this](int value) { return value - this->constant; });
    }
};

// Удаление искомых элементов
class RemoveValue {
    int value;
public:
    RemoveValue(int v) : value(v) {}

    void operator()(vector<int>& vec) const {
        vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
    }
};

int main() {
    vector<int> vec = { 10, 3, 5, 7, 2, 8, 3 };

    FindMin findMin;
    FindMax findMax;
    SortDescending sortDesc;
    SortAscending sortAsc;
    IncreaseByConstant increase(5);
    DecreaseByConstant decrease(2);
    RemoveValue removeVal(6);

    cout << "Initial vector: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    cout << "Minimum value: " << findMin(vec) << endl;
    cout << "Maximum value: " << findMax(vec) << endl;

    sortDesc(vec);
    cout << "Sorted in descending order: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    sortAsc(vec);
    cout << "Sorted in ascending order: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    increase(vec);
    cout << "After increasing by 5: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    decrease(vec);
    cout << "After decreasing by 2: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    removeVal(vec);
    cout << "After removing value 6: ";
    for (int num : vec) cout << num << " ";
    cout << endl;

    return 0;
}