#include<bits/stdc++.h>
using namespace std;

TreeNode* lowestCommonAncestor_235(TreeNode* root, TreeNode* p, TreeNode* q) {
	
	cout << "loweestCommonAncestor. " << root->val << " " <<  p->val << " " << q->val << endl; 
	
	vector<TreeNode*> vp = ancestor_of_a_node(root, p->val);
	vector<TreeNode*> vq = ancestor_of_a_node(root, q->val);
	
	sort(vp.begin(), vp.end());
	sort(vq.begin(), vq.end());
	
	
	
	cout << "Check 2" << endl;
	TreeNode* lca = root;
	cout << "lca->val = " << lca->val << endl;
	for (int i = 0; i < vp.size(); i++) {
		for (int j = 0; j < vq.size(); j++) {
			if (vp[i]->val == vq[j]->val  && vp[i]->val < lca->val)
				lca = vp[i];
		}
	}
	cout << "check 3" << endl;
	return lca;
}

int main() {

	return 0;
}

