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

static int idx =-1;

Node* buildTree(vector<int>&nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes); //left subtree
    currNode->right = buildTree(nodes); //right subtree

    return currNode;
}

int height(Node *root){
    if(root == NULL){
        return 0 ;
    }
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right);
    int currHeight = max(leftHeight,rightHeight)+1;
    return currHeight;
}


int diam1(Node *root){ //T.C.=>O(n^2)
    if(root == NULL){
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) +1;  //O(n)
    int leftDiam = diam1(root->left);
    int rightDiam  = diam1(root->right);
    return max(currDiam,max(leftDiam,rightDiam));
}

pair<int,int> diam2(Node *root){
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int,int> leftInfo = diam2(root->left);
    pair<int,int> rightInfo = diam2(root->right);
    
    int currDiam = leftInfo.second +rightInfo.second +1;
    int finalDiam = max(currDiam , max(leftInfo.first,rightInfo.first));
    int finalHt = max(leftInfo.second , rightInfo.second) +1;

    return make_pair(finalDiam,finalHt);
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout << diam1(root);
    cout << endl;
    cout << diam2(root).first;
    return 0;
}