#include <iostream>
using namespace std;

int main() {
    long long n,k,i,no,count=0;
	cin >> n >> k;
	for(i=0;i<n;i++)
	{
	    cin >> no;
	    if(no%k == 0)
	         count++;
	}
	cout << count;
	return 0;
}
