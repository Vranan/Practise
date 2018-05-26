#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
    int N,k,i,j,n;
    ll prod=1,pro=1,min=1;
    int A[100001];
	cin >> N >> k;

	for(i=1;i<=N;i++)
	     cin >> A[i];

    prod=A[1];
    min=A[0]*A[1];
	for(i=0;i<N;i=i+k+1)
	    {
	         if(i==0)
                  min = A[0]*A[1];
             else
                  min = (prod*(A[i]));

	         if((i+k)<N)
                  n=i+k;
             else
                  n=(N-1);

             for(j=i;j<=n;j++)
	          {
	              pro = (prod*A[j])%1000000007;
	              if(pro<min)
	                  min=pro;
              }
             prod=min;
        }
	    cout << prod;
	return 0;
}
