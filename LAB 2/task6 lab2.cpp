#include<iostream>
using namespace std;

int main(){
	int rows;
	cout<<"enter no. of rows: ";
	cin>>rows;
	int size[rows];
	string ** arr=new string*[rows];
	for(int i=0;i<rows;i++){
		cout<<"enter no. of seats for row "<<i+1<<": ";
		cin>>size[i];
	} 
	for(int i=0;i<rows;i++){
		for(int j=0;j<size[i];j++){
			arr[i]=new string[size[i]];
		}
	}
	
	for(int i=0;i<rows;i++){
		cout<<"enter names for row no."<<i+1<<" ("<<size[i]<<" seats): \n";
		for(int j=0;j<size[i];j++){
			cout<<"seat"<<j+1<<": ";
			cin>>arr[i][j];
			
		}
	}
	
	for(int i=0;i<rows;i++){
		cout<<"\nrow "<<i+1<<endl;
		for (int j=0;j<size[i];j++){
			cout<<"seat"<<j+1<<": "<<arr[i][j]<<endl;
		}
	}
}