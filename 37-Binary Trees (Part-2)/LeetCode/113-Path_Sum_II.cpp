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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        vector<int>comb;
        helper(root,targetSum,comb,ans);
        return ans;
    }
    void helper(TreeNode *root ,int targetSum , vector<int>&comb , vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }
        targetSum-=root->val;
        comb.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum == 0){
            ans.push_back(comb);
        }
        helper(root->left,targetSum,comb,ans);
        helper(root->right,targetSum,comb,ans);
        targetSum+=root->val;
        comb.pop_back();
    }
};



