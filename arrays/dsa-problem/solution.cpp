#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode *left;
    treenode *right;
    treenode(int val){
        data=val;
        left=right=NULL;
    }
};
int main(){
    treenode *root=new treenode(3);
    root->left=new treenode(5);
    root->right=new treenode(8);
    cout<<root->left->data;
  



}
