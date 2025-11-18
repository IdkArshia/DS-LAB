#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class BST{
    public:
    Node* root=nullptr;

    Node* insert(Node* r,int val){
        if(r==nullptr){
            return new Node(val);
        }
        if(val<r->data){
            r->left=insert(r->left,val);
        }
        else if(val>r->data){
            r->right=insert(r->right,val);
        }
        return r;
    }

    int countNodes(Node* r){
        if(r==nullptr){
            return 0;
        }
        return 1+countNodes(r->left)+countNodes(r->right);
    }

    void inorderFind(Node* r,int &count,int target,int &result){
        if(r==nullptr){
            return;
        }
        inorderFind(r->left,count,target,result);
        count++;
        if(count==target){
            result=r->data;
            return;
        }
        inorderFind(r->right,count,target,result);
    }

    double findMedian(Node* r){
        int n=countNodes(r);
        if(n==0){
            return 0;
        }
        if(n%2==1){
            int target=(n+1)/2;
            int count=0,result=0;
            inorderFind(r,count,target,result);
            return result;
        }
        else{
            int t1=n/2;
            int t2=t1+1;
            int c=0,r1=0,r2=0;
            inorderFind(r,c,t1,r1);
            c=0;
            inorderFind(r,c,t2,r2);
            return (r1+r2)/2.0;
        }
    }
};

int main(){
    BST bst;
    bst.root=bst.insert(bst.root,50);
    bst.root=bst.insert(bst.root,30);
    bst.root=bst.insert(bst.root,70);
    bst.root=bst.insert(bst.root,20);
    bst.root=bst.insert(bst.root,40);
    bst.root=bst.insert(bst.root,60);
    bst.root=bst.insert(bst.root,80);

    double med=bst.findMedian(bst.root);
    cout<<"Median: "<<med;

    return 0;
}
