#include <bits/stdc++.h>

using namespace std;

void eval(string s, int t) {
	int len = s.length();
	string str = s;
	cout << "final string after t = " << t << " time is - ";
	while(!(t--)) {
		for (int i = 1; i < len; i++) {
			if (s[i-1] == 'B' && s[i] == 'G') {
				str[i] = 'G';
				str[i-1] = 'B';
			}
		}
		s = str;
	}
	cout << s << endl;
	return;
}


int main() {
	int n, t;
	n = 5;
	t = 1;
	string s = "BGGBG";
	eval(s, t);
	return 0;
}
