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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        tail->next=head;
        k%=n;
        ListNode* temp =head;
        for(int i = 1; i<n-k ;i++){
            temp=temp->next;
        }
        head = temp->next;
        temp->next=NULL;
        return head;
    }
};