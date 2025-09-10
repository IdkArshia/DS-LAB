#include<iostream>
using namespace std;

class matrix{
	public:
	int rows, cols;
	int** mat=nullptr;
	void dynamic_matrix_creation(){
		cout<<" enter no. of rows: ";
		cin>>rows;
		cout<<" enter no. of columns: ";
		cin>>cols;
		int ** twod=new int* [rows];
		for(int i=0;i<rows;i++){
			twod[i]= new int[cols];
		}
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<"enter element ";
				cin>>twod[i][j];
			}
		}
		mat=twod;
		
	}
	void resize_matrix(){
		int r, c;
		cout<<"enter no. of rows for resized matrix: ";
		cin>>r;
		cout<<"enter no. of columns for resized matrix: ";
		cin>>c;
		int **newM=new int*[r];
		for(int i=0;i<r;i++){
			newM[i]=new int[c];
		}
		
		int minR =(rows<r)?rows:r;
		int minC =(cols<c)?cols:c;
		
		for(int i=0;i<minR;i++){
			for(int j=0;j<minC;j++){
				newM[i][j]=mat[i][j];	
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i>=rows || j>=cols){
					cout<<"enter new element for row "<<i+1<<" and column "<<j+1<<" : ";
					cin>>newM[i][j];
				}
			}
		}
		
		for(int i=0;i<rows;i++){
			delete[] mat[i];
		}
		delete mat;
		rows=r;
		cols=c;
		mat=newM;
	}
	
	void print_matrix(){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<mat[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	
	void transpose_matrix(){
		int tr=cols;
		int tc=rows;
		int **transM= new int*[tr];
		for(int i=0;i<tr;i++){
			transM[i]=new int[tc];
		}
		for(int i=0; i<tr;i++){
			for(int j=0; j<tc;j++){
				transM[i][j]=mat[j][i];
			}
		}
		for(int i=0; i<rows;i++){
			delete[] mat[i];
		}
		delete[] mat;
		rows=tr;
		cols=tc;
		mat=transM;
	}
	~matrix(){
		for(int i=0;i<rows;i++){
			delete[] mat[i];
		}
		delete[] mat;
		
	}
	
	
};

int main(){
	matrix m1;
	m1.dynamic_matrix_creation();
	m1.print_matrix();
	m1.resize_matrix();
	m1.print_matrix();
	m1.transpose_matrix();
	cout<<"transposed matrix: "<<endl;
	m1.print_matrix();
	for(int i=0;i<m1.rows;i++){
		for(int j=0; j<m1.cols;j++){
			if(j%2 != 0){
				m1.mat[i][j]=m1.mat[i][j]+2;
			}
		}
	}
	cout<<"after adding 2 to every odd column: \n";
	m1.print_matrix();
	
	
}