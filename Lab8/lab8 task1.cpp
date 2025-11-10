#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data  = val;
		left = right = NULL;
	}
};
class BST {

	Node* root;
	Node* insert(Node* node, int val){
		if(node == NULL){
			return new Node(val);
		}
		if( val < node->data){
			node->left = insert(node->left, val);
		}
		else if(val > node->data){
			node->right = insert(node->right, val);
		}
		return node;
	}
	public:
	BST(){
		root = NULL;
	}
	void insert(int val){
		root = insert(root, val);
	}
	void inorder(Node* node) const{
		if(node!=NULL){
			inorder(node->left);
			cout<<node->data<<" ";
			inorder(node->right);
		}
	}
	Node* delete_node(Node* node, int val){
		if(node == NULL){
			return node;
		} if(val < node->data){
			node->left = delete_node(node->left, val);
		} else if(val > node->data){
			node->right = delete_node(node->right, val);
		} else {
			if(node->left == NULL && node->right == NULL){
				delete node;
				return NULL;
			} else if(node->left == NULL){
				Node* temp = node->right;
				delete node;
				return temp;
			} else if (node->right == NULL){
				Node* temp = node->left;
				delete node;
				return temp;
			} else {
				Node* temp = find_min(node->right);
				node->data = temp->data;
				node->right = delete_node(node->right, temp->data);
			}
		}
		return node;
	}
	Node* find_min(Node* node){
		while (node && node->left != NULL)
            node = node->left;
        return node;
	}
	void remove(int val){
		root = delete_node(root, val);
	}
	void display(){
		inorder(root);
	}
	
};

int main(){
	///cout<<"tes";
	BST tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(4);
	tree.insert(2);
	tree.display();
	tree.remove(3);
	tree.display();

}