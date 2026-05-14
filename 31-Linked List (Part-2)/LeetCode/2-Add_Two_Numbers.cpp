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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode *curr = head;
        int sum = 0 , carry = 0;
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr = curr->next;
            l1=l1->next ,l2=l2->next;
        }
        while(l1){
            sum=l1->val+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr = curr->next;
            l1=l1->next;
        }
        while(l2){
            sum=l2->val+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr = curr->next;
            l2=l2->next;
        }
        while(carry){
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};


//Short but Same Approach

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode *curr = head;
        int sum = 0 , carry = 0;
        while(l1 || l2 || carry){
            sum = carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr = curr->next;
        }
        return head->next;
    }
};