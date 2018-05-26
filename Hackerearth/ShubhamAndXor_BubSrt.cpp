#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> vec,int size)
{
    int k=size+1;
    int i=0,j=0,temp=0;
    for(i=0;i<size;i++)
    {
        k--;
        for(j=0;j<k-1;j++)
        {
            if(vec[j]<vec[j+1])
            {
               temp=vec[j];
               vec[j]=vec[j+1];
               vec[j+1]=temp;
            }
        }
    }
    return(vec);
}

int main() {
    int T=0;
    
    cin >> T;
    while(T--)
    {
        int N=0,i=0,count=0;
        cin >> N;
        vector<int> vect(N);
        for(vector<int>::iterator it=vect.begin();it<vect.end();it++)
            cin >> *it;
        vect = bubble_sort(vect,N);  
        for(vector<int>::iterator it=vect.begin();it<vect.end();it++)
        {
            if(*it == *(it+1))
               count++;
        }
        cout << count << endl;
     }

	return 0;
}
