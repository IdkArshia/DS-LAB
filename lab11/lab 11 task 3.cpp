#include <iostream>
#include <list>
using namespace std;

class Hash {
    int size;
    list<int>* table;

public:
    Hash(int s) {
        size = s;
        table = new list<int>[size];
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunc(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunc(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunc(key);
        for(int x : table[index])
            if(x == key)
                return true;
        return false;
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << "index " << i << ": ";
            for(int x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    Hash h(7);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);

    h.display();

    cout << (h.search(15) ? "Found\n" : "Not Found\n");

    h.remove(10);
    h.display();

    return 0;
}
