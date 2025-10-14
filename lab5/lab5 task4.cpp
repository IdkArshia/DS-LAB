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
	
	bool search(node* head, int val) {
    if (head == nullptr) {
		return false;}
    bool found = search(head->next, val); 
    return head->data == val || found;
}
int main(){
	linked_list l1;
	l1.insertNode_end(1);
	l1.insertNode_end(2);
	l1.insertNode_end(3);
	if(search(l1.head,2)){
		cout<<"value found";
		
	}
	else{
		cout<<"value not found";
	}
}

