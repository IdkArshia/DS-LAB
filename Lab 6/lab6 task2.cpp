#include<iostream>
#include<string>
using namespace std;

class node{
	public:
	string val;
	node* next;
	node(string v){
		val= v;
		next=nullptr;
	}
};

class stack{
	public:
	node* top=nullptr;
	void push(string val){
		node* newNode=new node(val);
		newNode->next=top;
		top=newNode;
		cout<<"current website: "<<val<<endl;
	}
	void pop(){
		if(top==nullptr){
			cout<<"stack is empty";
		}
		else{
			node* temp=top;
			top=top->next;
			delete temp;
			cout<<"current website: "<<top->val<<endl;
		}
	}
};
int main(){
	stack searchHistory;
	searchHistory.push("google");
	searchHistory.push("twitter");
	searchHistory.push("facebook");
	searchHistory.push("linkedin");
	searchHistory.push("Instagram");
	cout<<"going back\n";
	searchHistory.pop();
	searchHistory.pop();
	
}