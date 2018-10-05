#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string str = "1";
        string s = "";
        
        while (n--) {
            int count = 1;
            s = "";
            int i = 0;
            for (i = 0; i < str.length()-1; i++){
              if (str[i] == str[i+1])
                  count++;
              else {
                    s += to_string(count);
                    s += str[i];
                    count = 1;
              }  
            }
            
            if (count > 1) {
                s += to_string(count);
                s += str[i-1];
            } else {
                s += to_string(1);
                s += str[i-1];
            }
            
            str = s;
        }
        return s;
    }
};


    
int main() {
	string str = countAndSay(4);
	return 0;
}
