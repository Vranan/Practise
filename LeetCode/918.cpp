#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& A) {
        
        int ms = 0;
        for (int i = 0; i < A.size(); i++) {
            int ps = A[i];
            if (ps > ms)
                ms = max(ms, ps);
            int j = i+1;
            int turn = 0;
            while(turn++ < A.size()-1) {
                ps = ps + A[j];
                if (ps > ms)
                    ms = max(ms, ps);
                
                if (j == A.size())
                    j = 0;
                else 
                    j++;
            }
        }
        return ms;
    }

int main() {
	vector<int> v{5, -3, 5};
	int s = maxSubarraySumCircular(v);
	cout << "s = " << s << endl;
	return 0;
}

