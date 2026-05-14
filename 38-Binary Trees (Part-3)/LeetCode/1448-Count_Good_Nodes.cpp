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
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return ans;
    }
    void dfs(TreeNode *root , int maximum){
        if(!root){
            return;
        }
        if(root->val>=maximum){
            maximum= root->val;
            ans++;
        }
        dfs(root->left,maximum);
        dfs(root->right,maximum);
    }
};