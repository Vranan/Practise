#include <bits/stdc++.h> 
using namespace std;

int main() {
	string str = "Vinit Kumar";
	unordered_map<char, char> m;
	for (int i = 0; i < str.length(); i++) {
		char w = str[i];
		m[w] = 'h';
		cout << str[i];
		cout << m[w];
	}
}
