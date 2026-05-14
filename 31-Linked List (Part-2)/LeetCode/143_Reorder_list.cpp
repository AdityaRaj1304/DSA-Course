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
    void reorderList(ListNode* head) {
        ListNode* left = head;
        ListNode* right = reverse(splitAtMid(head));
        ListNode* tail = right;
        while(left && right){
            ListNode *nextLeft = left->next;
            ListNode* nextRight =right->next;
            left->next=right;
            right->next=nextLeft;
            tail=right;
            left=nextLeft;
            right = nextRight;
        }
        if(right){
            tail->next=right;
        }
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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode * next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};