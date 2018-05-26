#include<bits/stdc++.h>
using namespace std;

int main() {
    short int T,i,amber=0,brass=0;
    string S;
	cin >> T;
	while((T--)>0)
	{
	    cin >> S;
	    string::iterator it;
	    for(it=S.begin();it!=S.end();it++)
	    {
	        if(*it == "a")
	           amber++;
	        else
	           brass++;
	    }
	    cout << min(amber,brass) << endl;
	}
	return 0;
}
