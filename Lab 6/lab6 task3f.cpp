#include<iostream>
#include<string>
using namespace std;

class node{
	public:
	char val;
	node* next;
	node(char v){
		val=v;
		next=nullptr;
	}
};

class stack{
	public:
	node* top=nullptr;
	void push(char val){
		node* newNode=new node(val);
		newNode->next=top;
		top=newNode;
	}
	char pop(){
		if(top==nullptr){
			cout<<"stack is empty"<<endl;
			return '\0';
		}else{
			node* temp=top;
			char ret=top->val;
			top=top->next;
			delete temp;
			return ret;
		}
	}
	bool isEmpty(){
		return top==nullptr;
	}
	char peek(){
		if(top==nullptr){
			cout<<"stack is empty"<<endl;
			return '\0';
		}else{
			return top->val;
		}
	}
};

bool isAlphaNumeric(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))return true;
	return false;
}

int getPrecedence(char c){
	if(c=='^')return 3;
	else if(c=='*'||c=='/')return 2;
	else if(c=='+'||c=='-')return 1;
	else return -1;
}

string infixToPrefix(string infix){
	string prefix="";
	stack st;
	for(int i=infix.length()-1;i>=0;i--){
		char c=infix[i];
		if(isAlphaNumeric(c)){
			prefix=c+prefix;
		}else if(c==')'){
			st.push(c);
		}else if(c=='('){
			while(!st.isEmpty()&&st.peek()!=')'){
				prefix=st.pop()+prefix;
			}
			if(!st.isEmpty())st.pop();
		}else{
			while(!st.isEmpty()&&getPrecedence(st.peek())>=getPrecedence(c)){
				prefix=st.pop()+prefix;
			}
			st.push(c);
		}
	}
	while(!st.isEmpty()){
		prefix=st.pop()+prefix;
	}
	return prefix;
}

int main(){
	string infix="a+b*(x^d-e)^(f+g*h)-i";
	cout<<"Infix: "<<infix<<endl;
	cout<<"Prefix: "<<infixToPrefix(infix)<<endl;
}
