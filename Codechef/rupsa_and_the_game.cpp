#include <bits/stdc++.h>
using namespace std;

int main() {
    short int T,i,j;
    int N,mod_val;
    int sum=0;
    int arr[100001];
    cin >> T;
    while((T--)>0)
    {
        cin >> N;
        i=0;
        sum=0;
        while(i<=(N))
        {
            cin >> arr[i];
            j=0;
            while(j<=i)
            {
                if(j==0)
                    sum = sum + arr[i]*arr[j]*2;
                else if(j>1)
                    sum = sum + arr[i]*arr[j]*pow(2,j);

                    j++;
            }
            i++;
        }
        mod_val = sum % 1000000007;
    }
	cout << mod_val << endl;
	return 0;
}
