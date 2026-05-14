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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l =head, *r=head;
        for(int i = 1 ;i<=right;i++){
            if(i<left){
                l=l->next;
            }
            r=r->next;
        }
        ListNode *prev = l;
        ListNode *curr = l->next;
        while(curr!=r->next){
            ListNode *next= curr->next;
            curr->next=prev;
            prev= curr;
            curr=next;
        }
        return head;
    }
};