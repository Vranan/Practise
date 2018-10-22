
// CPP program to check given number number y 
// is power of x 
#include <iostream> 
#include <math.h> 
using namespace std; 
  
bool isPower(int x, int y) 
{ 
    // logarithm function to calculate value 
    int res1 = ceil(log(y) / log(x)); 
    double res2 = log(y) / log(x); // Note : this is double 
  	cout << res1 << " " << res2 << endl;
    // compare to the result1 or result2 both are equal 
    return (res1 == res2); 
} 
  
// Driven program 
int main() 
{ 
    cout << isPower(3, 243) << endl; 
    return 0; 
} 
