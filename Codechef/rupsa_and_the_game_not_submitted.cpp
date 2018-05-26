#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    short int T=1;
    ll N,mod_val,i,j;
    ll sum=0;
    ll arr[100001] = {1,2,1};
    //cin >> T;
    while((T--)>0)
    {
        //cin >> N;
        N=2;
        i=1;
        sum=0;
        while(i<=(N))
        {
            //cin >> arr[i];
            j=0;
            while(j<i)
            {
                cout << "arr[" << i << "] = " << arr[i] << ", arr[" << j << "] = " << arr[j] << " ";
                if(j==0)
                {
                    cout << ", if command";
                    sum = sum + arr[i]*arr[j]*2;
                }
                else
                {
                    cout << ", else command";
                    sum = sum + arr[i]*arr[j]*(ll (pow(2,j)));
                }

                    cout << ", j = " << j << ", sum = " << sum << endl;
                    j++;
            }
            cout << "i = " << i << ", sum = " << sum << " ";
            mod_val = sum % 1000000007;
            i++;
            cout << ", i after ++ = " << i << endl << endl;
        }
    }
	cout << mod_val << endl;
	return 0;
}
