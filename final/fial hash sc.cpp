#include<iostream>
using namespace std;
const int size=7;

class Node{
	public:
	int key;
	string val;
	Node* next;
	
	Node(string v, int k){
		val=v;
		key=k;
		next=nullptr;
	}
};

class hashTable{
	public:
	Node* table[size];
	hashTable(){
		for(int i=0;i<size;i++){
			table[i]=nullptr;
		}
	}
	
	void insert(string v, int k){
		Node *newN=new Node(v,k);
		int i=hashF(k);
		if(table[i]==nullptr){
			table[i]=newN;
			return;
		}
		else{
			Node* temp=table[i];
			while(temp->next!=nullptr){
				if(temp->key==k){
					temp->val=v;
					delete newN;
					return;
				}
				temp=temp->next;
			}
				if(temp->key==k){
					temp->val=v;
					delete newN;
					return;
				}
				else{
					temp->next=newN;
				}	
		}
	}
	
	int hashF(int key){
		return key%size;
	}
	
	void del(int key){
		int i=hashF(key);
		Node* t=table[i];
		Node* p=nullptr;
		while(t!=nullptr && t->key!=key){
			p=t;
			t=t->next;
		}
		if(t==nullptr){
			cout<<"key not found";
			return;
		}
		if(p==nullptr){
			table[i]=t->next;
		}
		else{
			p->next=t->next;
		}
		delete t;
		cout<<"key deleted"<<endl;
		return;
	}
	
	void display(){
		for(int i=0;i<size ;i++){
			if(table[i]==nullptr) continue;
			else{
				Node* temp=table[i];
				cout<<i<<":";
				while(temp!=nullptr){
					cout<<temp->key<<" "<<temp->val<<"->";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
	}
	string search(int key){
		int i=hashF(key);
		Node* temp=table[i];
		while(temp!=nullptr){
			if(temp->key==key){
				return temp->val;
				
			}
			temp=temp->next;
		}
		
			return "key not found";
	}
};
int main(){
	hashTable h;
	h.insert("arshia",2);
	h.insert("is",5);
	h.insert("gonna",4);
	h.insert("ace",3);
	h.insert("ds",1);
	h.insert("and",6);
	h.insert("other",12);
	h.insert("too",14);
	h.display();
	h.del(6);
	h.display();
	cout<<h.search(4);
}