#include<bits/stdc++.h>
using namespace std;

 int compress(vector<char>& a) {
    int i = 0, cnt = 0, t = 0;
    for (int j = 0; j < a.size(); ++j)  {
		cout << "j = " << j << endl;
		if (j+1 == a.size() || a[j+1] != a[j]) {
			cout << "--------- Inside if ---------" << endl;
            int m = t;
            cout << "m = " << m << endl;
            a[t++] = a[j];
            cout << "t - 1 = " << t - 1 << ", a[" << j << "] = " << a[j] << endl;
            
			if (j >= i + 1) {
            	cout << "j - i + 1 = " << j - i + 1 << endl;
                string s = to_string(j-i+1);
                for (char c:s) a[t++] = c;
            }
            
            i = j + 1;
            cnt += t-m;
            cout << "cnt = " << cnt  << endl;
            cout << "--------- If Ends ---------" << endl;
        }
    }
        return cnt;
    }

int main() {
	vector<char> myvec;
	myvec = {'a','a','b','b','c','c','c'};
	//myvec = {"a","a","b","b","c","c","c"};
	int a = compress(myvec);
	cout << "a = " << a << endl;
	return 0;
}

