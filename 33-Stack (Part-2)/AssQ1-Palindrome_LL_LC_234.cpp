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
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        ListNode* temp = head;
        while(temp){
            s.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(s.top()!=temp->val){
                return false;
            }else{
                s.pop();
            }
            temp=temp->next;
        }
        return true;
    }
};