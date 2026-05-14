#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }else{
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }
            if(!root->left || !root->right){
                return root->left == NULL ? root->right : root->left;
            }
            TreeNode *IS = getInorderSuccessor(root->right);
            root->val=IS->val;
            root->right=deleteNode(root->right,IS->val);
        }
        return root;
    }
    TreeNode *getInorderSuccessor(TreeNode *root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
};