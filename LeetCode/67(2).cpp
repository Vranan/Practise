#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
	
	int al = a.size() - 1;
	int bl = b.size() - 1;
	int c = 0;
	string s = "";
	while (al >= 0 || bl >= 0 || c == 1) {
		
		c += (al >= 0) ? a[al--]-'0' : 0;
		c += (bl >= 0) ? b[bl--]-'0' : 0;
		s = char(c % 2 + '0') + s;
		c /= 2;
	}
	return s;	
}	

int main() {
	string s1 = "1111";
	string s2 = "1111";
	string st = addBinary(s1, s2);
	cout << "st = " << st << endl;
		
	return 0;
}
