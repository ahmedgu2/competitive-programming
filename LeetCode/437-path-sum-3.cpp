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
    
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        ans = 0;
        get_ans(root, sum);
        return ans;
    }
    
    void dfs(TreeNode* node, int sum, int cur){
        
        if(cur == sum)
            ans += 1;
        if(node->right != NULL)
            dfs(node->right, sum, cur + node->right->val);
        if(node->left != NULL)
            dfs(node->left, sum, cur + node->left->val);
    }
    
    void get_ans(TreeNode* root, int sum){
        dfs(root, sum, root->val);
        if(root->right != NULL)
            get_ans(root->right, sum);
        if(root->left != NULL)
            get_ans(root->left, sum);
    }
};