 #include <bits/stdc++.h>
 using namespace std;
 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        cout << "pre[0] = " << pre[0] << endl;
        for (int i = 1, j = 0; i < pre.size(); ++i) {
        	cout << "i = " << i << ", pre[" << i << "] = " << pre[i] << endl;
            TreeNode* node = new TreeNode(pre[i]);
            while (s.back()->val == post[j]) {
            	cout << "post[" << j << "] = " << post[j] << ", s.back()->val = " << s.back()->val << endl;
                s.pop_back(), j++;
            }	
            if (s.back()->left == NULL) {
            	cout << "left node" << endl;
				s.back()->left = node;
			}
            else s.back()->right = node; {
				cout << "right node" << endl;
            	s.push_back(node);
        	}
        }
        return s[0];
    }

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
    
    int main() {
    	//vector<int> pre{25,15,10,4,12,22,18,24,50,35,31,44,70,66,90};
    	//vector<int> post{4,12,10,18,24,22,15,31,44,35,66,90,70,50,25};
    	
		vector<int> pre{25,50,35,31,44,70,66,90};
    	vector<int> post{31,44,35,66,90,70,50,25};
    	
		TreeNode* node = constructFromPrePost(pre, post);
    	cout << endl << "---- Final ----" << endl << endl;
    	cout << "Pre Order Traversal" << endl;
    	preOrder(node);
    	cout << endl << "Post Order Traversal" << endl;
    	postOrder(node);
    	return 0;
	}
