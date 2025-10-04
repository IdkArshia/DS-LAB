#include<iostream>
using namespace std;
void binary_search(string val,string arr[], int n){
	int count=0;
	int left=0;
	int right=n-1;
	while(left<=right){
		count++;
		int mid=(left+right)/2;
		if(arr[mid]==val){
			cout<<val<<" found at index "<<mid<<" after "<<count<<" steps\n";
			return;
		}
		else if(arr[mid]>val){
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	cout<<val<<" not found after "<<count<<" steps\n";
	return;
}
void linearSearch(string val,string arr[],int n){
	int count=0;
	for(int i=0;i<n;i++){
		count++;
		if(arr[i]==val){
			cout<<val<<" found at index "<<i<<" after "<<count<<" steps\n";
			return;
		}
	}
	cout<<val<<" not found after "<<count<<" steps\n";
	return;
}
int main(){
	string arr[]={"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
	cout<<"Binary Search:\n";
	binary_search("Aftab",arr,10);
	binary_search("Rizwan",arr,10);
	binary_search("Tariq",arr,10);
	cout<<"\nLinear Search:\n";
	linearSearch("Aftab",arr,10);
	linearSearch("Rizwan",arr,10);
	linearSearch("Tariq",arr,10);
	
	cout<<"\n\nbinary search is better as it takes less steps";
}