#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key, value;
    Node* next;
};

class HashTable {
    int size;
    Node** table;

public:
    HashTable(int s = 10) {
        size = s;
        table = new Node*[size];
        for(int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunc(string key) {
        int sum = 0;
        for(char c : key)
            sum += c;
        return sum % size;
    }

    void insert(string key, string value) {
        int index = hashFunc(key);
        Node* n = new Node{key, value, table[index]};
        table[index] = n;
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << "(" << temp->key << "," << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();
    return 0;
}
