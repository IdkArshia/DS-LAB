#include<iostream>
using namespace std;
void printb(char mat[][4],int n){
	int count=0;
	for(int i=0;i<4;i++){
	 	for(int j=0;j<4;j++){
	 		cout<<mat[i][j];
	 		(mat[i][j]=='F'?count++:count=count);
		 }
		 cout<<endl;
	 }
	 cout<<"max flags= "<<count<<endl;
}
bool isSafe(char mat[][4],int r,int c,int n){
	for(int i=0;i<n;i++){
		if(mat[r][i]=='F'){
			return false;
		}
	}
	for(int i=0;i<n;i++){
		if(mat[i][c]=='F'){
			return false;
		}
	}
	for(int i=r,j=c;i>=0 && j>=0;i--,j--){
		if(mat[i][j]=='F'){
			return false;
		}
	}
	for(int i=r,j=c;i>=0 && j<n;i--,j++){
		if(mat[i][j]=='F'){
			return false;
		}
	}
	return true;
}

void nflags(char mat[][4],int row,int n,int count){
	if(row==n){
		printb(mat,n);
		return;
	}
	else{
		for(int j=0;j<n;j++){
			if(isSafe(mat,row,j,n)){
				mat[row][j]='F';
				count++;
				nflags(mat,row+1,n,0);
				mat[row][j]='.';
			}
		}
		
	}
	
}


int main(){
	 char mat[4][4];
	 for(int i=0;i<4;i++){
	 	for(int j=0;j<4;j++){
	 		mat[i][j]='.';
		 }
	 }
	 nflags(mat,0,4,0);
}