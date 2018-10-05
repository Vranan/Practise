#include<bits/stdc++.h>
using namespace std;

 int strStr(string haystack, string needle) {
        if (needle == "") 
            return 0;
        
                                            
        if (needle.length() > haystack.length())
            return -1;
            
        cout << "haystack.length() = " << haystack.length() << ", needle.length() = " << needle.length() << endl;
                                     
         for (int i = 0; i < haystack.length(); i++) {
            cout << "------- i = " << i << endl;
			int j = 0;
            while ((haystack[i] == needle[j]) && (i < haystack.length())) {
                i++;
                j++;
                cout << "  i = " << i << ", j = " << j << endl;
            }
             
			cout << "------- j = " << j << ", i = " << i << endl;
			
			//if (j ==  
             
            if (j == needle.size()) {
            	cout << " i - j = " << i - j << endl;
                return (i - j);
            }
             
         }
        return -1;
}

int main() {
	int v = strStr("mississippi","issip");
	//int v = strStr("a", "a");
	cout << "v = " << v << endl;
}
