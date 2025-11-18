#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node* insertNode(Node *root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val < root->data){
        root->left = insertNode(root->left,val);
    }
    else{
        root->right = insertNode(root->right,val);
    }
    return root;
}

int countInRange(Node *root,int a,int b){
    if(root==NULL){
        return 0;
    }
    int c=0;
    if(root->data>=a && root->data<=b){
        c=1;
    }
    if(a < root->data){
        c+=countInRange(root->left,a,b);
    }
    if(b > root->data){
        c+=countInRange(root->right,a,b);
    }
    return c;
}

int main(){
    Node *root=NULL;
    int arr[]={10,5,1,7,40,50};
    int n=6;
    for(int i=0;i<n;i++){
        root=insertNode(root,arr[i]);
    }
    int a=5,b=45;
    int r=countInRange(root,a,b);
    cout<<"Nodes in range ["<<a<<","<<b<<"] = "<<r;
    return 0;
}
