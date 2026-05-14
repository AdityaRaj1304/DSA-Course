#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

static int idx = -1;

Node *buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right =buildTree(nodes);

    return currNode;
}

void kth_helper(Node *root, int k , int currLevel){
    if(root == NULL){
        return;
    }
    if(currLevel==k){
        cout << root->data << " ";
        return ;
    }
    kth_helper(root->left,k,currLevel+1);
    kth_helper(root->right,k,currLevel+1);
}

void kthLevel(Node *root , int k){
    kth_helper(root,k,1);
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    kthLevel(root,3);
    return 0;
}