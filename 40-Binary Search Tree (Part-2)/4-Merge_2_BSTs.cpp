#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left ;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void getInorder(Node* root, vector<int>&arr){
    if(!root){
        return ;
    }
    getInorder(root->left,arr);
    arr.push_back(root->data);
    getInorder(root->right,arr);
}

Node* BSTfromVec(vector<int>arr , int st , int end){
    while(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left=BSTfromVec(arr,st,mid-1);
    curr->right=BSTfromVec(arr,mid+1,end);
    return curr;
}

Node* mergeBSTs(Node* root1 , Node* root2){
    vector<int>nodes1 , nodes2;
    vector<int>sorted;

    getInorder(root1,nodes1);
    getInorder(root2,nodes2);

    int i = 0 , j= 0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i]<nodes2[j]){
            sorted.push_back(nodes1[i++]);
        }else{
            sorted.push_back(nodes2[j++]);
        }
    }
    while(i<nodes1.size()){
        sorted.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        sorted.push_back(nodes2[j++]);
    }
    
    return BSTfromVec(sorted,0,sorted.size()-1);
}


void preorder(Node* root){
    if(!root){
        return;
    }
    cout << root->data << " " ;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    Node* root2 = new Node(9);
    root2->left = new Node(4);
    root2->right = new Node(12);

    Node* root = mergeBSTs(root1,root2);
    preorder(root);
    return 0;
}