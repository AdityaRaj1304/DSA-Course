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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return -1;
        }
        int ans = 0;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int size =Q.size();
            for(int i = 0 ;i<size;i++){
                TreeNode *curr = Q.front();
                Q.pop();
                if(i==0){
                    ans=curr->val;
                }
                if(curr->left){
                    Q.push(curr->left);
                }
                if(curr->right){
                    Q.push(curr->right);
                }
            }
        }
        return ans;
    }
};