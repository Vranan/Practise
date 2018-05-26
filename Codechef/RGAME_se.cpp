#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
#define mod 1000000007
#define ll long long
using namespace std;
ll a[100001]={1,2,1};
ll b[100001];
void precompute()
{
    b[0]=2;
    b[1]=2;
    for(int i=2;i<100001;i++)
        b[i]=(2*b[i-1])%mod;
}

int main()
{
    precompute();
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        //cin>>n;
        //n=n+1;
        n=3;
        //cin>>a[0];

        ll c[n];
        ll p[n];
        p[0]=(b[0]*a[0])%mod;
        c[0]=p[0];
        cout << "p[0] = " << p[0] << " " << ", c[0] = " << c[0] << endl;
        for(int i=1;i<n;i++)
        {
            //cin>>a[i];
            p[i]=(a[i]*b[i])%mod;
            c[i]=(c[i-1]+p[i])%mod;
            cout << "p[" << i << "] = " << p[i] << " " << ", c[" << i << "] = " << c[i] << endl;

        }
         if(n>=2){
            ll ans = a[0]*a[1]*2;
            cout << "ans = " << ans << endl;
            for(int i=2;i<n;i++)
            {
                ans=(ans*2)%mod;
                a[i]=(a[i]*c[i-1])%mod;
                cout << "ans = " << ans << ", a[" << i << "] = " << a[i] << ", c[" << i-1 << "] = " << c[i-1] << " ";
                ans=(ans+a[i])%mod;
                cout << "ans = " << ans << endl;
            }
            cout<<ans<<endl;
         }
         else
            cout<<"0"<<endl;
    }
}
