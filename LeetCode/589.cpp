#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> preTree;
        void preOrder(Node* root) {
            if (root == NULL)
                return;
        
            preTree.push_back(root->val);
            vector<Node*> ch = root->children;
            for (vector<Node*>::iterator it = ch.begin(); it != ch.end(); it++) {
                preOrder(*it);
            }
        }
    
    public:
        vector<int> preorder(Node* root) {
            Node* new_node = root;
            preOrder(new_node);
            return preTree;
        }
};




/*

Given an n-ary tree, return the preorder traversal of its nodes' values.

 
For example, given a 3-ary tree:



 
Return its preorder traversal as: [1,3,5,6,2,4].

 
Note: Recursive solution is trivial, could you do it iteratively?

*/
