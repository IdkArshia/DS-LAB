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
	
};
int main(){
	linkedList l1;
	int arr[5]={3,1,2,5,8};
	
	cout<<"array:"<<endl;
	
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	for(int i=0;i<5;i++){
		l1.addNode_end(arr[i]);
	}
	cout<<"\nlinked list:";
	l1.display();
	l1.addNode_end(9);
	l1.display();
	l1.insert_at_pos(11,3);
	l1.display();
	l1.addNode_front(4);
	l1.display();
	
}