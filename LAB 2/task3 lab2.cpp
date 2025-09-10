#include<iostream>
using namespace std;

int main(){
	int rows;
	int highest,lowest,total;
	float avg;
	cout<<"enter no. of departments: ";
	cin>>rows;
	int **arr=new int*[rows];
	int size[rows];
	
	for (int i=0; i<rows;i++){
		cout<<"enter no. of students in department "<<i+1<<": ";
		cin>>size[i];
		arr[i]=new int[size[i]];
	}
	
	for(int i=0;i<rows;i++){
		cout<<"enter marks of "<<size[i]<<" students of department "<<i+1<<":\n";
		for(int j=0;j<size[i];j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<rows;i++){
		highest=0;
		lowest=100;
		total=0;
		for( int j=0;j<size[i];j++){
			if(arr[i][j]>highest){
				highest=arr[i][j];
			}
			if(arr[i][j]<lowest){
				lowest=arr[i][j];
			}
			total=total+arr[i][j];
		}
		cout<<"department "<<i+1<<":\n";
		cout<<"highest: "<<highest<<endl;
		cout<<"lowest: "<<lowest<<endl;
		cout<<"average: "<<total/size[i]<<endl<<endl;
	}
}