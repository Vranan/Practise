#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
    int N,k,i,j,n;
    ll prod=1,pro=1,min=1;
    int A[100001]={1,2,3,4};
	//cin >> N >> K;
	N=4;k=2;

	//for(i=1;i<=N;i++)
	  //   cin >> A[i];

    prod=A[1];
    min=A[0]*A[1];
	for(i=0;i<N;i=i+k+1)
	    {
	        if(i==0)
                min = A[0]*A[1];
            else
                min = (prod*(A[i]))%1000000007;

	        cout << "i = " << i << ", min = " << min << "  "  << endl;

	     if((i+k)<N)
             n=i+k;
         else
             n=(N-1);

           for(j=i;j<=n;j++)
	        {
	            pro = (prod*A[j])%1000000007;
	            if(pro<min)
	                min=pro;

	                cout << "j = " << j << ", A[" << j << "] = " << A[j] << ", pro = " << pro << ", " << "min = " << min << " " << endl;
	        }


	        prod=min;
	        cout << ", prod = " << prod << " " << endl << endl;

	    }

	    cout << endl << "final value prod = " << prod;

	return 0;
}
