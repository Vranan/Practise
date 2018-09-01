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
	
	bool dfs(int graph[][2001], int sz, int group[], int index, int grp) {
		cout << "Inside dfs" << endl;
		group[index] = grp;
		for (int i = 0; i < sz; i++) {
			if (graph[index][i] == 1) {
				if (group[i] == 1)
					return false;
				if (group[i] == 0 && !dfs(graph, sz, group, i, -grp));
					return false;
			}		
		}
		return true;
	}

	bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
		cout << "Inside Bi part" << endl;
		
		int graph[2001][2001];
		vector<vector<int> >::iterator it;
		int sz = 0;
		for (it = dislikes.begin(); it != dislikes.end(); it++) {
			vector<int> d = *it;
			if (!d.empty()) {
				graph[d[0] - 1][d[1] - 1] = 1;
				graph[d[1] - 1][d[0] - 1] = 1;
			}
			else break;
			sz++;
		}
		
		int *group = new int[N];
		for (int i=0; i<N; i++) {
			int grpType = 1;
			if (group[i] == 0 && !dfs(graph, sz, group, i, grpType)) {
				return false;
			}
		}
		return true;
	}

int main() {
	cout << "Inside main" << endl;
	vector<vector<int> > dis(10001);
	int N = 5;
	dis[0].push_back(1);
	dis[0].push_back(2);
	
	dis[1].push_back(2);
	dis[1].push_back(3);
	
	dis[2].push_back(3);
	dis[2].push_back(4);
	
	dis[3].push_back(4);
	dis[3].push_back(5);
	
	dis[4].push_back(1);
	dis[4].push_back(5);
	cout << "Before bi part" << endl;
	bool val = possibleBipartition(N, dis);
	cout << val << endl;
	return 0;
}
