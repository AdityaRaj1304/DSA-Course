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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* left = list1 , *right = list2;
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
        }q
        tail->next = (left)?left:right;
        return head;
    }
};