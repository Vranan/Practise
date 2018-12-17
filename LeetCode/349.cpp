#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        set<int> myset(nums1.begin(), nums1.end());
        
        for (auto x : nums2) {
            if (myset.erase(x))
                res.push_back(x);
        }
        return res;
}

int main() {

	return 0;
}

