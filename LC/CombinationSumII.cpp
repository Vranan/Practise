#include<bits/stdc++.h>
using namespace std;

class Solution {
    

public:
	vector<vector<int>> com;
	vector<int> scom;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
		find (target, candidates, 0);
		return com;
    }
    
    void find(int target, vector<int>& cand, int index) {
		if (target == 0) com.push_back(scom);
		else if (target > 0) {		
			for (int i = index; i < cand.size() && target >= cand[i]; i++) {
				if (cand[i] == cand[i-1]) continue;
					scom.push_back(cand[i]);
					vector<int> temp = cand;
					temp.erase(temp.begin()+i);
					find(target-cand[i], temp, i);
					scom.pop_back();
			}
		}
	}
};


int main() {
	Solution sl;
	vector<int> candidates = {1, 1, 2, 5, 6, 7, 10};
	vector<vector<int>> result;
	result = sl.combinationSum2(candidates, 8);
	cout << endl << "The final Result == " << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int  j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}