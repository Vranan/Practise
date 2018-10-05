#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (sameT(s,t)) return true;
        
        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
    
    private:  
   bool sameT(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        else if (!s || !t) return false;
        else if (s->val != t->val) return false;
        
        return (sameT(s->left, t->left) && sameT(s->right, t->right));
     }
};


int main(){
	TreeNode* rn = new TreeNode(3);
	rn->right = new TreeNode(5);
	rn->left = new TreeNode(4);
	rn->left->left = new TreeNode(1);
	rn->left->right = new TreeNode(2);
	
	TreeNode* t = new TreeNode(4);
	t->right = new TreeNode(2);
	t->left = new TreeNode(1);
	Solution sl;
	bool ans = sl.isSubtree(rn, t);
	cout << "ans = " << ans << endl;
	return 0;
}
