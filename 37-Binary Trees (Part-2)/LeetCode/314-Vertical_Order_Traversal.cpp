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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>Q;
        map<int,vector<int>>m;
        Q.push(make_pair(root,0));
        while(!Q.empty()){
            pair<TreeNode*,int>curr = Q.front();
            Q.pop();
            TreeNode *currNode = curr.first;
            int currHD = curr.second;
            m[currHD].push_back(currNode->val);
            if(currNode->left!=NULL){
                pair<TreeNode*,int>left = make_pair(currNode->left,currHD-1);
                Q.push(left);
            }
            if(currNode->right!=NULL){
                pair<TreeNode*,int>right =  make_pair(currNode->right,currHD+1);
                Q.push(right);
            }
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};