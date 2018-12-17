/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    vector<TreeNode*> vec;
    void bft(TreeNode* rt, int N, TreeNode* root) {
        if (N == 0) {
            vec.push_back(root);
            return;
        }        
            root->left = new TreeNode(0);
            root->right = new TreeNode(0);
        
        bft(root->left, N-2, root);
        bft(root->right, N-2, root);
        
        if ((N-2)%2 == 1) {
            bft(root->left, (N-2)/2-1, root);
            bft(root->right, (N-2)/2+1, root);
            bft(root->left, (N-2)/2+1, root);
            bft(root->right, (N-2)/2-1, root);
        } else {
            bft(root->left,(N-2)/2,root);
            bft(root->right,(N-2)/2,root);
        }
    }
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        TreeNode* root = new TreeNode(0);
        bft(root, N-1, root);
        return vec;
    }
};
