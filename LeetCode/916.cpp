#include<bits/stdc++.h>
using namespace std;

void itr2(unordered_map<char, int> mp) {
	for (unordered_map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << ",  ";
	cout << endl;
}


vector<string> wordSubsets(vector<string>& A, vector<string>& B) {        
        unordered_map<char, int> m;
        unordered_map<char, int> n;
        
        vector<string> myvec;
        
      for (int i = 0; i < B.size(); i++) {
          string s = B[i];
          m.clear();
          for (int j = 0; j < s.length(); j++) {
              m[s[j]]++;
              n[s[j]] = max(m[s[j]], n[s[j]]);
          }
      }
        
      int sz = n.size();
      for (int i = 0; i < A.size(); i++) {
        int c = 0;
        string s = A[i];
        m.clear();
        for (int j = 0; j < s.length(); j++) {
            m[s[j]]++;
            if (m[s[j]] == n[s[j]])
                c++;
        }
          if (c == sz)
              myvec.push_back(s);
    }
       return myvec; 
    }
    
void itr(vector<string> s) {
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
	cout << endl;
}
int main() {
	vector<string> A{"amazon","apple","facebook","google","leetcode"};
	vector<string> B{"ec","oc","ceo"};
	vector<string> vec = wordSubsets(A, B);
	itr(vec);
	return 0;
}
