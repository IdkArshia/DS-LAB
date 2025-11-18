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
	Node* root=nullptr;
	Node* insert(Node* r, int val){
		if(r==nullptr){
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
		
		void inorder(Node* node){
			if(node==nullptr){
				return;
			}
			inorder(node->left);
			cout<<node->data<<" ";
			inorder(node->right);
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
	BST tree1;
	tree1.root=tree1.insert(tree1.root,30);
	tree1.root=tree1.insert(tree1.root,40);
	tree1.root=tree1.insert(tree1.root,20);
	tree1.root=tree1.insert(tree1.root,60);
	int val;
	cout<<"enter value to search: ";
	cin>>val;
	Node* temp=tree1.search(tree1.root,val);
	if(temp!=nullptr){
		cout<<"value found";
		return 0;
	}
	else{
		tree1.root=tree1.insert(tree1.root,val);
		cout<<"value inserted";
	}
	
	
}