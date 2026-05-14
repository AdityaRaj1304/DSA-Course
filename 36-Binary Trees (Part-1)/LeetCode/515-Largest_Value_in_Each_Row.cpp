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
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int>ans;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int maximum = INT_MIN;
            int size = Q.size();
            for(int i = 0 ;i<size;i++){
                TreeNode *curr = Q.front();
                Q.pop();
                maximum=max(maximum,curr->val);
                if(curr->left!=NULL){
                    Q.push(curr->left);
                }
                if(curr->right!=NULL){
                    Q.push(curr->right);
                }
            }
            ans.push_back(maximum);
        }
        return ans;
    }
};