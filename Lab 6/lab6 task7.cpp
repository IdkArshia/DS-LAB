#include<iostream>
#include<string>
using namespace std;
class patron{
	public:
	string name;
	patron(string n){name=n;}
	patron(){}
};
int front=-1,rear=-1;
patron arr[25];

bool isFull(){
	return (rear==24);
}
bool isEmpty(){
	return (front==-1||front>rear);
}
void enqueue(patron n){
	if(isFull()){
		cout<<"queue is full, please wait\n";
		return;
	}
	if(front==-1)front=0;
	arr[++rear]=n;
	cout<<n.name<<" joined the queue"<<endl;
}
void dequeue(){
	if(isEmpty()){
		cout<<"queue is empty, cannot dequeue\n";
		return;
	}
	cout<<arr[front].name<<" left the queue"<<endl;
	front++;
	if(front>rear){front=-1;rear=-1;}
}
int main(){
	int c;
	do{
		cout<<"\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter choice: ";
		cin>>c;
		if(c==1){
			cout<<"Enter your name: ";
			string n;cin>>n;
			patron p(n);
			enqueue(p);
		}
		else if(c==2)dequeue();
		else if(c!=3)cout<<"Invalid choice\n";
	}while(c!=3);
}
