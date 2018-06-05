#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
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
		root->right = new TreeNode(2);
		root->left->left = new TreeNode(3);
		root->left->right = new TreeNode(4);
		root->right->left = new TreeNode(4);
		root->right->right = new TreeNode(3);
	}
	
	void TreeTraversal(TreeNode *n) {		
		if (!n) return;
		cout << n->val << " ";
		TreeTraversal(n->left);
		TreeTraversal(n->right);
	}
	
	void Traverse() {
		TreeTraversal(root);
	}
};
 
 
class Solution {
	
private:
	vector<string> vec;
	void TraverseL(TreeNode* n) {
		if (!n) {
			vec.push_back("null");
			return;
		}
		vec.push_back(to_string(n->val));
		TraverseL(n->left);
		TraverseL(n->right);
	}
	
	void TraverseR(TreeNode* n) {
		if (!n) {
			vec.push_back("null");
			return;
		}
		vec.push_back(to_string(n->val));
		TraverseR(n->right);
		TraverseR(n->left);
	}
	
public:
    bool isSymmetric(TreeNode* root) {
		if (!root) return true;             // In case if the root node is null. It is still symmetric.
		TraverseL(root->left);
		vector<string> lvec = vec;
		vec.erase(vec.begin(), vec.end());
		TraverseR(root->right);
		vector<string> rvec = vec;
		
		if (lvec.size() != rvec.size()) return false;
		
		for (int i = 0; i < lvec.size(); i++) {
			if (lvec[i] != rvec[i]) return false;
		}
		return true;
    }
};


int main () {
	BinaryTree *bt1 = new BinaryTree(1);
	BinaryTree *bt2 = new BinaryTree(1);
	bt1->TreeCreation();
	cout << "Tree Traversal" << endl;
	bt1->Traverse();
	cout << endl;
	bt2->TreeCreation();
	// bt2->Traverse();
	Solution sl;
	if (sl.isSymmetric(bt1->root))
		cout << "Symetric" << endl;
	else
		cout << "Not Symetric" << endl;
	return 0;
}