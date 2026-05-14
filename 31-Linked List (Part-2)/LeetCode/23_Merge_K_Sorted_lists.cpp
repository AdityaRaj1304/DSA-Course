#include<bits/stdc++.h> // My Approach Works 100% 
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
    ListNode*mergeKLists(vector<ListNode*>& lists) {
        vector<int>temp;
        for(int i = 0 ;i<lists.size();i++){
            ListNode* head  = lists[i];
            while(head){
                temp.push_back(head->val);
                head=head->next;
            }
        }
        if(temp.empty()) return NULL;
        sort(temp.begin(),temp.end());
        ListNode* h = new ListNode(temp[0]);
        ListNode*tail=h;
        for(int i =1 ;i<temp.size();i++){
            tail->next=new ListNode(temp[i]);
            tail=tail->next;
        }
        return h;
    }
};

