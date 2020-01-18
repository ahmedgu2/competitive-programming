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
    
    bool ans = true;
    long long last = -1e10;
    
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* node){
        if(node == NULL)
            return;
        
        dfs(node->left);
        if(last >= node->val)
            ans = false;
        last = node->val;
        dfs(node->right);
        
    }
};