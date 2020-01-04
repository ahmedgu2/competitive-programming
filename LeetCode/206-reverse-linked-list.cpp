#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        return reverseList_iterative(head);
    }
    
    ListNode* reverseList_recursive(ListNode* head){
        if(!head || !(head->next))
            return head;
        
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    ListNode* reverseList_iterative(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* nextTmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTmp;
        }
        return prev;
    }
      
};