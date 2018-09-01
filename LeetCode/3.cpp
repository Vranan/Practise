#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int StringCal(string s) {
	int start = -1,maxL = 0;
	vector<int> m(256,-1);
	for (int i=0; i != s.length();i++) {
		if (m[s[i]] > start)
			start = m[s[i]];
		m[s[i]] = i;
		maxL = max(maxL,i-start);
	}
	return maxL;
}

/*
int StringCal(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        cout << "string length = " << s.length() << endl;
        for (int i = 0; i != s.length(); i++) {
        	cout << "s[" << i << "] = " << s[i] << endl;
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            cout << "dict[" << s[i] << "] = " << dict[s[i]] << endl;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
}
*/


int lengthOfLongestSubstring(string s) {
	int st = StringCal(s);
	//std::string copy(s);
	//cout << "1. string = " << s << endl;
	//reverse(copy.begin(),copy.end());
	//cout << "2. string = " << s << endl;
	//int rv = StringCal(copy);
	//int max = (st>rv)? st : rv;
	return st;
}

int main() {
	string s = "abcabcbb";
	string s2 = "pwwkew";
	string s3 = "abb";
	string s4 = "bbbbb";
	string s5 = "dvdf";
	string s6 = "asjrgapa";
	string s7 = " ";
	int l = lengthOfLongestSubstring(s7);
	cout << "length = " << l << endl;
	return 0;
}
