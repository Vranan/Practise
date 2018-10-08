#include<bits/stdc++.h>
using namespace std;

void itr(vector<int> t) {
	for (int i = 0; i < t.size();i++) 
		cout << t[i] << " ";
	cout << endl;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec(m+n);
        for (int i = 0; i < m+n; i++) {
        	cout << " m = " << m << endl;
            while (i <= m-1) {
                vec[i] = nums1[i];
                i++;
            }
            itr(vec);
            cout << "i = " << i << endl;
            int j = 0;
            while (i < m+n) {
                vec[i] = nums2[j];
                j++;
                i++;
            }
            cout << "i = " << i << ", j = " << j << endl;
            itr(vec);
        }
        
        sort(vec.begin(), vec.end());
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            if (i != vec.size()-1)
                cout << vec[i] << ",";
            else
                cout << vec[i];
        }
        cout << "]";
}

int main() {
	vector<int> nums1{1,2,3,0,0,0};
	vector<int> nums2{2,5,6};
	merge(nums1, 3, nums2, 3);
	return 0;
}

