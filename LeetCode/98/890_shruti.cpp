#include <bits/stdc++.h>
using namespace std;

 vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int i;
        vector<string> result;
        vector<string>::iterator it;
        map<char,char> m;
        string w,temp;
        for(it=words.begin();it!=words.end();it++) {
            cout << "check 1" << endl;
            w=(*it);
            for(i=0;i<pattern.length();i++) {
                cout << "check 2" << endl;
                char p1,c1;
                p1=pattern[i];
                c1=w[i];
                if((!m[p1]) || m[p1]==c1) {
                    cout << "Check 3" << endl;
                    m[p1]=c1;
                    if(i==(pattern.length()-1))
                        result.push_back(w);
                } else {
                    cout << "check 4 " << endl;
                    i=0;
                    m.clear();
                    continue;
                }
                    
            }
        }
        return result;
        
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

