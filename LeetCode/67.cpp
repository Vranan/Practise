#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
        //cout << "a = " << a <<", b = " << b << endl;
	int al = a.length();
        int bl = b.length();

        int l = min(al, bl);
        int m = max(al, bl);
	
        string str(m,'\0');
        

	//cout << "al = " << al << ",  bl = " << bl << ", l = " << l << ", m = " << m << ", str.length() = " << str.length() << endl;
        int c = 0;
	al--;
	bl--;
	m--;	
        while (l-- > 0) {
            
            if ((a[al] == '0') && (b[bl] == '0'))  {
                str[m] = (c == 1) ? '1' : '0';
                c = 0;
            }  else if ((a[al] == '0') || (b[bl] == '0')) {
		str[m] = (c == 1) ? '0' : '1';
		c = (c == 1) ? 1 : 0;		
	    } else if ((a[al] == '1') && (b[bl] == '1')) {
                str[m] = (c == 1) ? '1' : '0';
                c = 1;
            }

	    //cout << "1. str = " << str << endl;
	    al--;
	    bl--;
            m--;            
	}
	
	while (al >= 0) {

		if (a[al] == '1' &&  c == 1) {
			str[m] = '0';
			c = 1;	
		} else if (a[al] == '1' || c == 1) {
			str[m] = '1';
			c = 0;
		} else if (a[al] == '0' && c == 0) {
			str[m] = '0';
			c = 0;
		}

		al--;
		m--;
		//cout << "2. str = " << str << endl;
	}

	while (bl >= 0) {
		if (b[bl] == '1' &&  c == 1) {
			str[m] = '0';
			c = 1;	
		} else if (b[bl] == '1' || c == 1) {
			str[m] = '1';
			c = 0;
		} else if (b[bl] == '0' && c == 0) {
			str[m] = '0';
			c = 0;
		}

		bl--;
		m--;
		//cout << "3. str = " << str << endl;
	}
	
	//cout << "str = " << str << endl;

	if (c == 0)
		return str;
	else {
		string st(str.length()+1,'\0');
		st = '1' + str;
		return st;
	}
}

int main() {
	//cout << "Inside Main" << endl;
	string a = "1111";
	string b = "1111";
	string st = addBinary(a,b);
	//cout << "st = " << st << endl; 
	return 0;
}

	

