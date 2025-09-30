#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* Next;
	
	node(int val){
		data=val;
		Next=nullptr;
	}
};

class linkedList{
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
			tail=newNode;
			newNode->Next=nullptr;
		}
	}
	
	linkedList alt_list(){
		linkedList al;
		node* current=head;
		while(current->Next!=nullptr && current->Next->Next!=nullptr){
			al.addNode_end(current->Next->data);
			current=current->Next->Next;
		}
		if(current->Next!=nullptr){
			al.addNode_end(current->Next->data);
		}
		return al;
		
	}
	void join_alt(linkedList al){
		tail->Next=al.head;
		tail=al.tail;
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
	linkedList l1;
	l1.addNode_end(1);
	l1.addNode_end(2);
	l1.addNode_end(3);
	l1.addNode_end(4);
	l1.addNode_end(5);
	l1.addNode_end(6);
	l1.addNode_end(7);
	l1.addNode_end(8);
	linkedList alt=l1.alt_list();
	alt.display();
	l1.join_alt(alt);
	l1.display();
}