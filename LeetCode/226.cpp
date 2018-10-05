#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void preOrder(TreeNode* root) {
        if (root == NULL)
            return;
        
        TreeNode* rl = root->left;
        root->left = root->right;
        root->right = rl;
        preOrder(root->left);
        preOrder(root->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* nn = root;
        preOrder(nn);
        return root;
    }
};
