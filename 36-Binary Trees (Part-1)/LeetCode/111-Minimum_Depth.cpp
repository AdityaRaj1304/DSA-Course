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
    int minDepth(TreeNode* root) {
        if(root->left == NULL && root->right==NULL){
            return 1;
        }
        int left = INT_MAX , right = INT_MAX;
        
        left = 1+minDepth(root->left);
        right = 1+minDepth(root->right);
        return min(left,right);
    }
};