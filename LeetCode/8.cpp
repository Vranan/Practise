#include<bits/stdc++.h>
using namespace std;

public:
    int myAtoi(string str) {
     
        if (str.size() == 0)
            return 0;
        
        bool t = false;
        int i  = 0;
        long res = 0;
        while (str[i] == ' ') i++;
           
        if (i == str.size())
            return 0;
        if (i < str.size() && (str[i]-'0' > 9 || str[i]-'0' < 0) && str[i] != '-')
            return 0;
       
        if (str[i] == '-' && (str[i+1]-'0' <= 9 || str[i+1]-'0' >= 0)) {
            res = str[i+1] - '0';
            i = i + 2;
        } else if (str[i]-'0' <= 9 || str[i]-'0' >= 0) {
            res = str[i] - '0';
            i = i + 1;
        }
        cout << "i = " << i << " res = " << res << endl; 
      
        int mult = 10;
        for (;i <= str.length()-1; i++) {
            
            if (str[i]-'0' > 9 || str[i]-'0' < 0) {
                cout << "Inside " << endl;
                break;
            } else {
                    string temp = to_string(res);
                    if (temp.size() == 10)
                        res = INT_MAX;
                    else {
                        //cout << "1. " << res << endl;
                        res = res*mult + int(str[i] - '0');
                        //mult = mult*10;
                    }
            }
            
            cout << str[i] << " -- " << res << endl;
        }
        
        if (t) {
            res = (res >= INT_MAX) ? INT_MIN : -res;
        } 
        
        
        return res;
    } 



int main() {

	return 0;
}

