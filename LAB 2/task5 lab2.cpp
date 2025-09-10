#include<iostream>
using namespace std;

int main(){
	float ** arr=new float*[4];
	int cc[4]={3,4,2,1};
	for(int i=0;i<4;i++){
		arr[i]=new float[cc[i]];
	}
	string dept[4]={"Softwere engineering","Artificial Intelligence","Computer Science","Data Science"};
	
	for(int i=0;i<4;i++){
		cout<<"enter gpa for "<<dept[i]<<" department ("<<cc[i]<<" corses): \n";
		for(int j=0;j<cc[i];j++){
			cout<<"course "<<j+1<<": ";
			cin>>arr[i][j];
		}
	}
	for (int i=0;i<4;i++){
		cout<<"\n gpa for "<<dept[i]<<" department: \n";
		for(int j=0;j<cc[i];j++){
			cout<<"course "<<j+1<<": "<<arr[i][j]<<endl;
		}
		
	}
}