#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin >> T;
	while(T--)
	{
	    int N;
	    cin >> N;
	    //cout << "N = " << N << endl;
	    int v;
	    int s = ((N)*(N+1))/2;
	    int i = N;
	    //cout << "s = " << s << endl;
	    while (i-- > 1) {
	        cin >> v;
	        //cout << "v = " << v << ", s = " << s;
	        if (v > 0 && v < N+1)
	            s = s - v;
	        //cout << ", s -v = " << s << endl;
	    }
	    
	    cout << s << endl;
	    
	}
	return 0;
}
