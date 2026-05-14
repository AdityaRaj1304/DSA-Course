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
    ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next->next){
        return head;
    }
    ListNode *odd =head;
    ListNode* even = head->next;
    ListNode* evenStart= head->next;
    while(odd->next && even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    return head;
    }
};

ListNode* oddEvenList(ListNode* head) { // Safer Version
    // length 0,1,2 → already correct
    if (!head || !head->next) {
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenStart = even;  // save start of even list

    while (even && even->next) {
        odd->next = even->next;     // link next odd
        odd = odd->next;

        even->next = odd->next;     // link next even
        even = even->next;
    }

    // attach even list after odd list
    odd->next = evenStart;

    return head;
}
