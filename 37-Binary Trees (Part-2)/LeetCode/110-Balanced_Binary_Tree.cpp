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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    int height(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int leftHT = height(root->left);
        if(leftHT == -1){
            return -1;
        }
        int rightHT = height(root->right);
        if(rightHT == -1){
            return -1;
        }
        if(abs(leftHT-rightHT)>1){
            return -1;
        }
        int currHt = max(leftHT,rightHT)+1;
        return currHt;
    }
};