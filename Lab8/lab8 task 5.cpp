#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data=val;
		left=nullptr;
		right=nullptr;
	}
};
class BST{
	public:
		int size=0;
	Node* root=nullptr;
	Node* insert(Node* r, int val){
		if(r==nullptr){
			size++;
			return new Node(val);
		}
		if(val<r->data){
			r->left=insert(r->left,val);
		}
		else if(val>r->data){
			r->right=insert(r->right,val);
		}
		return r;
	}
	Node* deletenode(Node*r,int val){
			if(r==nullptr){
				return r;
			}
			else if(val<r->data){
				r->left=deletenode(r->left,val);
			}
			else if(val>r->data){
				r->right=deletenode(r->right,val);
			}
			else{
				if(r->left==nullptr){
					Node* temp=r->right;
					delete r;
					return temp;
				}
				else if(r->right==nullptr){
					Node* temp=r->left;
					delete r;
					return temp;
				}
				else{
					Node* temp=minNode(r->right);
					r->data=temp->data;
					r->right=deletenode(r->right,temp->data);
					return r;
				}
			}
			return r;
		}
		
		Node* search(Node* node, int val){
			if(node==nullptr || node->data==val){
				return node;
			}
			else{
				if(val<node->data){
					return search(node->left,val);
				}
				else if(val>node->data){
					return search(node->right,val);
				}
			}
		}
		
		Node* minNode(Node* node){
			Node* current=node;
			while(current->left!=nullptr){
				current=current->left;
			}
			return current;
		}
		
		bool inorder(Node* node,Node*& prev){
			if(node==nullptr){
				return true;
			}
			if(!inorder(node->left,prev)){
				return false;
			}
			if(prev!= nullptr && node->data<=prev->data){
				return false;
			}
			prev=node;
			return inorder(node->right,prev);
		}
		void preorder(Node* node){
			if(node==nullptr){
				return;
			}
			cout<<node->data<<" ";
			preorder(node->left);
			preorder(node->right);
		}
		void postorder(Node* node){
			if(node==nullptr){
				return;
			}
			postorder(node->left);
			postorder(node->right);
			cout<<node->data<<" ";
		}
};
int main(){
	BST bst;
	bst.root=new Node(10);
	bst.root->left=new Node(5);
	bst.root->right=new Node(20);
	bst.root->right->left=new Node(25);
	bst.root->right->right=new Node(30);
	Node* prev=nullptr;
	if(bst.inorder(bst.root,prev)){
		cout<<"It is a BST";
	}
	else{
		cout<<"Not a BST";
	}
	return 0;
}