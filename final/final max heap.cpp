#include<iostream>
using namespace std;
class maxHeap{
	public:
		int capacity;
		int size;
		int *arr;
		maxHeap(int cap){
			capacity=cap;
			arr=new int[capacity];
			size=0;
		}
		
		void heapify_up(int i){
			while(i!=0){
				int parent=(i-1)/2;
				if(arr[parent]<arr[i]){
					swap(arr[parent],arr[i]);
					i=parent;
				}
				else{
					break;
				}
			}
		}
		
		void heapify_down(int i){
			while(true){
				int left=(i*2)+1;
				int right=(i*2)+2;
				int largest=i;
				if(left<size && arr[left]>arr[largest]){
					largest=left;
				}
				if(right<size && arr[right]>arr[largest]){
					largest=right;
				}
				if(largest!=i){
					swap(arr[largest],arr[i]);
					i=largest;
				}
				else{
					break;
				}
			}
		}
		
		void insert(int val){
			if(size==capacity){
				cout<<"heap is full :(";
				return;
			}
			arr[size]=val;
			heapify_up(size);
			size++;
		}
		int del(){
			if(size==0){
				cout<<"heap is empty :(";
				return 0;
			}
			int temp=arr[0];
			arr[0]=arr[size-1];
			size--;
			heapify_down(0);
			return temp;
		}
		
		void display(){
			for (int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
			
		}
};
int main(){
	maxHeap m1(5);
	m1.insert(3);
	m1.insert(2);
	m1.insert(4);
	m1.insert(7);
	m1.insert(8);
	m1.insert(4);
	m1.display();
	cout<<endl;
	while(m1.size>0){
		cout<<m1.del()<<" ";
	}
}