#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key, value;
    Node* next;
};

class Dictionary {
    int size = 100;
    Node* table[100];

public:
    Dictionary() {
        for(int i = 0; i < 100; i++)
            table[i] = NULL;
    }

    int hashFunc(string key) {
        int sum = 0;
        for(char c : key)
            sum += c;
        return sum % 100;
    }

    void Add_Record(string key, string value) {
        int index = hashFunc(key);
        Node* n = new Node{key, value, table[index]};
        table[index] = n;
    }

    void Word_Search(string key) {
        int index = hashFunc(key);
        Node* temp = table[index];

        while(temp != NULL) {
            if(temp->key == key) {
                cout << "search key " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found\n";
    }

    void Print_Dictionary() {
        for(int i = 0; i < 100; i++) {
            Node* temp = table[i];
            while(temp != NULL) {
                cout << "index " << i << ": (" << temp->key << ", " << temp->value << ")\n";
                temp = temp->next;
            }
        }
    }
};

int main() {
    Dictionary d;

    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");

    d.Word_Search("AB");
    d.Print_Dictionary();

    return 0;
}
