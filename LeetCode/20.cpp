#include<bits/stdc++.h>
using namespace std;


bool isValid(string s) {
	cout << "s = " << s << ", s.length = " << s.length() << endl;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
        	
            cout << "s[" << i << "] = " << s[i] << endl;
            
            switch(s[i]) {
            	case '(':
            		st.push(s[i]);
            		break;
            	case '{':
            		st.push(s[i]);
            		break;
            	case '[':
            		st.push(s[i]);
            		break;
            	case ')':
            		if (!st.empty() && st.top() == '(')
            			st.pop();
            		else
            			return false;
            		break;
				case '}':
            		if (!st.empty() && st.top() == '{')
            			st.pop();
            		else
            			return false;	
            		break;
				case ']':
            		if (!st.empty() && st.top() == '[')
            			st.pop();
            		else
            			return false;	
            		break;
				default:
					return false;			
			}
        }
        if (!st.empty())
        	return false;
        return true;
        
}

int main() {
	bool a = isValid("]");
	cout << "a = " << a << endl;
	return 0;
}
