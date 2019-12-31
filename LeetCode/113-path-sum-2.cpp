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
    
    vector<int> path;
    vector<vector<int>> ans;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return ans;
        path.push_back(root->val);
        dfs(root, sum, root->val);
        return ans;
    }
    
    void dfs(TreeNode* node, int sum, int cur){
        if(cur == sum && node->left == NULL && node->right == NULL){
            ans.push_back(path);
            return;
        }
        
        if(node->left != NULL){
            path.push_back(node->left->val);
            dfs(node->left, sum, cur + node->left->val);
            path.pop_back();    
        }
        if(node->right != NULL){
            path.push_back(node->right->val);
            dfs(node->right, sum, cur + node->right->val);
            path.pop_back();
        }
        
    }
};