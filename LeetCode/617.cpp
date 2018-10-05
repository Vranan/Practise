#include<bits/stdc++.h>
using namespace std;



class Solution {    
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {    
        if (!t1 || !t2) return (t1 ? t1 : t2);  // If both are NULL,in that case returning either t1 or t2 won't matter.
        
        TreeNode* node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};


/*

Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.

*/
