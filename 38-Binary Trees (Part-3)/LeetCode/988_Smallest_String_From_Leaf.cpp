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


//Method-1 (My Approach) - Good but Not Optimal
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string>comb;
        string s;
        helper(root,s,comb);
        sort(comb.begin(),comb.end());
        string ans = comb[0];
        return ans;
    }
    void helper(TreeNode *root , string s , vector<string>&comb){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right == NULL){
            s.push_back(root->val+'a');
            reverse(s.begin(),s.end());
            comb.push_back(s);
        }else{
            s.push_back(root->val+'a');
            helper(root->left,s,comb);
            helper(root->right,s,comb);
        }
    }
};

class Solution {
public:
    string ans ="~";
    string smallestFromLeaf(TreeNode* root) {
        string s;
        helper(root,s);
        return ans;
    }
    void helper(TreeNode *root , string &s){
        if(root==NULL){
            return ;
        }
        s.push_back(root->val+'a');
        if(root->left==NULL && root->right == NULL){
            string temp = s;
            reverse(temp.begin(),temp.end());
            if(temp<ans){
                ans=temp;
            }
        }
        helper(root->left,s);
        helper(root->right,s);
        s.pop_back();
    }
};