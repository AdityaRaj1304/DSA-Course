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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = getSize(headA);
        int n = getSize(headB);
        ListNode* ptr1=headA,*ptr2=headB;
        while(m>n){
            ptr1=ptr1->next;
            m--;
        }
        while(m<n){
            ptr2=ptr2->next;
            n--;
        }
        while(ptr1 && ptr2 && ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1;
    }
    int getSize(ListNode *head){
        int sz =0 ;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
};