#include<iostream>
#include<vector>
#include<string>
using namespace std;




/**   								Following is only the class part for submission.
 class Solution {
private:
	vector<string> vec;
	void TraverseSl(TreeNode* n) {
		if (!n) {
            vec.push_back("null");
            return;
        }
		
		vec.push_back(to_string(n->val));
		TraverseSl(n->left);
		TraverseSl(n->right);
	}

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        TraverseSl(p);
		vector<string> lvec1 = vec;
		vec.erase(vec.begin(), vec.end());
		TraverseSl(q);
		vector<string> lvec2 = vec;
		if (lvec1.size() != lvec2.size()) return false;
		
		for (int i = 0; i < lvec1.size(); i++) {
			if (lvec1[i] != lvec2[i])
				return false;
		}
		
		return true;
    }
};
 */

 
 //							Below is the solution including tree creation and tree traversal sections to test the solution.

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
	
private:
	vector<string> vec;
	void TraverseSl(TreeNode* n) {
		if (!n) {
			vec.push_back("null");
			return;
		}
		vec.push_back(to_string(n->val));
		TraverseSl(n->left);
		TraverseSl(n->right);
	}

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        TraverseSl(p);
		vector<string> lvec1 = vec;
		vec.erase(vec.begin(), vec.end());
		TraverseSl(q);
		vector<string> lvec2 = vec;
		vec.erase(vec.begin(), vec.end());
		cout << "lvec1.size() = " << lvec1.size() << ", lvec2.size() = " << lvec2.size() << endl;
		if (lvec1.size() != lvec2.size()) return false;
		
		for (int i = 0; i < lvec1.size(); i++) {
			cout << "i = " << i << ", " << lvec1[i] << " " << lvec2[i] << endl;
			if (lvec1[i] != lvec2[i])
				return false;
		}
		
		return true;
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
	sl.isSameTree(bt1->root, bt2->root);
	return 0;
}






