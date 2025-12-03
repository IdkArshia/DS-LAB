#include <iostream>
using namespace std;

const int size = 7;   // Table size (prime)
const int R = 5;      // Second prime < size

class Entry {
public:
    int key;
    string value;

    Entry() {
        key = -1;     // -1 = EMPTY
        value = "";
    }

    Entry(int k, string v) {
        key = k;
        value = v;
    }
};

class hashTable {
public:
    Entry table[size];

    // ? First Hash Function
    int hash1(int key) {
        return key % size;
    }

    // ? Second Hash Function
    int hash2(int key) {
        return R - (key % R);
    }

    // ? INSERT (DOUBLE HASHING)
    void insert(int key, string value) {
        int index = hash1(key);
        int step = hash2(key);

        if (table[index].key == -1) {
            table[index] = Entry(key, value);
            return;
        }

        for (int i = 1; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex].key == -1) {
                table[newIndex] = Entry(key, value);
                return;
            }
        }

        cout << "Hash Table is Full\n";
    }

    // ? DELETE (DOUBLE HASHING)
    void del(int key) {
        int index = hash1(key);
        int step = hash2(key);

        if (table[index].key == key) {
            table[index].key = -1;
            table[index].value = "";
            cout << "Key deleted\n";
            return;
        }

        for (int i = 1; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex].key == key) {
                table[newIndex].key = -1;
                table[newIndex].value = "";
                cout << "Key deleted\n";
                return;
            }

            if (table[newIndex].key == -1)
                break;
        }

        cout << "Key not found\n";
    }

    // ? SEARCH (DOUBLE HASHING)
    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);

        if (table[index].key == key) {
            cout << "Found: " << table[index].value << endl;
            return;
        }

        for (int i = 1; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex].key == key) {
                cout << "Found: " << table[newIndex].value << endl;
                return;
            }

            if (table[newIndex].key == -1)
                break;
        }

        cout << "Key not found\n";
    }

    // ? DISPLAY
    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i].key == -1)
                cout << i << ": EMPTY\n";
            else
                cout << i << ": " << table[i].key
                     << " -> " << table[i].value << endl;
        }
    }
};

int main() {
    hashTable h;

    h.insert(2, "Arshia");
    h.insert(9, "Is");
    h.insert(16, "Gonna");
    h.insert(23, "Ace");
    h.insert(30, "This");

    cout << "Initial Table:\n";
    h.display();

    cout << endl;
    h.search(16);

    cout << endl;
    h.del(9);
    h.display();
}
