#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

void preOrder(TreeNode* node) {
	if(node == NULL)
		return;
	
	cout << node->val << ", ";
	preOrder(node->left);
	preOrder(node->right);
}

void postOrder(TreeNode* node) {
	if(node == NULL)
		return;
		
	postOrder(node->left);
	postOrder(node->right);
	cout << node->val << ", ";
}

 TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		vector<TreeNode*> myvec;
		TreeNode* new_node = new TreeNode(pre[0]);
		myvec.push_back(new_node);
		int  j = 0;
		for (int i = 1; i < pre.size(); i++) {
			TreeNode* new_node = new TreeNode(pre[i]);
			while (myvec.back()->val == post[j]) {
				myvec.pop_back();
				j++;
			}
			if (myvec.back()->left == NULL) 
				myvec.back()->left = new_node;
			else
				myvec.back()->right = new_node;
			myvec.push_back(new_node);	
		}
		return myvec[0];
    }

int main() {
	vector<int> pre{25,15,10,4,12,22,18,24,50,35,31,44,70,66,90};
	vector<int> post{4,12,10,18,24,22,15,31,44,35,66,90,70,50,25};
	TreeNode* new_node = constructFromPrePost(pre,post);
	cout << "pre --" << endl;
	preOrder(new_node);
	cout << endl << "post--" << endl;
	postOrder(new_node);
	return 0;
}
