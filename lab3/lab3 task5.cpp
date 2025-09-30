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
	
	void display(){
		node* current=head;
		cout<<endl;
		while(current!=nullptr){
			cout<<current->data<<"->";
			current=current->Next;
		}
		cout<<"NULL";
	}
	void isPalindrome(){
		linkedList pl;
		node* current=head;
		while (current!=nullptr){
			pl.addNode_front(current->data);
			current=current->Next;
		}
		current=head;
		node* current2=pl.head;
		while(current!=nullptr){
			if(current->data==current2->data){
			current=current->Next;
			current2=current2->Next;
			}
			else{
				cout<<"not a palindrome";
				return;
			}
		}
		cout<<"the linked list is a palindrome";
		
	}
};

int main(){
	linkedList l1;
	l1.addNode_end(1);
	l1.addNode_end(2);
	l1.addNode_end(0);
	l1.addNode_end(2);
	l1.addNode_end(1);
	l1.isPalindrome();
}
