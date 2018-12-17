#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result, 0);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    
    int l = 0;
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result, int l)	{
        cout << "num = ";
        string t;
        for (auto x : num) {
            cout << x;
            t += (x + '0');
        }
        
        cout << ", begin = " << begin << ", l = " << l << endl;
		if (begin >= num.size()) {
		    // one permutation instance
            cout << "res.push_back " << t << endl;
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
            cout << "i = " << i << endl;
		    swap(num[begin], num[i]);
            cout << "1. swap " << ", i - " << i << ", begin - " << begin << endl;
            cout << "permute (" << begin+1 << ", res" << endl;  
		    permuteRecursive(num, begin + 1, result, l+1);
		    // reset
            cout << "2. swap" << ", i - " << i << ", begin - " << begin << endl; 
		    swap(num[begin], num[i]);
		}
    }
};



int main() {

	return 0;
}

