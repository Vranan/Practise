#include<bits/stdc++.h>
using namespace std;
void itr(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

vector<int> findDuplicates(vector<int>& nums) {
    auto &a = nums;
    vector<int> dup;
    
    for (int i = 0; i < a.size();) {
        
        if (a[i] == i+1 || a[i] == 0) ++i;
        else if (a[i] == a[a[i] - 1]) {
            dup.push_back(a[i]);
            a[i] = 0;
            ++i;
        } else {
            int temp = a[a[i] - 1];
            a[a[i] - 1] = a[i];
            a[i] = temp;
            
            if (0 == temp) ++i;
                
        }
        
        
    }
    itr(a);
    return dup;
        
}


int main() {
	
	vector<int> vec{4,3,2,7,8,2,3,1};
	vector<int> v = findDuplicates(vec);
	itr(v);
	
	return 0;
}

