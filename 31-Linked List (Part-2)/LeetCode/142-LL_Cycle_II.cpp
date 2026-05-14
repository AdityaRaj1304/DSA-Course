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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head , *fast =head;
        bool ans = false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ans = true;
                break;
            }
        }
        if(ans){
            fast=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
        return NULL;
    }
};