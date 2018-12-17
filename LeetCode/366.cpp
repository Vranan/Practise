#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 
 void itrVvec(vector<vector<int> >& vec) {
	
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) 
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void itrN(TreeNode* node) {
	if (node == NULL)
		return;
		
	cout << node->val << " ";
	itrN(node->left);
	itrN(node->right);	
}
 
 void itrVec(vector<int> vec) {
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}


 
 TreeNode* customTree() {
	TreeNode* root = new TreeNode(1);
	
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	
	root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);
	root->left->right->left = new TreeNode(10);
	root->left->right->right = new TreeNode(11);
	
	root->right->left->left = new TreeNode(12);
	root->right->left->right = new TreeNode(13);
	root->right->right->left = new TreeNode(14);
	root->right->right->right = new TreeNode(15);
	
	/*TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);*/
	return root;
}
 
    TreeNode* fl(TreeNode* root, vector<int>& vec) {
    	
		//cout << " >>>>>>>>>>> fl :: BEGIN <<<<<<<<<<<<<<" << endl;
		
		if (root == NULL) return NULL;
		
        if (root->left == NULL && root->right == NULL) {
        	//cout << "1. " << root->val << endl;
            vec.push_back(root->val);
			//cout << "2. leaves added -- "; 
            //itrVec(vec);
            //cout << " >>>>>>>>>>> fl :: END <<<<<<<<<<<<<<" << endl;
            return NULL;
        }
        
        root->left = fl(root->left, vec);
        root->right = fl(root->right, vec);
        
        //cout << " >>>>>>>>>>> fl :: END <<<<<<<<<<<<<<" << endl;
        return root;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
      vector<vector<int>> myvec;
      vector<int> mvec;
      TreeNode* temp = root;
      while (temp != NULL) {
          //cout << "------------- findLeaves :: BEGIN------------- " << endl;
          mvec.clear();
          temp = fl(root, mvec);
          //cout << "leaves --" << endl;
          //itrVec(mvec);
          myvec.push_back(mvec);
          //cout << "left tree iterate  -- ";
          //itrN(temp);
          //cout << endl;
          //cout << "------------- findLeaves :: END------------- " << endl;
      }
        return myvec;
    }
    
    
    
    int main() {
    	
    	
    	TreeNode* root = customTree();
    	//TreeNode* root = new TreeNode(1);
    	cout << "Preorder traversal" << endl;
    	itrN(root);
    	cout << endl;
    	vector<vector<int>> mvec2 = findLeaves(root);
    	cout << "Complete List of leaves -- " << endl;
    	itrVvec(mvec2);
    	return 0;
	}
	
	
	
	
	
	
	
