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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>nodes1,nodes2;
        dfs(root1,nodes1);
        dfs(root2,nodes2);
        int m = nodes1.size() , n = nodes2.size();
        if(m!=n){
            return false;
        }
        for(int i = 0 , j =0 ;i <m && j<n;i++,j++){
            if(nodes1[i]!=nodes2[j]){
                return false;
            }
        }
        return true;
    }
    void dfs(TreeNode *root,vector<int>&nodes){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            nodes.push_back(root->val);
        }
        dfs(root->left,nodes);
        dfs(root->right,nodes);
    }
};