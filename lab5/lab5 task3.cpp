#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data=val;
			next=nullptr;
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
			tail=newNode;
		}
	}
};
	
int count(node* head, int c){
	if(head==nullptr){
		return c;
	}
	return count(head->next,c+1);
}
	
int main(){
	linked_list l1;
	l1.insertNode_end(1);
	l1.insertNode_end(2);
	l1.insertNode_end(3);
	int len=count(l1.head,0);
	cout<<"length: "<<len;
}	