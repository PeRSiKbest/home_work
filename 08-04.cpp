#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Reservoir {
private:
    string name;
    string type;
    double width;
    double length;
    double max_depth;

public:
    explicit Reservoir() : name(""), type(""), width(0), length(0), max_depth(0) {}

    explicit Reservoir(const string& n, const string& t, double w, double l, double d)
        : name(n), type(t), width(w), length(l), max_depth(d) {}

    ~Reservoir() {}

    Reservoir(const Reservoir& other) : name(other.name), type(other.type), width(other.width), length(other.length), max_depth(other.max_depth) {}

    // Об'єм
    double approximateVolume() const {
        return width * length * max_depth;
    }

    // Площа поверхні
    double surfaceArea() const {
        return width * length;
    }

    // Порівняння площі поверхні водойм
    double compareSurfaceArea(const Reservoir& other) const {
        if (sameType(other)) {
            return surfaceArea() - other.surfaceArea();
        }
        else {
            cout << "Reservoirs are not of the same type." << endl;
            return 0;
        }
    }

    // Перевірка, чи належать водойми до одного типу
    bool sameType(const Reservoir& other) const {
        if ((type == "Sea" && other.type == "Sea") || (type == "Basin" && other.type == "Pond")) {
            return true;
        }
        else {
            return false;
        }
    }

    // Копіювання об'єкту
    Reservoir copyReservoir() const {
        return Reservoir(name, type, width, length, max_depth);
    }

    // Сеттери
    void setName(const string& n) { name = n; }
    void setType(const string& t) { type = t; }
    void setWidth(double w) { width = w; }
    void setLength(double l) { length = l; }
    void setMaxDepth(double d) { max_depth = d; }

    // Геттери
    string getName() const { return name; }
    string getType() const { return type; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getMaxDepth() const { return max_depth; }
};

// Додавання об'єктів в масив
void addReservoir(vector<Reservoir>& reservoirs) {
    string name;
    int type;
    double width, length, max_depth;

    cout << "Enter reservoir name: ";
    getline(cin, name);

    cout << "Select reservoir type:\n1. Sea\n2. Basin\n3. Pond" << endl;
    cout << "Enter your choice: ";
    cin >> type;
    cin.ignore();

    string reservoirType;
    switch (type) {
    case 1:
        reservoirType = "Sea";
        break;
    case 2:
        reservoirType = "Basin";
        break;
    case 3:
        reservoirType = "Pond";
        break;
    default:
        cout << "Invalid reservoir type. Defaulting to Sea." << endl;
        reservoirType = "Sea";
        break;
    }

    cout << "Enter reservoir width: ";
    cin >> width;
    cout << "Enter reservoir length: ";
    cin >> length;
    cout << "Enter reservoir max depth: ";
    cin >> max_depth;

    cin.ignore();

    Reservoir r(name, reservoirType, width, length, max_depth);
    reservoirs.push_back(r);

 }

void copyAndAddReservoir(vector<Reservoir>& reservoirs) {
    if (!reservoirs.empty()) {
        cout << "Enter index of reservoir to copy: ";
        int index;
        cin >> index;
        Reservoir copiedReservoir = reservoirs[index].copyReservoir();
        reservoirs.push_back(copiedReservoir);
        cout << "Reservoir copied successfully and added to the list. Name: " << copiedReservoir.getName() << ", Type: " << copiedReservoir.getType() << ", Volume: " << copiedReservoir.approximateVolume() << ", Area: " << copiedReservoir.surfaceArea() << endl;
    }
    else {
        cout << "There are no reservoirs to copy." << endl;
    }
}

// Видалення об'єкту з масиву за індексом
void removeReservoir(vector<Reservoir>& reservoirs, int index) {
    if (index >= 0 && index < reservoirs.size()) {
        reservoirs.erase(reservoirs.begin() + index);
    }
}

int main() {
    vector<Reservoir> reservoirs;

    while (true) {
        cout << "\n1. Add a reservoir\n"
            << "2. Remove a reservoir\n"
            << "3. View all reservoirs\n"
            << "4. Compare surface area of reservoirs\n"
            << "5. Copy a reservoir\n"
            << "6. Exit\n"
            << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addReservoir(reservoirs);
            break;
        case 2: {
            if (!reservoirs.empty()) {
                cout << "Enter index of reservoir to remove: ";
                int index;
                cin >> index;
                removeReservoir(reservoirs, index);
            }
            else {
                cout << "There are no reservoirs to remove." << endl;
            }
            break;
        }
        case 3: {
            if (!reservoirs.empty()) {
                cout << "\nList of reservoirs:" << endl;
                for (size_t i = 0; i < reservoirs.size(); ++i) {
                    cout << "Index: " << i << ", Name: " << reservoirs[i].getName() << ", Type: " << reservoirs[i].getType() << ", Volume: " << reservoirs[i].approximateVolume() << ", Area: " << reservoirs[i].surfaceArea() << endl;
                }
            }
            else {
                cout << "No reservoirs available." << endl;
            }
            break;
        }
        case 4: {
            if (reservoirs.size() >= 2) {
                cout << "Enter index of first reservoir: ";
                int index1;
                cin >> index1;
                cout << "Enter index of second reservoir: ";
                int index2;
                cin >> index2;

                double diff = reservoirs[index1].compareSurfaceArea(reservoirs[index2]);
                if (diff != 0) {
                    cout << "Difference in surface area: " << diff << endl;
                }
            }
            else {
                cout << "At least two reservoirs are required to compare." << endl;
            }
            break;
        }
        case 5: {
            copyAndAddReservoir(reservoirs);
            break;
        }
        case 6:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
