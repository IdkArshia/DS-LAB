#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* right; 
		Node* left;
		Node(int val){
			data=val;
			right=left=nullptr;
		}
};

class bst{
	public:
	Node * root=nullptr;
	Node* insert(Node* node,int val){
		if(node==nullptr){
			return new Node(val);
		}
		else if(val<node->data){
			node->left=insert(node->left,val);
		}
		else{
			node->right=insert(node->right,val);
		}
		return node;
	}
	
	Node *del(Node* node,int val){
		if(node==nullptr){
			return nullptr;
		}
			else if(val<node->data){
				node->left=del(node->left,val);
			}
			else if(val>node->data){
				node->right=del(node->right,val);
			}
			else{
				if(node->left==nullptr){
					Node* temp=node->right;
					delete node;
					return temp;
				}
				else if(node->right==nullptr){
					Node* temp=node->left;
					delete node;
					return temp;
				}
				else{
					Node * temp=IS(node->right);
					node->data=temp->data;
					node->right=del(node->right,temp->data);
				}
			}
			return node;
		}
	
	Node * IS(Node * node){
		if(node->left==nullptr){
			return node;
		}
		else{
			node=node->left;
		}
	}	
	
	void inOrder(Node* node){
		if(node==nullptr){
			return;
		}
		inOrder(node->left);
		cout<<node->data<<" ";
		inOrder(node->right);
	}
	
};
int main(){
	bst mybst;
	mybst.root=mybst.insert(mybst.root,2);
	mybst.root=mybst.insert(mybst.root,4);
	mybst.root=mybst.insert(mybst.root,1);
	mybst.root=mybst.insert(mybst.root,3);
	mybst.root=mybst.insert(mybst.root,6);
	mybst.inOrder(mybst.root);
	mybst.root=mybst.del(mybst.root,6);
	cout<<endl;
	mybst.inOrder(mybst.root);
}