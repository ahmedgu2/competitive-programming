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
    
    TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
        dfs(&root);
    }
    
    void dfs(TreeNode** node){
        if(*node == NULL)
            return;
        
        dfs(&((*node)->right));
        dfs(&((*node)->left));

        
        (*node)->right = prev;
        (*node)->left = NULL;
        prev = *node;
    }
};