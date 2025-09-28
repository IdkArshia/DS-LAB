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
	
	void addNode_front(int val){
		node* newNode=new node(val);
		if(head==nullptr){
			head=newNode;
			tail=newNode;
		}
		else{
			newNode->Next=head;
			head=newNode;
		}
	}
	
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
	void insert_at_pos(int val, int pos){
		node* newNode=new node(val);
		node*current=head;
		node* prev=head;
		for(int i=0;i<pos;i++){
			prev=current;
			current=current->Next;
		}
		newNode->Next=prev->Next;
		prev->Next=newNode;
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
	
	void dlt_val(int val){
		node* current=head;
		node* prev=head;
		while( current!=nullptr && current->data!=val){
			prev=current;
			current=current->Next;
		}
		if(current==nullptr){
			cout<<"value not present";
			return;
		}
		else if(current==head){
			head=current->Next;
			cout<<"\n"<<val <<" deleted from the linked list";
		}
		else{
			prev->Next=current->Next;	
			cout<<"\n"<<val <<" deleted from the linked list";
		}
		
	}
	
};
int main(){
	linkedList l1;
	l1.addNode_end(3);
	l1.addNode_end(4);
	l1.addNode_end(6);
	l1.addNode_end(2);
	l1.addNode_end(9);
	l1.display();
	l1.dlt_val(6);
	l1.dlt_val(3);
	l1.dlt_val(9);
	l1.display();
}