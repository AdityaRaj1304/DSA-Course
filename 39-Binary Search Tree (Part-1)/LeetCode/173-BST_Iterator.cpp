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

class BSTIterator {
public:
    vector<int>val;
    int idx = 0;

    void inorder(TreeNode* root , vector<int>&val){
        if(!root){
            return;
        }
        if(root->left){
            inorder(root->left,val);
        }
        val.push_back(root->val);
        if(root->right){
            inorder(root->right,val);
        }
    }


    BSTIterator(TreeNode* root) {
        inorder(root,val);
    }
    
    int next() {
        int data = val[idx];
        idx++;
        return data;
    }
    
    bool hasNext() {
        if(idx>=val.size()){
            return false;
        }
        return true;
    }
};
