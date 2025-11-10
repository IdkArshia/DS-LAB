#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;

    Student() {}
    Student(string n, int r, int s) {
        name = n;
        roll = r;
        score = s;
    }
};

struct Node {
    Student data;
    Node* left;
    Node* right;
    Node(Student val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, Student val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val.name < node->data.name)
            node->left = insert(node->left, val);
        else if (val.name > node->data.name)
            node->right = insert(node->right, val);
        return node;
    }

    Node* find_min(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* delete_node(Node* node, string name) {
        if (node == NULL) return node;

        if (name < node->data.name)
            node->left = delete_node(node->left, name);
        else if (name > node->data.name)
            node->right = delete_node(node->right, name);
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data.name);
            }
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data.name << " " << node->data.roll << " " << node->data.score << endl;
            inorder(node->right);
        }
    }

    Node* search(Node* node, string name) {
        if (node == NULL || node->data.name == name)
            return node;
        if (name < node->data.name)
            return search(node->left, name);
        return search(node->right, name);
    }

    void delete_low_scores(Node* node) {
        if (node == NULL) return;
        delete_low_scores(node->left);
        delete_low_scores(node->right);
        if (node->data.score < 10) {
            cout << "Deleting " << node->data.name << " " << node->data.score << endl;
            remove(node->data.name);
        }
    }

    void find_max_score(Node* node, Student &maxStu) {
        if (node == NULL) return;
        if (node->data.score > maxStu.score)
            maxStu = node->data;
        find_max_score(node->left, maxStu);
        find_max_score(node->right, maxStu);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(Student val) {
        root = insert(root, val);
    }

    void remove(string name) {
        root = delete_node(root, name);
    }

    void display() {
        inorder(root);
    }

    void search(string name) {
        Node* res = search(root, name);
        if (res)
            cout << res->data.name << " " << res->data.roll << " " << res->data.score << endl;
    }

    void deleteLowScoreStudents() {
        delete_low_scores(root);
    }

    void getMaxScoreStudent() {
        if (root == NULL) return;
        Student maxStu = root->data;
        find_max_score(root, maxStu);
        cout << maxStu.name << " " << maxStu.roll << " " << maxStu.score << endl;
    }
};

int main() {
    BST tree;

    Student s[10] = {
        Student("Ali", 1, 15),
        Student("Sara", 2, 8),
        Student("Bilal", 3, 25),
        Student("Nida", 4, 5),
        Student("Umar", 5, 40),
        Student("Hina", 6, 9),
        Student("Raza", 7, 18),
        Student("Zara", 8, 12),
        Student("Daniyal", 9, 35),
        Student("Asma", 10, 50)
    };

    tree.insert(s[0]);
    tree.insert(s[2]);
    tree.insert(s[4]);
    tree.insert(s[6]);
    tree.insert(s[7]);
    tree.insert(s[9]);
    tree.insert(s[1]);

    tree.display();

    tree.search("Sara");

    tree.deleteLowScoreStudents();

    tree.display();

    tree.getMaxScoreStudent();

    return 0;
}
