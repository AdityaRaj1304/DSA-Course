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
    ListNode* sortList(ListNode* head) {
       if(head==NULL || head->next==NULL){
        return head;
       } 
       ListNode *rightHead =splitAtMid(head);
       ListNode *left = sortList(head);
       ListNode *right = sortList(rightHead);
       return merge(left,right);
    }
    ListNode* splitAtMid(ListNode* head){
        ListNode *prev = NULL ;
        ListNode *fast =head , *slow = head; 
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right) {
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        ListNode *head = NULL , *tail =NULL;
        if(left->val<=right->val){
            head=tail=left;
            left=left->next;
        }else{
            head=tail=right;
            right=right->next;
        }
        while(left && right){
        if(left->val<=right->val){
            tail->next=left;
            left=left->next;
        }else{
            tail->next=right;
            right=right->next;
        }
        tail=tail->next;
        }
        tail->next = (left)?left:right;
        return head;
    }  
};