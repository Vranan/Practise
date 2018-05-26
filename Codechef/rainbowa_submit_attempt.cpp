#include <bits/stdc++.h>
using namespace std;

int main() {
	short int T,N,i,one1,one2,two1,two2,three1,three2,four1,four2,five1,five2,six1,six2,unknown;
	int arr[100];
	cin >> T;
	while((T--)>0)
	{
	    cin >> N;
	    i=0;
	    one1=0;
	    one2=0;
	    two1=0;
	    two2=0;
	    three1=0;
	    three2=0;
	    four1=0;
	    four2=0;
	    five1=0;
	    five2=0;
	    six1=0;
	    six2=0;
	    unknown=0;
	    while(i<N)
	        {
	            cin >> arr[i];
	            if(arr[i]==7)
	                 break;
	            else if(arr[i]==1)
	                 one1++;
	            else if(arr[i]==2)
	                 two1++;
	            else if(arr[i]==3)
	                 three1++;
	            else if(arr[i]==4)
	                 four1++;
	            else if(arr[i]==5)
	                 five1++;
	            else if(arr[i]==6)
	                 six1++;
                else
                     unknown++;

	                 i++;
	        }

	        while((++i)<N)
	        {
	            cin >> arr[i];
	            if(arr[i]==7)
	                continue;
	            else if(arr[i]==1)
	                 one2++;
	            else if(arr[i]==2)
	                 two2++;
	            else if(arr[i]==3)
	                 three2++;
	            else if(arr[i]==4)
	                 four2++;
	            else if(arr[i]==5)
	                 five2++;
	            else if(arr[i]==6)
	                 six2++;
                else
                     unknown++;
	        }

         if(unknown==0)
         {
	        if(one1==one2 and two1==two2 and three1==three2 and four1==four2 and five1==five2 and six1==six2)
	             cout << "yes" << endl;
	        else
	             cout << "no" << endl;
         } else
                 cout << "no" << endl;

	}
	return 0;
}
