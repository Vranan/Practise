#include <bits/stdc++.h>
using namespace std;

void itr(vector<string> myvec) {
	vector<string>::iterator it;
	for (it = myvec.begin(); it !=myvec.end(); it++) {
		cout << *it << " ";
	}
}

int main() {
    string A, B;
    getline(cin, A);
	getline(cin, B);
	
	string C = A +" " + B;
	vector<string> strvec;
	
	stringstream ss1(C);
	string word1;
	
	map<string, int> m;
	
	while (ss1 >> word1) {
		if (m[word1]) {
			m[word1] = 2;
			continue;
		}
		m[word1] = 1;
	}
	
	map<string,int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == 1)
			strvec.push_back(it->first);
	}
	
	itr(strvec);
	return 0;
 }
 

