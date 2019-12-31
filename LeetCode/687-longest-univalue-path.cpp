#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans;
    
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* node){
        
        if(node == NULL)
            return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        int l = 0, r = 0;
        if(node->left != NULL && node->val == node->left->val){
            l = left + 1;
        }
        if(node->right != NULL && node->val == node->right->val){
            r = right + 1;
        }
        
        ans = max(ans, l+r);
        return max(l, r);
    }
};