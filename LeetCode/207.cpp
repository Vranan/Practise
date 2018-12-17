#include<bits/stdc++.h>
using namespace std;


vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) {		
        	cout << pre.second << " " << pre.first << endl;
            graph[pre.second].insert(pre.first);
        }
        return graph;
}

vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
    vector<int> degrees(graph.size(), 0);
    for (auto neighbors : graph)
        for (int neigh : neighbors) {
            degrees[neigh]++;
            cout << "neigh = " << neigh << ", degrees[" << neigh << "] = " << degrees[neigh] << endl;
        }
    return degrees;
}
    
 bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            cout << "i = " << i << endl;
            for (; j < numCourses; j++) {			
            	cout << "j = " << j << ", degrees[" << j << "] = " << degrees[j] << endl;
                if (!degrees[j]) break;
            }
            cout << "j = " << j << endl;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        
        return true;
}
    



int main() {
	
	vector<pair<int, int>> pre;
	pre = {{0,1},{2,1},{2,3},{3,1}};
	bool res = canFinish(4,pre);
	cout << "res = " << res << endl;
	return 0;
}

