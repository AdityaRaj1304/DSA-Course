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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>Q;
        Q.push(root);
        Q.push(NULL);
        vector<int>temp;
        while(!Q.empty()){
            TreeNode *curr = Q.front();
            Q.pop();
            if(curr==NULL){
                ans.push_back(temp);
                temp.clear();
                if(Q.empty()){
                    break;
                }
                Q.push(NULL);
            }else{
                temp.push_back(curr->val);
                if(curr->left!=NULL){
                    Q.push(curr->left);
                }
                if(curr->right!=NULL){
                    Q.push(curr->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};