#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void kthSmallest(Node* root, int &k) {
    if (!root) return;

    kthSmallest(root->left, k);
    k--;
    if (k == 0) {
        cout << "Kth Smallest: " << root->data << endl;
        return;
    }
    kthSmallest(root->right, k);
}

void kthLargest(Node* root, int &k) {
    if (!root) return;

    kthLargest(root->right, k);
    k--;
    if (k == 0) {
        cout << "Kth Largest: " << root->data << endl;
        return;
    }
    kthLargest(root->left, k);
}

int height(Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    Node* root = NULL;
    int arr[7] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    int k = 3;
    int ks = k, kl = k;

    kthSmallest(root, ks);
    kthLargest(root, kl);

    cout << "Left Height: " << height(root->left) << endl;
    cout << "Right Height: " << height(root->right) << endl;
}
