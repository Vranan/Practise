#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        cout << s1 << " " << s2 << endl;

        int j = 0;
        int c = 0;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == s1[j])
                c++;
            else 
                c = 0;
            
            if (c == s1.length())
                return true;
            
            j++;
            
        }
        return false;
}


int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool res = checkInclusion(s1, s2);
    cout << res << endl;
    return 0;
}
