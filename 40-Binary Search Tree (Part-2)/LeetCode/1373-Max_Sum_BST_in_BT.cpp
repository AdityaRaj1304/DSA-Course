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


class Info{
public:
    bool isBST;
    int min ;
    int max;
    int sum;

    Info(bool isBST , int min , int max , int sum){
        this->isBST=isBST;
        this->min=min;
        this->max=max;
        this->sum=sum;
    }
};


class Solution {
public:
    int maxSum = 0;
    Info* dfs(TreeNode* root){
        if(root==NULL){
            return new Info(true,INT_MAX,INT_MIN,0);
        }

        Info* leftInfo = dfs(root->left);
        Info* rightInfo = dfs(root->right);

        int currMin = min(root->val,min(leftInfo->min,rightInfo->min));
        int currMax = max(root->val,max(leftInfo->max,rightInfo->max));
        int currSum = leftInfo->sum + rightInfo->sum + root->val;

        if(leftInfo->isBST && rightInfo->isBST && root->val>leftInfo->max && root->val<rightInfo->min){
            maxSum=max(maxSum,currSum);
            return new Info(true,currMin,currMax,currSum);
        }
        return new Info(false,0,0,0);
}
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};




//Better Approach - No Memory Leak using Object Not Pointer

class Info {
public:
    bool isBST;
    int min, max, sum;

    Info(bool isBST, int min, int max, int sum)
        : isBST(isBST), min(min), max(max), sum(sum) {}
};

class Solution {
public:
    int maxSum = 0;

    Info dfs(TreeNode* root) {
        if (!root) {
            return Info(true, INT_MAX, INT_MIN, 0);
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.max &&
            root->val < right.min) {

            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return Info(
                true,
                min(root->val, left.min),
                max(root->val, right.max),
                currSum
            );
        }

        return Info(false, 0, 0, 0);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};




