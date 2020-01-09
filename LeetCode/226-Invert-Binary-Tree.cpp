#include<bits/stdc++.h>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* node){
        if(node == NULL)
            return;
        invert(node->left);
        invert(node->right);
        
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
};