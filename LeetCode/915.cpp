#include<bits/stdc++.h>
using namespace std;


int partitionDisjoint(vector<int>& A){
	int p0 = 0, p1 = 0, m = 0;
	
	for(int i=1; i<A.size(); i++){
		cout << "     A[" << i <<"] = " << A[i] << ", A[" << m <<"] = " << A[m] << ", A[" << p0 <<"] = " << A[p0] << endl;
		if(A[i] >= A[m])
			m = i;
		if(A[i] < A[p0])
			p1 = i, p0 = m;
		cout << "i = " << i << ", m = " << m << ", p0 = " << p0 << ", p1 = " << p1 << endl;
	}
	return p1 + 1;
}

int main() {
	vector<int> myvec{1,0,3,8,9,12};
	int ind = partitionDisjoint(myvec);
	cout << "ind = " << ind << endl;
	return 0;
}
