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

int height(Node *root){ //DFS Method - Easy 
    if(root == NULL){
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt,rightHt)+1;
    return currHt;
}

int height_bfs(Node *root){
    if(root==NULL){
        return 0;
    }
    int ht =0;
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        for(int i =0;i<size;i++){
            Node *curr = Q.front();
            Q.pop();
            if(curr->left!=NULL){
                Q.push(curr->left);
            }
            if(curr->right!=NULL){
                Q.push(curr->right);
            }
        }
        ht++;
    }
    return ht;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout << height(root)<<endl;
    cout << height_bfs(root);
    return 0;
}