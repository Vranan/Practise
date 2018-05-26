#include<bits/stdc++.h>
using namespace std;

int main() {
	short int T,N,i,one1,one2,two1,two2,three1,three2,four1,four2,five1,five2,six1,six2,unknown;
	//int arr[100] = {1,1,2,2,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,7,7,6,6,6,6,5,5,5,4,4,4,3,3,2,2,1,1};
	int arr[100] = {1,1,2,2,3,3,8,8,8,5,5,5,6,6,6,6,7,7,7,7,6,6,6,6,5,5,5,8,8,8,3,3,2,2,1,1};
	N=36;
	cin >> T;
	while((T--)>0)
	{
	    //cin >> N;
	    i=0;
	    one1=0,one2=0,two1=0,two2=0,three1=0,three2=0,four1=0,four2=0,five1=0,five2=0,six1=0,six2=0,unknown=0;
	    while(arr[i]!=7)
	        {
	            //cin >> arr[i];
	            cout << i << " - " << arr[i] << ", ";
	            if(arr[i]==1)
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
cout << endl;
	        while((++i)<N)
	        {
	            //cin >> arr[i];
	            cout << i << " - " << arr[i] << ", ";
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
cout << endl;
cout << endl << "one1 = " << one1 << ", two1 = " << two1 << ", three1 = " << three1 << ", four1 = " << four1 << ", five1 = " << five1 << ", six1 = " << six1 << endl;
cout << "one2 = " << one2 << ", two2 = " << two2 << ", three2 = " << three2 << ", four2 = " << four2 << ", five2 = " << five2 << ", six2 = " << six2 << endl;


        if(unknown == 0)
        {
	       if(one1==one2 and two1==two2 and three1==three2 and four1==four2 and five1==five2 and six1==six2)
	             cout << "yes" << endl;
	        else
	             cout << "no" << endl;
        }
        else
             cout << "no" << endl;


	}
	return 0;
}
