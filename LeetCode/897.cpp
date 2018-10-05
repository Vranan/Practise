#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

	int arr[100]={0};
	int i = 0;

	void preOrder(TreeNode* root) {
		cout << "preOrder -- root = " << root << endl;
        if(root == NULL)
            return;
        
        arr[i] = root->val;
        i = i + 1;
        preOrder(root->left);
        preOrder(root->right); 
    }
    
    void preOrder2(TreeNode* root) {
    	cout << "preOrder2 = " << root << endl;
        if(root == NULL)
            return;
        
        cout << " -- " << root->val << endl;
        preOrder(root->right);
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
    	cout << "increasingBST  " << endl;
    	int arr[100]={0};
        TreeNode *new_node = root;
        preOrder(new_node);
        stack<TreeNode*> s;
        s.push_back(root);
        int i = 0;
        sort(arr,arr+i-1);
        for (int j = 0; j <= i-1; j++) {
        	cout << "1. " << arr[j] << endl;
 		}
 		cout << "i =" << i << endl;
        TreeNode *rt = new TreeNode(arr[0]);
        TreeNode *strt = rt;
        for (int k = 1; k < i; k++) {
            TreeNode *new_node = new TreeNode(arr[k]);
            rt->right = new_node;
            rt = new_node;
        }
        return strt;
    }
    
int main() {
	TreeNode *rtn = new TreeNode(379);
	rtn->left = new TreeNode(826);
	rtn->right = NULL;
	//cout << "rtn = " << rtn << ", rtn->left = " << rtn->left << endl;
	//cout << " rtn->left->val = " << rtn->left->val << endl;
	TreeNode* nnode = increasingBST(rtn);
	//cout << "nnode = " << nnode << endl;
	preOrder2(nnode);
	return 0;
}
