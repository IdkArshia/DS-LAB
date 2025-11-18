#include <iostream>
using namespace std;

class product{
	public:
		int id;
		int quantity;
		product(int Id, int q){
			id=Id;
			quantity=q;
		}
};
struct Node {
	product pd;
	Node* left;
	Node* right;
	Node(product p) : pd(p), left(nullptr), right(nullptr) {}
};
class BST{
	public:
	Node* root=nullptr;
	Node* insert(Node* r, product p){
		if(r==nullptr){
			return new Node(p);
		}
		if(p.id<r->pd.id){
			r->left=insert(r->left,p);
		}
		else if(p.id>r->pd.id){
			r->right=insert(r->right,p);
		}
		return r;
	}
	
		Node* search(Node* node, int Id){
			if(node==nullptr || node->pd.id==Id){
				return node;
			}
			else{
				if(Id<node->pd.id){
					return search(node->left,Id);
				}
				else if(Id>node->pd.id){
					return search(node->right,Id);
				}
			}
		}
		
		void updateQ(Node* node, int Id, int q){
			if(node==nullptr){
				cout<<"ID does not exist";
				return;
			}
			if(node->pd.id==Id){
				node->pd.quantity=q;
				cout<<"quantity updated";
				return;
			}
			
			else{
				if(Id<node->pd.id){
					updateQ(node->left,Id,q);
				}
				else if(Id>node->pd.id){
					updateQ(node->right,Id,q);
				}
			}
		}
		
		Node* highest_stock(Node* node, Node* temp){
    		if(node == nullptr) return temp;
    		if(temp == nullptr || node->pd.quantity > temp->pd.quantity){
        		temp = node;
    		}
    		temp = highest_stock(node->left, temp);
    		temp = highest_stock(node->right, temp);
    		return temp;
}

	
};
int main(){
	BST bst;
	product p1(1,23);
	product p2(2,34);
	product p3(3,14);
	bst.root=bst.insert(bst.root,p1);
	bst.root=bst.insert(bst.root,p2);
	bst.root=bst.insert(bst.root,p3);
	bst.updateQ(bst.root,2,45);
	Node*temp=nullptr;
	Node* hs=bst.highest_stock(bst.root,nullptr);
	cout<<"\nhighest stock: "<<hs->pd.quantity;
	
	
	
}