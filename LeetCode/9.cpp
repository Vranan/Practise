#include<bits/stdc++.h>
using namespace std;




bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        string y = "";
        string s = to_string(x);
        while (x > 0) {
            y = y + to_string(x%10);
            x = x/10;
        }
        
        cout << "s = " << s << ", y = " << y << endl;
        if (s == y)
            return true;
        
        return false; 
    }
    
int main() {
	bool fs = isPalindrome(121);
	cout << "fs = " << fs << endl;
	return 0;
}
