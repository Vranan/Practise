#include<bits/stdc++.h>
using namespace std;

vector<TreeNode*> ancestor_of_a_node(TreeNode* root, int v) {

vector<TreeNode*> vec;
	while(root->val != v) {
		vec.push_back(root);
		
		if (root->val == v) {
			break;
		} else if (root->val > v) {
			root = root->left;
		} else if (root->val < v) {
			root = root->right;
		}
	
	}

return vec;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode*> vp = ancestor_of_a_node(root, p->val);
	vector<TreeNode*> vq = ancestor_of_a_node(root, q->val);
	
	TreeNode* lca = vp[0];
	for (int i = 0; i < vp.size(); i++) {
		for (int j = 0; j < vq.size(); j++) {
			if (vp[i]->val == vq[j]->val  && vp[i]->val < lca->val)
				lca = vp[i];
		}
	}
	
	return lca;
}

int main() {

	return 0;
}

