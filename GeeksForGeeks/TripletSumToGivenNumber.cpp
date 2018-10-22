
#include <bits/stdc++.h> 
using namespace std; 
  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    // Fix the first element as A[i] 
    cout << "sum = " << sum << endl;
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // Find pair in subarray A[i+1..n-1] 
        // with sum equal to sum - A[i] 
        unordered_set<int> s; 
        int curr_sum = sum - A[i]; 
        cout << "i = " << i << ", curr_sum  =  sum - A[" << i << "] = " << curr_sum << endl;
        for (int j = i + 1; j < arr_size; j++) { 
        	cout << "j = " << j << ", curr_sum - A[" << j << "] = " << curr_sum - A[j] << endl;
			if (s.find(curr_sum - A[j]) != s.end()) {
            	cout << endl << " true " << endl;
                return true; 
            }
            cout << "Insert = A[" << j << "] = " << A[j] << endl;
            s.insert(A[j]); 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
  
    if (find3Numbers(A, arr_size, sum)) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
    return 0; 
} 
