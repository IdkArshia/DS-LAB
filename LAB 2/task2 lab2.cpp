#include<iostream>
using namespace std;

int main(){
	float avg;
	int avgt,total;
	int highest=0;
	int topper;
	int** marks=new int*[5];
	for(int i=0; i<5;i++){
		marks[i]=new int[4];
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			cout<< "enter marks of subject "<<j+1<<" for student "<<i+1<<": ";
			cin>>marks[i][j];
		}
		cout<<endl;
	}
	cout<<"\n\n";
	for(int i=0; i<5;i++){
		total=0;
		for(int j=0;j<4;j++){
			total=total+marks[i][j];
		}
		if(total>highest){
			highest=total;
			topper=i+1;
		}
		cout<<"total marks of student "<<i+1<<" is: "<<total<<endl;	
	}
	cout<<"\n";
	cout<<"the topper student is student "<<topper<<endl;
	cout<<"\n";
	for(int i=0;i<4;i++){
		avg=0;
		avgt=0;
		for(int j=0;j<5;j++){
			avgt=avgt+marks[j][i];
		}
		avg=avgt/5;
		cout<<"average marks of subject "<< i+1 <<" are: "<<avg<<endl;
	}
	
}