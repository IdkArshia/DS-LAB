#include <iostream>
using namespace std;

class StudentHashTable {
    int size = 15;
    int roll[15];
    string name[15];

public:
    StudentHashTable() {
        for(int i = 0; i < 15; i++)
            roll[i] = -1;
    }

    int hashFunc(int r) {
        return r % 15;
    }

    void InsertRecord(int r, string n) {
        int index = hashFunc(r);
        int i = 0;

        while(roll[(index + i*i) % 15] != -1)
            i++;

        int pos = (index + i*i) % 15;
        roll[pos] = r;
        name[pos] = n;
    }

    void SearchRecord(int r) {
        int index = hashFunc(r);
        int i = 0;

        while(roll[(index + i*i) % 15] != -1) {
            int pos = (index + i*i) % 15;

            if(roll[pos] == r) {
                cout << "Student Name: " << name[pos] << endl;
                return;
            }
            i++;
        }
        cout << "Record not found\n";
    }

    void display() {
        for(int i = 0; i < 15; i++) {
            if(roll[i] != -1)
                cout << i << ": " << roll[i] << " " << name[i] << endl;
        }
    }
};

int main() {
    StudentHashTable h;

    h.InsertRecord(21, "Ali");
    h.InsertRecord(36, "Ahmed");
    h.InsertRecord(51, "Sara");

    h.display();
    h.SearchRecord(36);
    h.SearchRecord(100);

    return 0;
}
