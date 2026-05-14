#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Method 1  (My Approach - Works 100% but TC=O(nlogn))
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

// Approach 2(Teacher Approach - TC=O(nlogk)
ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* merged = new ListNode(-1); // dummy node
    ListNode* mptr = merged;
    ListNode* left = list1;
    ListNode* right = list2;

    while (left != NULL && right != NULL) {
        if (left->val <= right->val) {
            mptr->next = left;
            left = left->next;
        } else {
            mptr->next = right;
            right = right->next;
        }
        mptr = mptr->next;
    }

    if (left) mptr->next = left;
    if (right) mptr->next = right;

    return merged->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;
    if (lists.size() == 1) return lists[0];

    ListNode* head = lists[0];

    for (int i = 1; i < lists.size(); i++) {
        head = merge(head, lists[i]);
    }

    return head;
}

int main(){
    //make object and call function 
    Solution s;
    
}