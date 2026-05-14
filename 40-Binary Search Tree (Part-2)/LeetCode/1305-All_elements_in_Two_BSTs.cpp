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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1,tree2,sorted;
        getInorder(root1,tree1);
        getInorder(root2,tree2);
        int i = 0 , j = 0;
        while(i<tree1.size() && j<tree2.size()){
            if(tree1[i]<tree2[j]){
                sorted.push_back(tree1[i++]);
            }else{
                sorted.push_back(tree2[j++]);
            }
        }
        while(i<tree1.size()){
            sorted.push_back(tree1[i++]);
        }
        while(j<tree2.size()){
            sorted.push_back(tree2[j++]);
        }
        return sorted; 
    }

    void getInorder(TreeNode* root , vector<int>&arr){
        if(!root){
            return ;
        }
        getInorder(root->left,arr);
        arr.push_back(root->val);
        getInorder(root->right,arr);
    }
};