#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:	
	void find(int index, int target, vector<int>&candidates, vector<int>& scom, vector<vector<int>>& com) {
		if(target == 0) {
			com.push_back(scom);
			return;
		}
		
		if (target < 0 || index >= candidates.size()) return;
		
		for (int i = index; i < candidates.size(); ++i) {
			int temp = candidates[i];
			scom.push_back(temp);
			target -= temp;
			find(i, target, candidates, scom, com);
			target += temp;
			scom.pop_back();
		}
	}

public: 
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> com;
		vector<int> scom;
		// sort(candidates.begin(), candidates.end());
		find(0, target, candidates, scom, com);
		return com;
	}	
};