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


//My Approach -  Works fine but it doesnt stop when kth element is found
class Solution {
public:
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        inorder(root,counter,k);
        return ans;
    }
    void inorder(TreeNode* root , int &counter,int k){
        if(!root){
            return ;
        }
        inorder(root->left,counter,k);
        counter++;
        if(counter==k){
            ans=root->val;
        }
        inorder(root->right,counter,k);
    }
};

// Right Optimal Solution
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        return inorder(root, counter, k);
    }

    int inorder(TreeNode* root, int &counter, int k) {
        if (!root) return -1;

        int left = inorder(root->left, counter, k);
        if (left != -1) return left;  // ✅ already found

        counter++;
        if (counter == k) return root->val;

        return inorder(root->right, counter, k);
    }
};