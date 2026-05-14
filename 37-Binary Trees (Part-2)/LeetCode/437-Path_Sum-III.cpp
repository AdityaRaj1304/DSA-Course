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
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        int ans = 0;
        helper(root,targetSum,ans);
        int left = pathSum(root->left,targetSum);
        int right = pathSum(root->right,targetSum);
        return ans + left + right;
    }
    void helper(TreeNode *root ,long long targetSum , int &ans){
        if(root == NULL){
            return;
        }
        targetSum-=root->val;
        if(targetSum == 0){
            ans++;
        }
        helper(root->left,targetSum,ans);
        helper(root->right,targetSum,ans);
        targetSum+=root->val;
    }
};