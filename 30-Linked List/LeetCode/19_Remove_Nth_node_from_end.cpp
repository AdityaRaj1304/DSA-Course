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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        ListNode *prev = head;
        if(n==size){
            ListNode *temp =head;
            head=head->next;
            delete temp;
            return head;
        }
        for(int i = 1 ; i<size-n;i++){
            prev=prev->next;
        }
        ListNode *toDel = prev->next;
        prev->next=prev->next->next;
        delete toDel;
        return head;
    }
    int getSize(ListNode *head){
        ListNode *temp =head;
        int sz=0;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
};