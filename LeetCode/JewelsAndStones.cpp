#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


public class JewelsAndStones {
    public:
			int numJewelsInStones(string J, string S) {
			   int jew = 0;
			   unordered_map<character, string> hashtable;
			   for (int i = 0; i < J.length(); i++) {
			      hashtable.emplace(J[i], "J");
			   }
			   
			   for (int k = 0; k < S.length(); k++) {
				   if(hashtable[S[i]] == "J") {
					   jew++;
				   }
				   else
					   continue;
			   }
			   return jew;
			}	
}

int main() {
JewelsAndStones js = new JewelsAndStones("aAAbbbb", "aA");
cout << "Output: " << js.numOfJewelsInStones() << endl;
return 0;

}