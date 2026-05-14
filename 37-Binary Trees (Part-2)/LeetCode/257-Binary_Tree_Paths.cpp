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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<string>ans;
        string s;
        helper(root,s,ans);
        return ans;
    }
    void helper(TreeNode*root,string s , vector<string>&ans){
        if(root==NULL){
            return ;
        }
        s+=to_string(root->val);
        if(root->left== NULL && root->right==NULL){
            ans.push_back(s);
        }
        s+="->";
        helper(root->left,s,ans);
        helper(root->right,s,ans);
    }
};