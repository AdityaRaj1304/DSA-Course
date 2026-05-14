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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,false);
        return ans;
    }
    void dfs(TreeNode *root,bool flag){
        if(!root){
            return;
        }
        if(flag && (!root->left && !root->right)){
            ans+= root->val;
        }
        if(root->left){
            dfs(root->left,true);
        }
        if(root->right){
            dfs(root->right,false);
        }
    }
};