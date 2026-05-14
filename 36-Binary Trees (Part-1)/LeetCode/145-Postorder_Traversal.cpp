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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(ans,root);
        return ans;
    }
    void postorder(vector<int>&nodes,TreeNode*root){
        if(root == NULL){
            return;
        }
        postorder(nodes,root->left);
        postorder(nodes,root->right);
        nodes.push_back(root->val);
    }
};