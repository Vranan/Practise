#include<bits/stdc++.h>
using namespace std;

void itr(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> vec;
    auto &a = nums;
    
    for (int i = 0; i < a.size();) {
        
        if (a[i] == i+1 || a[i] == 0) 
			++i;
        else if (a[i] == a[a[i]-1]) {
            a[i]=0;
            ++i;
        } else {
            /*int temp = a[i];
            a[i] = a[a[i]-1];			// running this makes the loop go into infinite loop.
            a[a[i]-1] = temp;*/
            int temp = a[a[i]-1];
            a[a[i]-1] = a[i];
            a[i] = temp;
        }   
    }
    
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) 
            vec.push_back(i+1);
    }
    
    return vec;
}


int main() {

	vector<int> vec{4,3,2,7,8,2,3,1};
	vector<int> v = findDisappearedNumbers(vec);
	itr(v);
	return 0;
}

