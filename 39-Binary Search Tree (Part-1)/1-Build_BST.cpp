#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data ;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node *insert(Node *root ,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){  //left subtree
        root->left=insert(root->left,val);
    }else{ //right subtree
        root->right=insert(root->right,val);    
    }
    return root;
}

Node *buildBST(int arr[] ,int n){
    Node *root = NULL;
    for(int i = 0 ;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node *root , int val){
    if(root == NULL){ // Not Found
        return false;
    }
    if(root->data == val){  //FOUND
        return true;
    }else if(root->data>val){  // left Subtree
        return search(root->left,val);
    }else{ //right Subtree
        return search(root->right,val);    
    }
}



int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node *root = buildBST(arr,6);
    inorder(root);
    cout << endl;
    int arr2[9]= {8,5,3,1,4,6,10,11,14};
    Node *root2 = buildBST(arr2,9);
    inorder(root2);
    cout << endl;
    cout << search(root,3) << endl;
    cout << search(root,8);
    return 0;
}