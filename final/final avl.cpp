#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* right;
	Node* left;
	int height;
	
	Node(int val){
		data=val;
		left=right=nullptr;
		height=1;
	}
};

class avl{
	public:
	Node* root=nullptr;
	int h(Node* n){
		if(n==nullptr){
			return 0;
		}
		else{
			return n->height;
		}
	}
	
	int balance(Node* n){
		if(n==nullptr){
			return 0;
		}
		else{
			return (h(n->left)-h(n->right));
		}
	}
	
	void update(Node *n){
		n->height=1+ max(h(n->left),h(n->right));
	}
	
	Node* leftR(Node* y){
		Node* x=y->right;
		Node * t=x->left;
		x->left=y;
		y->right=t;
		update(y);
		update(x);
		return x;
		
	}
	
	Node* rightR(Node* y){
		Node* x=y->left;
		Node * t=x->right;
		x->right=y;
		y->left=t;
		update(y);
		update(x);
		return x;
		
	}
	
	
	Node* insert(Node* n,int val){
		if(n==nullptr){
			return new Node(val);
		}
		else if(val<n->data){
			n->left=insert(n->left,val);
		}
		else{
			n->right=insert(n->right,val);
		}
		
		update(n);
		int bf=balance(n);
		
		//greater than 1 matlab left heavy matlab rr
		if(bf>1 && val<n->left->data){
			return rightR(n);
		}
		
		//less than -1 matlab right heavy matlab ll
		if(bf<-1 && val>n->right->data){
			return leftR(n);
		}
		
		//greater than one matlab pehle left and greater than left node matlab lr case
		if(bf>1 && val>n->left->data){
			n->left=leftR(n->left);
			return rightR(n);
		}
		
		if(bf<-1 && val<n->right->data){
			n->right=rightR(n->right);
			return leftR(n);
		}
		
		return n;
	}
	Node * del(Node* n, int val){
		if(n==nullptr){
			return nullptr;
		}
		else if(val<n->data){
			n->left=del(n->left,val);
		}
		else if(val>n->data){
			n->right=del(n->right,val);
		}
		else{
			if(n->right==nullptr){
				Node* t=n->left;
				delete n;
				return t;
			}
			else if(n->left==nullptr){
				Node* t=n->right;
				delete n;
				return t;
			}
			else{
				Node* t=IS(n->right);
				n->data=t->data;
				n->right=del(n->right,t->data);
			}
			
		}
		
		update(n);
		int bf=balance(n);
		
		if(bf>1 && val<n->left->data){
			return rightR(n);
		}
		if(bf<-1 && val>n->right->data){
			return leftR(n);
		}
		if(bf>1 && val>n->left->data){
			n->left= leftR(n->left);
			return rightR(n);
		}
		if(bf<-1 && val<n->right->data){
			n->right=rightR(n->right);
			return leftR(n);
		}
		return n;
		
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
	avl mybst;
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