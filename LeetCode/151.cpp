#include<bits/stdc++.h>
using namespace std;


 void reverseWords(string &s) {
        
        if (s.size() == 0)
            return;
        
        istringstream ss(s);
        string str;
        ss >> s;
        cout << "s = " << s << endl;
        while (ss >> str) {
            s = str + ' ' + s;
        }
        cout << "s = " << s << endl;
        if (s[0] == ' ') s = "";
        
    }


int main() {
	
	string s = "the sky is blue";
	reverseWords(s);
	cout << "s = " << s << endl;
	return 0;
}

