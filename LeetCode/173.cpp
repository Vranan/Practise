#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class BSTIterator {
private:
    TreeNode* r;
public:
    BSTIterator(TreeNode *root) {
        r = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       
        if (r == NULL)
            return false;
        
        return true;
    }

    /** @return the next smallest number */
    int next() {
        if (r->left == NULL) {
        	int temp = r->val;
        	r = r->left;
            return temp;
        }
        
        r = r->left;
        return r->val;
    }
};

int main() {

	TreeNode *root = new TreeNode(1);
	BSTIterator i = BSTIterator(root);
 	while (i.hasNext()) cout << i.next();


	return 0;
}

