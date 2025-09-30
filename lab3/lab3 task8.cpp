#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* Next;
	node* prev;
	
	node(int val){
		data=val;
		Next=nullptr;
		prev=nullptr;
	}
};

class D_linkedList{
	public:
	node* head=nullptr;
	node* tail=nullptr;

	void addNode_end(int val){
		node* newNode=new node(val);
		if(head==nullptr){
			head=newNode;
			tail=newNode;
		}
		else{
			tail->Next=newNode;
			newNode->prev=tail;
			tail=newNode;
			newNode->Next=nullptr;
		}
	}
	void display(){
		node* current=head;
		cout<<endl;
		while(current!=nullptr){
			cout<<current->data<<"->";
			current=current->Next;
		}
		cout<<"NULL";
	}
	
};
int main(){
	D_linkedList L;
	L.addNode_end(1);
	L.addNode_end(2);
	L.addNode_end(3);
	L.addNode_end(4);
	L.addNode_end(5);
	L.display();
	D_linkedList M;
	M.addNode_end(6);
	M.addNode_end(7);
	M.addNode_end(8);
	M.addNode_end(9);
	M.addNode_end(10);
	M.display();
	// Joining the two lists:
	L.tail->Next=M.head;
	M.head->prev=L.tail;
	L.display();
}