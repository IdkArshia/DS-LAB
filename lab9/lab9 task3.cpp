#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int v) {
        data = v;
        left = right = NULL;
        height = 1;
    }
};

int h(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;

    return y;
}

int balance(Node* n) {
    if (n == NULL) return 0;
    return h(n->left) - h(n->right);
}

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    root->height = max(h(root->left), h(root->right)) + 1;

    int bf = balance(root);

    if (bf > 1 && val < root->left->data)
        return rightRotate(root);

    if (bf < -1 && val > root->right->data)
        return leftRotate(root);

    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[5] = {10, 5, 15, 3, 7};

    for (int i = 0; i < 5; i++)
        root = insert(root, arr[i]);

    root = insert(root, 12);

    cout << "Final Balanced AVL (Preorder): ";
    preorder(root);
}
