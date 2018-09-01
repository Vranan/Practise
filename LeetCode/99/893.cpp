#include<bits/stdc++.h>
using namespace std;

vector<string> myvec(1000);

int numSpecialEquivGroups(vector<string>& A) {
	for(int i = 0; i < A.size(); i++) {
		string s1 = A[i];
		int s1_len = s1.length();
		for(int j = i+1; j < A.size(); j++) {
			string s2 = A[j];
			int s2_len = s2.length();
			if (s1_len != s2_len)
				continue;
			myvec(i).push_back(s1);
			for (int k = 0; k < s1_len; k++) {
				char c = s1[k];
				int in = k;
				for (int l = 0; l < s2_len; l++) {
					char ch = s2[l];
					string temp = "";
					if (c == ch && k%2 == l%2) {
						temp = s2[k];
						s2[k] = s2[l];
						s2[l] = temp;
					}
				}
			}
			if (s2 == s1)
				myvec(i).push_back(s2);
			else
				myvec(i).pop(); 
		}
	}
	     
}

int main() {
	vector<string> A{"aa","bb","ab","ba"};
	int num = numSpecialEquivGroups(A);
	return 0;
}
