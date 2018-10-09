#include <bits/stdc++.h>

using namespace std;

    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
    	int as = A.size();
    	int bs = B.size();
    	int bg = as > bs ? as : bs;
    	int suma=0, sumb=0;
       	for (int i = 0; i < bg; i++) {
            if (i < as)
       			suma+=A[i];
            if (i < bs) {
				sumb+=B[i];
			}
		} 
		int diff = (suma - sumb)/2;
		for (int i = 0; i < as; i++) {
			for (int j = 0; j < bs; j++) {
				if (A[i]-B[j] == diff) {
					ans[0] = A[i];
					ans[1] = B[j];
					break;
				}
			}
		}
		return ans;
    }
    
    
    int main () {
    	vector<int> A(3);
    	vector<int> B(2);
    	A[0] = 1;
    	A[1] = 2;
    	A[2] = 5;
    	B[0] = 2;
    	B[1] = 4;
    	vector<int> ans = fairCandySwap(A,B);
    	cout << ans[0] << " " << ans[1];
	}
