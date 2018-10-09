#include<bits/stdc++.h>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
	int sa = 0;
	int sz = grid.size();
	int mi1 = 0;
	int mi2 = 0;
	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++) {
			// cout << "0. grid[" << i << "][" << j << "] = " << grid[i][j] << endl;
			if (grid[i][j] == 0) {
				// sa+=1;
				// cout << "1. sa = " << sa << endl;
				continue;
			}
			sa+=((grid[i][j]*4)+2);
			// cout << "2. sa = " << sa << endl;
			if ((i == sz-1) && (j == sz-1)) {
				// cout << "check 2: " << endl; 
				continue;
			} else if (i == sz-1) {
				mi1 = 0;
				mi2 = min(grid[i][j],grid[i][j+1]);
				// cout << "check 3: " << "mi1 = " << mi1 << ", mi2 = " << mi2 << endl; 
			} else if (j == sz-1) {
				mi1 = min(grid[i][j],grid[i+1][j]);
				mi2 = 0;
				// cout << "check 4: " << "mi1 = " << mi1 << ", mi2 = " << mi2 << endl; 
			} else if ((i != (sz-1)) || (j != (sz-1)))	{ 
				 mi1 = min(grid[i][j],grid[i+1][j]);
				 mi2 = min(grid[i][j],grid[i][j+1]);
				 // cout << "check 1: " << "mi1 = " << mi1 << ", mi2 = " << mi2 << endl; 	
			} 
			sa-=((2*mi1)+(2*mi2));
			// cout << "3. sa = " << sa << endl;
		}
		// cout << endl;
	}
	// cout << "4. sa = " << sa << endl;
	return sa;
}

int main() {
	vector<vector<int> > grid{{1,1,1},{1,0,1},{1,1,1}};
	for(int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {
			cout << "grid["<< i << "][" << j << "] = " << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	int sa = surfaceArea(grid);
	cout << "2. sa = " << sa << endl;
	return 0;
}
