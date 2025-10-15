#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(char c) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }
    bool isEmpty() {
        return top < 0;
    }
};
bool isPalindrome(string str) {
    int len = str.length();
    Stack s(len);
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }

    return true;
}
int main() {
    string word = "BORROWROB";
    for (int i = 0; i < word.length(); i++) {
        cout << word[i];
    }
    cout << endl;
    if (isPalindrome(word)) {
        cout << word << " is a palindrome!" << endl;
    } else {
        cout  << word << " is not a palindrome." << endl;
    }

    return 0;
}