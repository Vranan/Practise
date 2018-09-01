#include<bits/stdc++.h>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
	//cout << "query_row = " << query_row << ", query_glass = " << query_glass << endl << endl << endl;
	
	if (poured == 1 && query_row == 0 && query_glass == 0)
		return 1.0;
		
    double vol[100][100] = {0.0};
    vol[0][0] = poured;
    //cout << "vol[" << 0 << "][" << 0 << "] = " << vol[0][0] << endl;
    double wtx1 = 0.0, wtx2 = 0.0;
    for (int i = 1; i <= query_row; i++) {
    	 //cout << " --------------------- i = " << i << " --------------------- " << endl;
    	for (int j = 0; j < (i + 1); j++) {
    		//cout << "j = " << j << endl;
    		if (j == 0)  {
    			wtx1 = vol[i-1][j];
    			//cout << "1. wtx1 = " << wtx1 << endl;
    			if (wtx1 > 1) 
    				vol[i][j] = (wtx1-1)/2;
    			
			} else if (j == i) {
				wtx1 = vol[i-1][j-1];
				//cout << "2. wtx1 =  " << wtx1 << endl;
				if (wtx1 > 1)
					vol[i][j] = (wtx1 - 1)/2;
			} 
			else {
				//cout << "3. wtx1 = " << wtx1 << ", wtx2 = " << wtx2 << endl;
				wtx1 = (vol[i-1][j-1]);
				wtx2 = (vol[i-1][j]);
				if (wtx1 > 1) {
					vol[i][j] += (wtx1 - 1)/2;
				}
					
				if (wtx2 > 1) {
					vol[i][j] += (wtx2 - 1)/2;
				} 
				
			}	
			//cout << "vol[" << i << "][" << j << "] = " << vol[i][j] << endl;		
		}
	}
	// cout << "query" << endl;
	double fv = vol[query_row][query_glass];
	if (fv >= 1)
		fv = 1;
	//cout << "fv = " << fv << endl;
	
	/*cout << endl << endl;
	cout << "poured = " << poured << endl;
	cout << vol[query_row-1][query_glass-1] << endl;
	int ij_hold = vol[query_row-1][query_glass-1] * poured;
	cout << "ij_hold = " << ij_hold << endl;
	int fv = (ij_hold >= 1) ? 1 : ij_hold;*/
	return (fv);
}

int main() {
	double ct = champagneTower(2,2,0);
	cout << "ct = " << ct << endl;
	return 0;
}





/*
    	
    cout << "query_row = " << query_row << ", query_glass = " << query_glass << endl;
				cout << "1. vol[" << i << "][" << j << "] = " << vol[i][j] << endl;
    			*/
