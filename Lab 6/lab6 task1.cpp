#include<iostream>
#include<string>
using namespace std;

struct Node{
	string data;
	Node* next;
	Node(string val){
		data=val;
		next= nullptr;
	}
};

class stack{
	Node* top;
	public:
		stack(){
			top=nullptr;
		}
		void push(string val){
			Node* newNode = new Node(val);
			newNode->next=top;
			top=newNode;
			cout<< val <<" added to the todo list\n";
		}
		void pop(){
			if(top==nullptr){
				cout<<"list is empty\n"<<endl;
				return;
			}
			else{
				cout<<endl<<top->data<<" popped from the stack\n";
				Node* temp=top;
				top=top->next;
				delete temp;
			}
		}
		bool isEmpty(){
			return top==nullptr;
		}
		void display(){
			Node*temp=top;
			cout<<"\ncurrent list:\n";
			while(temp!=nullptr){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
		
};
int main(){
	stack todo_list;
	todo_list.push("Send Mails");
	todo_list.push("do Assignment 6");
	todo_list.push("Study for quiz");
	todo_list.display();
	todo_list.pop();
	todo_list.display();
}