//"Test1ng-Leet=code-Q!"
#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string S) {
        int l = S.length();
        string str(l, '\0');
        int j=0;
        for (int i = S.length()-1; i>=0; i--) {
        	    
                if (((33 <= S[i]) && (S[i] <= 64)) || ((91 <= S[i]) && (S[i] <= 96)))
                    str[i] = S[i];
            
        }
        
        //cout << "str = " << str << endl;
        
         for (int i = S.length()-1; i>=0; i--) {
             
             if ( ((97 <= S[i]) && (S[i] <= 122)) ||   ((65 <= S[i])  && (S[i] <= 90))) {
                 if (str[j] == NULL)
                     str[j] = S[i];
                 else {
                 	 while (str[++j] != NULL);
                     str[j] = S[i];
                 }
                 
                 j++;
             }
         }
         
         
        return str;
    }

int main() {
	cout << "Test1ng-Leet=code-Q!" << endl;
	cout << "   z<*zj" << endl;
	cout << "ghzAb" << endl;
	string st = reverseOnlyLetters("ghzAb");
	cout << "st = " << st << endl;
	return 0;
}

