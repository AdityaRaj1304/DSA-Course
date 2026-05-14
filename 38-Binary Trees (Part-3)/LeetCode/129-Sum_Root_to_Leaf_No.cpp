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
    int ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        int num = 0;
        helper(root,num);
        return ans;
    }
    void helper(TreeNode *root , int num ){
        if(root==NULL){
            return;
        }
        num = num*10 + root->val;
        if(!root->left && !root->right){
            ans+=num;
        }
        helper(root->left,num);
        helper(root->right,num);
    }
};