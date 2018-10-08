/* 

B. Mike and Shortcuts time limit per test3 seconds memory limit per test256 megabytes inputstandard input output standard output
Recently, Mike was very busy with studying for exams and contests. Now he is going to chill a bit by doing some sight seeing in the city.

City consists of n intersections numbered from 1 to n. Mike starts walking from his house located at the intersection number 1 and goes along some sequence of intersections. Walking from intersection number i to intersection j requires |i - j| units of energy. The total energy spent by Mike to visit a sequence of intersections p1 = 1, p2, ..., pk is equal to  units of energy.

Of course, walking would be boring if there were no shortcuts. A shortcut is a special path that allows Mike walking from one intersection to another requiring only 1 unit of energy. There are exactly n shortcuts in Mike's city, the ith of them allows walking from intersection i to intersection ai (i ≤ ai ≤ ai + 1) (but not in the opposite direction), thus there is exactly one shortcut starting at each intersection. Formally, if Mike chooses a sequence p1 = 1, p2, ..., pk then for each 1 ≤ i < k satisfying pi + 1 = api and api ≠ pi Mike will spend only 1 unit of energy instead of |pi - pi + 1| walking from the intersection pi to intersection pi + 1. For example, if Mike chooses a sequence p1 = 1, p2 = ap1, p3 = ap2, ..., pk = apk - 1, he spends exactly k - 1 units of total energy walking around them.

Before going on his adventure, Mike asks you to find the minimum amount of energy required to reach each of the intersections from his home. Formally, for each 1 ≤ i ≤ n Mike is interested in finding minimum possible total energy of some sequence p1 = 1, p2, ..., pk = i.

Input
The first line contains an integer n (1 ≤ n ≤ 200 000) — the number of Mike's city intersection.

The second line contains n integers a1, a2, ..., an (i ≤ ai ≤ n , , describing shortcuts of Mike's city, allowing to walk from intersection i to intersection ai using only 1 unit of energy. Please note that the shortcuts don't allow walking in opposite directions (from ai to i).

Output
In the only line print n integers m1, m2, ..., mn, where mi denotes the least amount of total energy required to walk from intersection 1 to intersection i.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector< pair<int, ll> > G[2000001];


void dijkstra (int N) {
	int D[200001];
	for (int i = 1; i <= N; i++) {
		D[i] = 1e8;
	}
	D[1] = 0;
	queue<pair<int,ll> > myq;
	myq.push(make_pair(0,1));
	while (!myq.empty()) {
		pair<int, ll> frnt = myq.front();
		myq.pop();
		int u = frnt.second;
		if (D[u] < frnt.first)
			continue;
		vector< pair<int,ll> >::iterator it;
		for (it = G[u].begin(); it != G[u].end(); it++) {
			int v = (*it).second;
			int w = (*it).first;
			if (D[v] > D[u]+w) {
				D[v] = D[u]+w;
				myq.push(make_pair(D[v], v));
			}
		}	
	}
	for (int i = 1; i <= N; i++) {
		cout << D[i] << " ";
	}
	cout << endl;
	return;
}


int main() {
	int n,a;
	cin >> n;
	for (int i = 1;i <= n; i++) {
		cin >> a;
		if (i == n) {
			G[i].push_back(make_pair(1,a));
			continue;
		}
		G[i].push_back(make_pair(1, i+1));
		G[i+1].push_back(make_pair(1, i));
		G[i].push_back(make_pair(1, a));
	}
	dijkstra(n);
	return 0;
}
