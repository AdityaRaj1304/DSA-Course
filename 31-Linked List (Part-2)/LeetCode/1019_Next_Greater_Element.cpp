#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) { // Very bad solution TC = O(n^2) can be solved using stack in O(n)
        vector<int>ans;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode*temp = curr->next;
            while(temp!=NULL){
                if(temp->val>curr->val){
                    ans.push_back(temp->val);
                    break;
                }else{
                    temp=temp->next;
                }
            }
            if(temp==NULL){
                ans.push_back(0);
            }
            curr=curr->next;
        }
        return ans;
    }
};