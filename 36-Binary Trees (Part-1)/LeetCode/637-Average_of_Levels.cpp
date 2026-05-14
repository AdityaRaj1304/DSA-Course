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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>Q;
        Q.push(root);
        Q.push(NULL);
        double sum = 0.0;
        int n = 1;
        int next = 0;
        while(!Q.empty()){
            TreeNode *curr = Q.front();
            Q.pop();
            if(curr==NULL){
                ans.push_back(sum/double(n));
                sum=0;
                n=next;
                next=0;
                if(Q.empty()){
                    break;
                }
                Q.push(NULL);
            }else{
                sum+=curr->val;
                if(curr->left!=NULL){
                    Q.push(curr->left);
                    next++;
                }
                if(curr->right!=NULL){
                    Q.push(curr->right);
                    next++;
                }
            }
        }
        return ans;
    }
};