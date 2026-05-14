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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast =head;
        ListNode *slow = head;
        while(fast!=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr=head;
        ListNode *next=head->next;
        ListNode *temp =head;
        while(next!=NULL){
            if(curr->val==next->val){
                curr->next=next->next;
            }
            if(temp->val==curr->val){
                
            }
        }
    }
};