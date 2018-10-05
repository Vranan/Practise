#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;
        
        int al = nums.size();
    
        int *LS = new int[al];
        
        for (int i = 0; i < nums.size(); i++) {
            LS[i] = 1;
            cout << " i -- nums[" << i << "] = " << nums[i] << ", LS[" << i << "] = " << LS[i] << endl;
            for (int j = 0; j <= i-1; j++) {
            	cout << "j -- nums[" << j << "] = " <<  nums[j] << ", LS[" << j << "] = " << LS[j] << endl;
                if ((nums[i] > nums[j]) && (LS[i] <= LS[j])) {
                	cout << "if " << " ";
                    LS[i] = LS[j] + 1;
                    cout << "i = " << i << "LS[" << i << "] = " << LS[i] << endl;
                }
            }
            cout << endl;
        }
        
        int largest = LS[0];
        for (int i = 0; i < nums.size(); i++) {
            if (largest < LS[i]) {
                largest = LS[i];
                cout << "largest = " << largest << endl;
            }
        }
        
        return largest;
}

void itr(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec{10,9,2,5,3,7,101,18};
	cout << "Inside Main " << endl;
	itr(vec);
	int ls = lengthOfLIS(vec);
	return 0;
}
