/* 
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.
Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
*/

#include <bits/stdc++.h>
using namespace std;

typedef long int64;
int graph[2001][2001];
	
	bool dfs(int graph[][2001], int sz, int group[], int index, int grp) {
		cout << "Inside dfs" << endl;
		group[index] = grp;
		for (int i = 0; i < sz; i++) {
			if (graph[index][i] == 1) {
				if (group[i] == true) {
					cout << "1. false" << endl;
					return false;
				}
				if (group[i] == false && !dfs(graph, sz, group, i, -grp)) {
					cout << "2. false" << endl;
					return false;
				}
					
			}		
		}
		cout << "3. true" << endl;
		return true;
	}
	

	bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
		cout << "Inside Bi Part" << endl;
		int sz = 0;
		for (int it = 0; it < dislikes.size(); it++) {
			vector<int> d = dislikes[it];
			cout << "4. it = " << it << ", d[0] = " << d[0] << ", d[1] = "<< d[1] << endl;
			if (!d.empty()) {
				graph[d[0] - 1][d[1] - 1] = 1;
				graph[d[1] - 1][d[0] - 1] = 1;
			}
			else break;
			sz++;
			cout << "5. size = " << sz << endl;
		}
		
		int *group = new int[N];
		for (int i=0; i<N; i++) {
			int grpType = true;
			if (group[i] == 0 && !dfs(graph, sz, group, i, grpType)) {
				cout << "6. false" << endl;
				return false;
			}
		}
		cout << "7. true" << endl;
		return true;
	}

int main() {
	// cout << "Inside main" << endl;
	
	memset(graph,0,sizeof graph);
	vector<vector<int> > dis(10001);
	int N = 5;
	dis[0].push_back(1);
	dis[0].push_back(2);
	
	dis[1].push_back(1);
	dis[1].push_back(3);
	
	dis[2].push_back(2);
	dis[2].push_back(4);
	
	/* dis[2].push_back(3);
	dis[2].push_back(4);
	
	dis[3].push_back(4);
	dis[3].push_back(5);
	
	dis[4].push_back(1);
	dis[4].push_back(5);
	*/
	// cout << "Before bi part" << endl;
	bool val = possibleBipartition(N, dis);
/*	if (val == 0)
		cout << "False" << endl;
	else if (val == 1)
		cout << "True" << endl;
	else 
		cout << "Not a valid condition" << endl;
		*/
	return 0;
}
