class Solution {
public:
    string addBinary(string a, string b) {
        
        int l = min(a.length(), b.length());
        int m = max(a.length(), b.length());
        string str(max(m,'\0');
        
        int al = a.length();
        int bl = b.length();
        int c = 0;
        while (l-- > 0) {
            
            if ((a[al] == 0) && (b[bl] == 0))  {
                str[m] = 0 + c;
                c = 0;
            } 
            if ((a[al] == 0) || (b[bl] == 0)) {
                 if (1+c > 1) {
                     str[m] = 0;
                     c = 1;
                 } else {
                     str[m] = 1;
                     c = 0;
                 }
            }
            if ((a[al] == 1) && (b[bl] == 1)) {
                str[m] = 0;
                c = 1;
            }
            m--;
            al--;
            bl--;
        }
                   
        
        
    }
};#include<bits/stdc++.h>
using namespace std;



int main() {

	return 0;
}

