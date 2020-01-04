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
    
    bool ans;
    
    bool isBalanced(TreeNode* root) {
        ans = true;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* node){
        if(node == NULL)
            return 0;
        
        int l = 1 + dfs(node->right);
        int r = 1 + dfs(node->left);
        
        if(abs(l-r) > 1)
            ans = false;
        
        return max(l, r);
    }
};