#include<iostream>
#include<string>
using namespace std;
int front=-1, rear=-1;
string arr[1];

bool isFull(){
	return (rear==0);
}
bool isEmpty(){
	return (front==-1 || front>rear);
}
void enqueue(string msg){
	if(isFull()){
		cout<<"queue is full, only process one message at a time\n";
		return;
	}
	if(front==-1){
		front=0;
	}
	arr[++rear]=msg;
	cout<<"enqueued: "<<msg<<endl;
}

void dequeue(){
	if(isEmpty()){
		cout<<"queue is empty cannot dequeue";
		return ;
	}
	else{
		cout<<"message processed: "<<arr[front++]<<endl;
		front=-1;
		rear=-1;
	}
}
int main(){
	enqueue("hi");
	enqueue("how are you doing");
	dequeue();
	enqueue("how are you doing");
}