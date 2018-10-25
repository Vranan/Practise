#include<bits/stdc++.h>
using namespace std;

//class <template> TYPE;

int gcd(int x, int y) {
 vector<int> divisors; 
 vector<int> total; 
 
 for (int i = 2; i <= x; i++) { 
 	while (x%i == 0) { 
	 	x /= i; 
		divisors.push_back(x); 
	} 
 }
 
 for (int i = 2; i <= y; i++) {
 	while (y%i == 0) { 
	 	y /= i; 
		for (int n : divisors) { 
			if (y == n) { 
				total.push_back(y); 
			} 
		} 
	} 
 } 
 
 for (int n : total) { 
 	cout << n << endl; 
 }
 
 return 0;
 } 

/*int gcd(int x, int y) {
		
while (x != y) {
	if (x > y)
	      x -= y;
	else
	      y-=x;
	cout << "GCD = " << x;
	}
	return x;
}
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
TreeNode* createBST(vector<int>& vec, int l, int h) {
	if (l > h)
		return NULL;
	
	cout << "CBST" << endl;
	int mid = (l+h)/2;
	TreeNode* r = new TreeNode(vec[mid]);
	r->left = createBST(vec, l, mid-1);
	r->right = createBST(vec, mid+1, h);
	return r;
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

void itrVec(vector<TreeNode*> vec) {
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i]->val << " ";
	}
	cout << endl;
}

void itrVvec(vector<vector<int> >& vec) {
	
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) 
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void levelTraversal(TreeNode* root) {
	
	queue<pair<TreeNode*, int> > q;
	q.push({root, 0});
	int lv = 0;
	vector<vector<int> > vec;
	while(!q.empty()) {
		
		TreeNode* temp = q.front().first;
		lv = q.front().second;
		q.pop();
		
		if (vec.empty() || vec.size() <= lv) {
			vec.push_back(vector<int>());
		}
		
		vec[lv].push_back(temp->val);
		
		
		if (temp->left)
			q.push({temp->left, lv+1});
		if (temp->right)
			q.push({temp->right, lv+1});
		
	}
	
	cout << "Level Traversal of the Tree starting from Root - " << root->val << " is: " << endl;
	itrVvec(vec);
	
}





void char_xor(string s) {
	
	int l = s.length();
	cout << "string = " << s << endl;
	for (int i = 0; i < l/2; i++) {
		cout << "1. " << s[i] << endl;
		s[i] ^= s[l - i -1];
		cout << "2.1 " << int(s[i]) << endl;
		cout << "2. " << s[i] << " " << s[l-i-1] << endl;
		s[l - i - 1] ^= s[i];
		cout << "3. " << s[l-i-1] << endl;
		s[i] ^= s[l-i-1];
		cout << "4. " << s[i] << endl;
	}
	
	cout << "reversed string = " << s << endl;
}


vector<TreeNode*> ancestor_of_a_node(TreeNode* root, int v) {
	
	vector<TreeNode*> vec;
	while(root->val != v) {
		vec.push_back(root);
		//cout << "1. " << root->val << endl;
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

TreeNode* customTree() {
	TreeNode* root = new TreeNode(6);
	TreeNode* trav = root;
	trav->left = new TreeNode(2);
	trav->right = new TreeNode(8);
	trav = trav->left;
	trav->left = new TreeNode(0);
	trav->right = new TreeNode(4);
	trav = trav->right;
	trav->left = new TreeNode(3);
	trav->right = new TreeNode(5);
	trav = root->right;
	trav->left = new TreeNode(7);
	trav->right = new TreeNode(9);
	
	/*TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);*/
	
	
	return root;
}

string solution2(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (S.length() == 1 && S[0] != '-') {
    	S[0] = ((97 <= S[0] && S[0] <= 122) ? S[0]-32 : S[0]);
    	return S;
    }
    else if (S.length() == 1 && S[0] == '-')
    	return '\0';
    	
    string S2;
    int c = 1;
    for (int i = S.length()-1; i >= 0; i--) {
        	if (S[i] != '-' && c == K) {
        		S2 = (97 <= S[i] && S[i] <= 122) ? char((S[i]-32)) + S2 : S[i] + S2;
        		S2 = (i >= K) ? '-' + S2 : S2;
                c = 1;
			} else if (S[i] != '-'  && c < K) {
                S2 = (97 <= S[i] && S[i] <= 122) ? char(S[i]- 32) + S2 : S[i] + S2;
                c++;
            }
    }
    return S2;
}


vector<int> solution(vector<int> &stores, vector<int> &houses) {
    // write your code in C++14 (g++ 6.2.0)
    sort(stores.begin(), stores.end());
    vector<int> res;
    
    
    for (unsigned int i = 0; i < houses.size(); i++) {
    	int sm = 0; int l = stores.size()-1; int mid = (sm+l)/2;
    	int minI = mid;
    	int house = houses[i];
        while (l >= sm) {
            mid = (sm+l)/2;
            
            if (stores[mid] == house) {
                break;
            } else if (stores[mid] > house){
                l = mid-1;
            } else if (stores[mid] < house) {
                sm = mid+1;
            }
        }
        
        if (mid > stores.size()/2)
        	mid--;
        int comp1 = abs(stores[mid]-houses[i]); int comp2 = abs(stores[mid+1]-houses[i]);
        
        if (stores[mid] == house)
        	res.push_back(stores[mid]);
		else if (comp1 < comp2) 
            res.push_back(stores[mid]);
        else if (comp1 > comp2) 
            res.push_back(stores[mid+1]);
        
        
    }
    return res;
}

int main() {

	vector<int> stores{1,5,20,11,16};
	vector<int> houses{5,10,17,20,9,0};
	vector<int> result = solution(stores,houses);
	itrVec(result);
	

	return 0;
}



        //cout << "2. mid = " << mid << ", stores[mid] = " << stores[mid] << ", houses[i] = " << houses[i] << endl;
        //cout << "comp1 = " << comp1 << ", comp2 = " << comp2<< endl; 
