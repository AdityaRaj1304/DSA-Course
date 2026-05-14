#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* node = dummy;
        inorder(root,node);
        return dummy->right;
    }

    void inorder(TreeNode* root, TreeNode*& node){
        if(!root){
            return;
        }
        inorder(root->left,node);
        node->right = new TreeNode(root->val);
        node= node->right;
        inorder(root->right,node);
    }
};


// SLightly Better Approach 

class Solution {
public:
    TreeNode* curr;

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        curr = dummy;

        inorder(root);

        return dummy->right;
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        curr->right = new TreeNode(root->val);
        curr = curr->right;

        inorder(root->right);
    }
};