#include<iostream>
using namespace std;

int main(){
	bool ** arr=new bool*[5];
	for(int i=0;i<5;i++){
		arr[i]=new bool[5];
	}
	arr[0][0]=false;
	arr[0][1]=true;
	arr[0][2]=false;
	arr[0][3]=true;
	arr[0][4]=true;
	
	arr[1][0]=true;
	arr[1][1]=false;
	arr[1][2]=true;
	arr[1][3]=false;
	arr[1][4]=true;
	
	arr[2][0]=false;
	arr[2][1]=true;
	arr[2][2]=false;
	arr[2][3]=false;
	arr[2][4]=false;
	
	arr[3][0]=true;
	arr[3][1]=false;
	arr[3][2]=false;
	arr[3][3]=false;
	arr[3][5]=true;
	
	arr[4][0]=true;
	arr[4][1]=true;
	arr[4][2]=false;
	arr[4][3]=true;
	arr[4][4]=false;
	
	int num1,num2;
	cout<<"enter 2 numbers to find out if they have common friends: ";
	cin>>num1>>num2;
	bool fr=false;
	for(int i=0;i<5;i++){
		if(arr[num1][i] && arr[num2][i]){
			cout<< "they have "<<i<<" as a common friend"<<endl;
			fr=true;
		}
	
	}
		if(fr==false){
			cout<<"no common friends";
		}
	
	
}