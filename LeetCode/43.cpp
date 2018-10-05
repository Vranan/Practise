#include<bits/stdc++.h>
using namespace std;

/*
string multiply(string num1, string num2) {
  string res(num1.size() + num2.size(), '0');
  for (int i = num1.size() - 1; i >= 0; i--) {
    cout << "--------------------- i = " << i << ", num1[" << i << "] = " << num1[i] << "---------------------" << endl;
    for (int j = num2.size() - 1; j >= 0; j--) {
        int prod =  (num1[i] - '0') * (num2[j] - '0') +  (res[i + j + 1] - '0');
        res[i+j+1] = (prod % 10) + '0';
        res[i+j] = ((prod /10) + (res[i + j] - '0')) + '0';
        cout << "j = " << j << ", num2[" << j << "] = " << num2[j] << ", prod = " << prod << ", res[" << i+j+1 << "] = " << res[i+j+1] << ", res[" << i+j << "] = " << res[i+j] << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;; 
  }
  //remove the trailing zeros
  int it = res.find_first_not_of("0");
  return ( it < 0  ? "0" : res.substr(it) );
}

*/

string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        string sum(l1+l2, '0');
        for (int i = l1-1; i >= 0; i--) {
            int carry = 0;
            for (int j = l2-1; j >= 0; j--) {
                int mult = (num2[j] - '0')*(num1[i] - '0') + (sum[i+j+1] - '0');   // Initially, sum[i+j+1] is going to store carry.
                sum[i+j] = ((mult/10) + (sum[i+j] - '0')) + '0';
                sum[i+j+1] = ((mult % 10)) + '0';
            }
        }
        return sum;
    }


int main() {
	string mult = multiply("123","456");
	//cout << "mult = " << mult;
	return 0;
}
