#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int k) {
		    val = k;
	    }
};

class BinaryTree {
public:
	TreeNode *root;
	
	BinaryTree(int k) {
		root = new TreeNode(k);
	}
	
	void TreeCreation() {
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		root->right->left = new TreeNode(6);
		root->right->right = new TreeNode(7);
	}
	
	void TreeTraversal(TreeNode *n) {		
		if (!n) return;
		cout << n->val << endl;
		TreeTraversal(n->left);
		TreeTraversal(n->right);
	}
	
	void Traverse() {
		TreeTraversal(root);
	}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
		if (!root) return 0;
		int depth = 0;
        queue<TreeNode *> q;
		q.push(root);
		while(!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				TreeNode* n = q.front();
				q.pop();
				if (n->left) q.push(n->left);
				if (n->right) q.push(n->right);
			}
			depth++;
		}
		return depth;
	}
};

int main () {
	BinaryTree *bt1 = new BinaryTree(1);
	BinaryTree *bt2 = new BinaryTree(1);
	bt1->TreeCreation();
	// bt1->Traverse();
	bt2->TreeCreation();
	// bt2->Traverse();
	Solution sl;
	int depth = sl.maxDepth(bt1->root);
	cout << "Depth = " << depth << endl;
	return 0;
}