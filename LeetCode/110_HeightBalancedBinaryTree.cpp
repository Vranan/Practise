#include <iostream>
#include <queue>
#include <cmath>

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
		// root->right->left = new TreeNode(6);
		// root->right->right = new TreeNode(7);
		root->left->left->left = new TreeNode(8);
		root->left->left->right = new TreeNode(9);
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
/*
class Solution {
	
	private:
		queue<TreeNode *> q; 
		
		int height(TreeNode *root) {
			q.push(root);
			int depth = 0;
			while (!q.empty()) {
				int sz = q.size();
				for (int i = 0; i < sz; i++) {
					TreeNode *top = q.front();
					q.pop();
					if (top->left) q.push(top->left);
					if (top->right) q.push(top->right);
				}
				depth++;
			}
			return depth;
		}
	
	public:
		bool isBalanced(TreeNode* root) {
		    cout << "Inside isBalanced " << endl;
			if (!root) {
			    cout << "true " << endl;
			    return true;
			}
			queue<TreeNode *> qu;
			qu.push(root);
			while (!qu.empty()) {
			   //  cout << "Inside While" << endl;
				int sz = qu.size();
				int lv = 0;
				int rv = 0;
				// cout << "sz = " << sz << endl;
				for (int  i = 0; i < sz; i++) {
					TreeNode* r = qu.front();
					qu.pop();
					if (root->left) {
						lv = height(root->left);
						qu.push(root->left);
						
					}
					else lv = 0;
					if (root->right) { 
						rv = height(root->right);
						qu.push(root->right);
					}
					else rv = 0;
					// cout << "lv = " << lv << ", rv = " << rv << endl;
					if (abs(lv - rv) > 1)
						return false;
				}
			}
			return true;
	}
}; */


class solution {
public:
	int dfs(TreeNode* root) {
		if (root == NULL) return 0;
		
		int lh = dfs(root->left);
		if (lh == -1) return -1;
		int rh = dfs(root->right);
		if (rh == -1) return -1;
		
		if (abs(lh - rh) > 1) return -1;
		return (max(lh, rh) + 1);
	}
	
	bool isBalanced(TreeNode* root) {
		if (dfs(root) == -1) return false;
		return true;
	}
};

int main () {
	BinaryTree *bt1 = new BinaryTree(1);
	// BinaryTree *bt2 = new BinaryTree(1);
	bt1->TreeCreation();
	// bt1->Traverse();
	// bt2->TreeCreation();
	// bt2->Traverse();
	solution sl;
	bool bal = sl.isBalanced(bt1->root);
	cout << "Balanced = " << bal << endl;
	return 0;
}