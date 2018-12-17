#include<bits/stdc++.h>
using namespace std;

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
 

void printArray(int arr[], int n) {
	int i;
	for (i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	cout << "n = " << n << endl;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			printArray(arr,8);
			j = j-1;
		}
		arr[j+1] = key;
	}
}


void insertion_sort(vector<int>& arr) {
	cout << "Begin" << " --> ";
	itrVec(arr);
	cout << endl;
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j;
		for (j = i-1; j >= 0; j--) {
			if (arr[j] > key) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			
		}
		arr[j+1] = key;
		itrVec(arr);
	}
	cout << "Final -- " << endl;
	itrVec(arr);
}


int getVolume(vector<int> A, bool isForward, int end, int boundary[]) {  
	itrVec(A);
	cout << "isForward = " << isForward << ", end = " << end << ", boundary = " << boundary << ", boundary[0] = " << boundary[0] << endl;
    // skip zeros  
   int cur = 0;  
   if (end < 0) end = 0;
   if (!isForward) cur = A.size() - 1;  
   while (cur != end && A[cur] == 0) {  
     cur += (isForward ? 1 : -1);  
   }  
   
   cout << "cur = " << cur << endl;
   
   int vol = 0, newEnd = cur;  
   for (int i=cur, tempSum=0; i!=end; i+=(isForward ? 1 : -1)) {  
     if (A[i] >= A[newEnd]) {  
       vol += tempSum;  
       // reset  
       tempSum = 0;  
       newEnd = i;  
     } else {  
       tempSum += (A[newEnd] - A[i]);  
     }  
   }  
   boundary[0] = newEnd;  
   cout << "vol = " << vol << endl;
   return vol;   
 }  
   
int trap(vector<int>& A) {  
   int *boundary = new int[1];  
   int vol = getVolume(A, true, A.size(), boundary);
   vol += getVolume(A, false, boundary[0]-1, boundary);  
   return vol;  
 } 

void set_check() {
	set<int> myset;
	myset.insert(10);
	myset.insert(10);
	for (auto it : myset) {
		cout << it << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		if (i <= 5)
			myset.insert(10);
		
		myset.insert(i);
	}
	for (auto it : myset) {
		cout << it << " ";
	}
	cout << endl;
	myset.erase(10);
	for (auto it : myset) {
		cout << it << " ";
	}
	
}


	
int main() {
	
	/*vector<vector<int>> myvec;
	
	myvec.push_back(vector<int> {1});
	myvec.push_back(vector<int> {2});
	myvec.push_back(vector<int> {3});
	int j = 0;
	for (auto it = myvec.begin(); it != myvec.end(); it++) {
		vector<int> t = (*it);
		vector<int> temp{j+1,j+2,j+3};
		temp.push_back(j+4);
		t.push_back(j+1);
		vector<int> t1 = t;
		j++;
		//temp.push_back(j++);
		
		myvec.push_back(temp);
		myvec.push_back(t1);
		if (j == 5)
			break;
	}
	
	itrVvec(myvec);
	*/
	
	string a[10];
	a[0] = "Apple";
	a[1] = "Bat";
	a[2] = "Cat";
	a[3] = "Dog";
	a[4] = "Elephant";
	
	auto it = find(begin(a), end(a), "Dog");
	cout << *it << endl;
	
	return 0;
}


