#include <bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	vector<string> wo;
	int c = 0;
	unordered_map<char,char> m;
	unordered_map<char,char> s;
	for (int w = 0; w < words.size(); w++) {
	    m.clear();
	    s.clear();
		string word = words[w];
		for (int i=0; i<pattern.length(); i++) {
			if(m[pattern[i]] || s[word[i]]) {
			 	if ((m[pattern[i]] != word[i])) {
					c = 1;		
					break;
				} 
				
				if (s[word[i]] != pattern[i]) {
				    c = 1;
				    break;
				}
			} else {
				m[pattern[i]] = word[i];
				s[word[i]] = pattern[i];
			}
		}
		if (c == 0) {
			wo.push_back(word);
		} else 
			c = 0;
	}
	return wo;
}        

int main() {
	vector<string> words{"abc","deq","mee","aqq","dkd","ccc"};
	string pattern = "abb";
	vector<string> word = findAndReplacePattern(words,pattern);
	cout << "Final Output - " << endl;
	for (vector<string>::iterator it = word.begin(); it < word.end(); it++) {
		cout << *it << " " << endl;
	}
}

