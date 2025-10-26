#include<iostream>
using namespace std;
int front=-1, rear=-1;
int arr[10];

bool isFull(){
	return (rear==9);
}
bool isEmpty(){
	return (front==-1 || front>rear);
}
void enqueue(int val){
	if(isFull()){
		cout<<"queue is full";
		return;
	}
	if(front==-1){
		front=0;
	}
	arr[++rear]=val;
	cout<<"enqueued: "<<val<<endl;
}

int dequeue(){
	if(isEmpty()){
		cout<<"queue is empty cannot dequeue";
		return -1;
	}
	else{
		cout<<"dequeued: ";
		return arr[front++];
	}
}

int main(){
	enqueue(13);
	enqueue(7);
	enqueue(4);
	enqueue(1);
	enqueue(6);
	enqueue(8);
	enqueue(10);
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue();
	
}