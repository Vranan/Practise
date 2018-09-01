#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

map<int,int> m;
void preOrder(TreeNode* root) {
	if (root == NULL)
		return;
	
		m[root->val]++;
			
	preOrder(root->left);
	preOrder(root->right);
}

vector<int> findMode(TreeNode* root) {
		TreeNode* node = root;
        preOrder(node);
        int max = 0;
        vector<int> myvec;
        map<int,int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
        	if (it->second > max){
        		max = it->second;
        		myvec.clear();
        		myvec.push_back(it->first);
			} else if (it->second == max) {
				myvec.push_back(it->first);
			} 	
		}
		return myvec;
}

int main() {
	
	return 0;
}
