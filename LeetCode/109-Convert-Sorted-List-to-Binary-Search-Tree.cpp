#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    vector<int> nums;
    
    TreeNode* sortedListToBST(ListNode* head) {
        convertList(head);
        return vectorToBST(0, nums.size()-1);
    }
    
    void convertList(ListNode* node){
        while(node != NULL){
            nums.push_back(node->val);
            node = node->next;
        }
    }
    
    TreeNode* vectorToBST(int l, int r){
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = vectorToBST(l, mid-1);
        root->right = vectorToBST(mid+1, r);
        
        return root;
    }
};