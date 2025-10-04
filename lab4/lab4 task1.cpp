#include<iostream>
using namespace std;
void selection_sort(int n,int arr[]){
	int min,temp;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
	}
}
int main(){
	int arr[10];
	cout<<"enter 10 elements: ";
	for(int i=0;i<10;i++)
	cin>>arr[i];
	selection_sort(10,arr);
	cout<<"smallest 4 numbers are: ";
	for(int i=0;i<4;i++){
		cout<<arr[i]<<" ";
	}
}