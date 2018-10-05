#include<bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        int MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<pair<int,int> > s1, s2;
        for (int i = 0; i < n; i++) {
            int count = 1;
            while ( (!s1.empty()) && s1.top().first > A[i]) {
                count+= s1.top().second;
                s1.pop();
            }
            s1.push({A[i],count});
            left[i] = count;
        }
        
        for (int i = n-1; i>=0; i--) {
            int count = 1;
            while( !s2.empty() && s2.top().first >= A[i]) {
                count+= s2.top().second;
                s2.pop();
            }
            
            s2.push({A[i],count});
            right[i] = count;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            count = (count + (A[i]*left[i]*right[i])) % MOD;
        }
        return count;
    }
    
    
int main() {
	vector<int> A{1,3,2,1,5,6,4};
	int count = sumSubarrayMins(A);
	cout << "count = " << count << endl;
	return 0;
}
