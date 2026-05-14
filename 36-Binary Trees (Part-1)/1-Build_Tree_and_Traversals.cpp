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

//Traversals 

//1)Preorder Traversal
void preorder(Node *root){
    if(root == NULL){
        return;
    }

    cout << root->data << " " ;
    preorder(root->left);
    preorder(root->right);
}

//2)Inorder Traversal
void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//3)Postorder Traversal
void postorder(Node *root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//4.a)Level Order Traversal - Single Line Output
void levelOrder(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty()){
        Node *curr = Q.front();
        Q.pop();
        cout << curr->data << " ";
        if(curr->left!=NULL){
            Q.push(curr->left);
        }
        if(curr->right!=NULL){
            Q.push(curr->right);
        }
    }
}

//4.b)Level Order Traversal - Level Wise Output
void level_Order(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node *curr = Q.front();
        Q.pop();
        if(curr == NULL){
            cout << endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);// to track next line
        }else{
            cout << curr->data << " ";
            if(curr->left!=NULL){
                Q.push(curr->left);
            }
            if(curr->right!=NULL){
                Q.push(curr->right);
            }
        }
    }
}

//4.c)Level Order Traversal - Level Wise Output (Alternate)
void level_Order_alt(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        for(int i =0;i<size;i++){
            Node *curr = Q.front();
            Q.pop();
            cout << curr->data << " ";
            if(curr->left!=NULL){
                Q.push(curr->left);
            }
            if(curr->right!=NULL){
                Q.push(curr->right);
            }
        }
        cout << endl;
    }
}

void invertTree(Node *root){
    if(root == NULL){
        return ;
    }
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
}


int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout << "Root = " << root->data << endl ;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    level_Order(root);
    cout << endl;
    level_Order_alt(root);
    invertTree(root);
    level_Order_alt(root);
    return 0;
}
