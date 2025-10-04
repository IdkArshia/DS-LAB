#include<iostream>
using namespace std;
bool check_dup(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n;
	cout<<"enter no. of elemets: ";
	cin>>n;
	int arr[n];
	cout<<"enter array elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<(check_dup(arr,n)?"duplicates exist":"no duplicates");
}