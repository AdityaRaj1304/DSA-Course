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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return balancedBST(nums,0,nums.size()-1);
    }
    
    TreeNode* balancedBST(vector<int>&nums,int st , int end){
        if(st>end){
            return NULL;
        }
        int mid = st+(end-st)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left= balancedBST(nums,st,mid-1);
        curr->right = balancedBST(nums,mid+1,end);
        return curr;
    }
};