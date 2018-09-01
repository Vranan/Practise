#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char,char> m;
	if (!m['a']) {
		cout << "Inside if" << endl;
		m['a'] = 'p';
	}
}
