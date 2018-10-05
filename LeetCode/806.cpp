#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
	map<int,int> m;
	for (int i = 0; i < bills.size(); i++) {
		cout << "1. i = " << i << ", bills[" << i << "] = " << bills[i] << endl;
		cout << "2. m[5] = " << m[5] << ", m[10] = " << m[10] << ", m[20] = " << m[20] << endl;
		m[bills[i]]++;
		cout << "3. m[5] = " << m[5] << ", m[10] = " << m[10] << ", m[20] = " << m[20] << endl;
		int diff = bills[i] - 5;
		cout << "4. diff = " << diff << endl;
		if (diff == 0){
			cout << "continue" << endl;
			continue;
		}
		int rem;
		int mult;
		if ((m[20] != 0) && (diff >= 20)) {
			cout << "----- m[20] -----" << endl;
			rem = diff%20;
			mult = diff/20;
			m[20] -= mult;
			cout << "5. m[5] = " << m[5] << ", m[10] = " << m[10] << ", m[20] = " << m[20] << endl;
			if (rem == 0) {
				continue;
			} else 
				diff = rem;
				
			cout << "6. diff = " << diff << endl;
		}
		
		
		
		if ((m[10] != 0) && (diff >= 10)) {
			cout << "----- m[10] -----" << endl;
			rem = diff%10;
			mult = diff/10;
			m[10] -= mult;
			cout << "8. m[5] = " << m[5] << ", m[10] = " << m[10] << ", m[20] = " << m[20] << endl;
			if (rem == 0)
				continue;
			else 
				diff = rem;
				
			cout << "7. diff = " << diff << endl;
		} 
		
		
		
		
		if ((m[5] != 0) && (diff >= 5)) {
			cout << "----- m[5] -----" << endl;
			rem = diff%5;
			mult = diff/5;
			m[5] = (m[5] - mult) > 0 : m[5] - mult
			cout << "10. m[5] = " << m[5] << ", m[10] = " << m[10] << ", m[20] = " << m[20] << endl;
			if (rem == 0) 
				continue;
			else 
				diff = rem;
				
			cout << "9. diff = " << diff << endl;
		}
		
		
		
		
		if (diff)
			return false; 
	}     
	cout << "TRUE" << endl;   
	return true;
}

int main(){
	
	vector<int> bills{5,5,5,10,5,5,10,20,20,20};
	bool resp = lemonadeChange(bills);
	cout << "response = " << resp << endl;
	return 0;
}
