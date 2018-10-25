#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> cv[N];
	int i = 0;
	while (i < N)
	  cin >> cv[i++];

	i = 0;
	while (i < N)
	  cout << cv[i++];
	
	return 0;
}
