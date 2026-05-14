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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left =head;
        for(int i = 1 ;i<k;i++){
            left=left->next;
        }
        ListNode*right=KthnodefromEnd(head,k);
        swap(left->val,right->val);
        return head;
    }
    int getSize(ListNode* head){
        int sz = 0;
        ListNode* curr = head;
        while(curr){
            sz++;
            curr=curr->next;
        }
        return sz;
    }
    ListNode* KthnodefromEnd(ListNode*head,int k){
        int size = getSize(head);
        ListNode* temp =head;
        for(int i = 0 ; i<size-k;i++){
            temp=temp->next;
        }
        return temp;
    }
};

// Optimised Code 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        
        // Move left to kth node from start
        for(int i = 1; i < k; i++){
            left = left->next;
        }
        
        ListNode* first = left;     // save kth node from start
        ListNode* right = head;     // will become kth from end
        
        // Move left to end, right follows
        while(left->next){
            left = left->next;
            right = right->next;
        }
        
        swap(first->val, right->val);
        return head;
    }
};
