#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
	
		if (nums.size() == 0)
			return 0;
		else if (nums.size() == 1)
			return 1;
        
        int *LS = new int[nums.size()]; 
        for (int i = 0; i < nums.size(); i++) {
            LS[i] = 1;
            for (int j = 0; j <= i-1; j++) {
                if ((nums[i] > nums[j]) && (LS[i] <= LS[j])) {
                    LS[i] += 1;
                }
            }
        }
        
        int largest = LS[0];
        int sl = LS[0];
        unordered_map<int, int> m;
        for(int i = 1; i < nums.size(); i++) {
        	cout << "largest = " << largest << ", LS[" << i << "] = " << LS[i] << endl;
            if (largest < LS[i]){
            	sl = largest;
                largest = LS[i];
                m[largest] = 1;
            } else if (largest == LS[i]) {
            	m[largest]++;
            	cout << m[largest] << " " << endl;
            }
        }
        cout << "c  = " << m[largest-1] << endl;
        return m[largest-1];
}

int main() {
	vector<int> nums{2,2,2,2,2};
	// 1,3,5,4,7
	int c = findNumberOfLIS(nums);
	return 0;
}
