#include<bits/stdc++.h>
using namespace std;

//vector<int> num;

vector<int> num;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  	
  	
void itr(vector<int>& myvec) {
	for (int i = 0; i < myvec.size(); i++) 
		cout << myvec[i] << " ";
	cout << endl;
}
  	
TreeNode* insert(int l, int h, vector<int>& nums){
	if (h < l)
	    return NULL;
	
	int median = (l + h)/2;
	TreeNode* r = new TreeNode(nums[median]);
	
	r->left = insert(l, median - 1, nums);
	r->right = insert(median + 1, h, nums);
	return r;
}
	
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.size() == 0)
	    return NULL;
	
	return insert(0, nums.size()-1, nums);
}

void inorder(TreeNode *root) {
	if (root == NULL)
		return;
		
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main() {
	
	vector<int> vec{1, 2, 3, 4, 5, 6};
	cout << "inside main" << endl;
	TreeNode* n = sortedArrayToBST(vec);
	inorder(n);
	
	return 0;
}

