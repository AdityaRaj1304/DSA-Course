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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>s;
        ListNode *curr = head;
        while(curr){
            while(!s.empty()&&curr->val>s.top()->val){
                s.pop();
            }
            s.push(curr);
            curr=curr->next;
        }
        ListNode* tail = NULL;
        while(!s.empty()){
            curr = s.top();
            s.pop();
            curr->next=tail;
            tail=curr;
        }
        return curr;
    }
};