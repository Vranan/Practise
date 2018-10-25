#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int sum = 0;
    bool flag = true;
    for (int i = 0; i < s.length(); i++) {
        
        if (!flag) break;
        
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            flag = false;
            break;
        } else if (0 <= s[i]-48 && s[i]-48 <= 9) {
            if (sum == 0) {
                sum += s[i] - 48;
            } else if (sum != 0) {
                sum += s[i]- 48;
                if (sum%2 != 0) {
                    flag = false;
                    break;
                }
                sum = s[i]-48;
            }
        } else 
            sum = 0;
        
    }
    
    if (flag)
        cout << "valid";
    else 
        cout << "invalid";
    return 0;
}

