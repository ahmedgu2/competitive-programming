
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(0);
        ListNode* head = cur;

        int rem = 0;
        while(l1 || l2 || rem){
            if(l1){
                rem += l1->val;
                l1 = l1->next;                
            }
            if(l2){
                rem += l2->val;
                l2 = l2->next;                
            }
            cur->next = new ListNode(rem % 10);
            rem /= 10;
            cur = cur->next;
        }
        return head->next;
    }
    
};