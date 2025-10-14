#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int val){
			data=val;
			next=nullptr;
			prev=nullptr;
		}
};
class linked_list{
	public:
		node* head=nullptr;
		node* tail=nullptr;
	
	void insertNode_end(int val){
		node* newNode=new node(val);
		if(head==nullptr){
			head=newNode;
			tail=newNode;
		}
		else{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}
	}	
	void insertNode_pos(int val, int pos){
		node* newNode=new node(val);
		node* current=head;
		for(int i=1;i<pos;i++){
			current=current->next;
		}
		newNode->prev=current->prev;
		current->prev->next=newNode;
		newNode->next=current;
		current->prev=newNode;
	}
	void dltNode_pos(int pos){
		node* current=head;
		for(int i=1;i<pos;i++){
			current=current->next;
		}
		current->prev->next=current->next;
		current->next->prev=current->prev;
	}
	void display(){
		node* current=head;
		while(current!=nullptr){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<"NULL\n";
	}
		
};
int main(){
	linked_list l1;
	l1.insertNode_end(1);
	l1.insertNode_end(2);
	l1.insertNode_end(3);
	l1.insertNode_end(4);
	l1.insertNode_pos(5,3);
	l1.display();
	l1.dltNode_pos(3);
	l1.display();
	
}
