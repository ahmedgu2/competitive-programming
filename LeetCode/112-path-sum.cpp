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
    
    int done = true;
    
    bool hasPathSum(TreeNode* root, int sum) {
        done = false;
        dfs(root, sum, 0);
        return done;
    }
    
    void dfs(TreeNode* node, int sum, int cur){
        if(node == NULL)
            return;
        
        dfs(node->left, sum, cur + node->val);
        dfs(node->right, sum, cur + node->val);
        
        if(cur + node->val == sum && node->left == NULL && node->right == NULL){
            done = true;
            return;            
        }
    }
};