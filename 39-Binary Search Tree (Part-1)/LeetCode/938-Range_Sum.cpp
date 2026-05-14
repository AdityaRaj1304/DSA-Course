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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        if(!root){
            return 0;
        }
        if(low<=root->val && root->val<=high){
            ans+=rangeSumBST(root->left,low,high);
            ans+=root->val;
            ans+=rangeSumBST(root->right,low,high);
        }else if(root->val<low){
            ans+=rangeSumBST(root->right,low,high);
        }else{
            ans+=rangeSumBST(root->left,low,high);
        }
        return ans;
    }
};


class Solution { // Better Written 
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        if(!root){
            return 0;
        }
        if(low<=root->val && root->val<=high){
            ans+= root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }else if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }else{
            return rangeSumBST(root->left,low,high);
        }
        return ans;
    }
};




