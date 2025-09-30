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

class circular{
	public:
	node* head=nullptr;
	node* tail=nullptr;
	
	void addNode_front(int val){
		node* newNode=new node(val);
		if(head==nullptr){
			head=newNode;
			tail=newNode;
			tail->Next=head;
		}
		else{
			newNode->Next=head;
			head=newNode;
			tail->Next=head;
		}
	}
	
	void addNode_end(int val){
		node* newNode=new node(val);
		if(head==nullptr){
			head=newNode;
			tail=newNode;
			tail->Next=head;
		}
		else{
			tail->Next=newNode;
			tail=newNode;
			newNode->Next=head;
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
		if(current->Next==head){
			this->addNode_end(val);
		}
		else if(current==head){
			this->addNode_front(val);
		}
		newNode->Next=prev->Next;
		prev->Next=newNode;
	}
	
	void display(){
		node* current=head;
		cout<<endl;
		cout<<current->data<<"->";
		current=current->Next;
		while(current!=head){
			cout<<current->data<<"->";
			current=current->Next;
		}
		cout<<"NULL";
	}
	
	void dlt_val(int val){
		node* current=head;
		node* prev=head;
		do{
			if(current->data==val){
				if(current==head){
					tail->Next=current->Next;
					head=head->Next;
					cout<<endl<<val<<" removed";
					return;
				}
				else if(current->Next==head){
					prev->Next=current->Next;
					tail=prev;
					cout<<val<<" removed";
					return;
				}
				else{
					prev->Next=current->Next;
					cout<<val<<" removed";
					return;
				}
			}
			prev=current;
			current=current->Next;
		}while(current!=head);
		cout<<val<<" not present";
		
	}
	
};

int main(){
	circular cl;
	cl.addNode_end(1);
	cl.addNode_end(2);
	cl.addNode_end(3);
	cl.addNode_end(5);
	cl.addNode_end(6);
	cl.display();
	cl.addNode_front(0);
	cl.display();
	cl.insert_at_pos(4,4);
	cl.display();
	cl.dlt_val(2);
	cl.display();
}