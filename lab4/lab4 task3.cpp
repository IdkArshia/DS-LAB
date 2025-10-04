#include<iostream>
#include<string>
using namespace std;
int main(){
	string arr[5]={"banana","apple","cherry","date","grape"};
	int n=5;
	string temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j][0]>arr[j+1][0]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}