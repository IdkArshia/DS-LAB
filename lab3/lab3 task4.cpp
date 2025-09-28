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
	
	void display(){
		node* current=head;
		cout<<endl;
		while(current!=nullptr){
			cout<<current->data<<"->";
			current=current->Next;
		}
		cout<<"NULL";
	}
	void organize(){
		linkedList le;
		linkedList lo;
		node* current=head;
		while(current!=nullptr){
			if(current->data%2==0){
				le.addNode_end(current->data);
			}
			else{
				lo.addNode_end(current->data);
			}
			current=current->Next;
		}
		le.tail->Next=lo.head;
		head=le.head;
		tail=lo.tail;
	}
};
int main(){
	linkedList l1;
	l1.addNode_end(17);
	l1.addNode_end(15);
	l1.addNode_end(8);
	l1.addNode_end(12);
	l1.addNode_end(10);
	l1.addNode_end(5);
	l1.addNode_end(4);
	l1.addNode_end(1);
	l1.addNode_end(7);
	l1.addNode_end(6);
	l1.display();
	l1.organize();
	l1.display();
	linkedList ll;
	ll.addNode_end(4);
	ll.addNode_end(6);
	ll.addNode_end(8);
	ll.display();
	ll.organize();
	ll.display();
	
}