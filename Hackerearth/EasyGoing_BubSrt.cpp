#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> vect,int N)
{
    int i=0,j=0,k=N,temp=0,check=0;
    for(i=0;i<N;i++)
    {
        k--;
        check=0;
        for(j=0;j<k;j++)
        {
           if(vect[j]>vect[j+1])
           {
             temp=vect[j+1];
             vect[j+1]=vect[j];
             vect[j]=temp;
             check++;
           }
        }
        if(check==0)
           break;
    } 
    return vect;
}

int main() {

    int T=0,M=0,N=0;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        vector<int> vec(N);
        int i=0,max_sum=0,min_sum=0;
        for(vector<int>::iterator it = vec.begin();it < vec.end();it++)
            cin >> *it;

        vec=bubble_sort(vec,N);
        vector<int>::iterator it = vec.begin();
        for(i=0;i<N-M;i++)
        {
          min_sum+=*it;
          it++;
        }
        vector<int>::reverse_iterator rit = vec.rbegin();
        while((N--) >= (N-M))
        {
          max_sum+=*rit;
          rit--;
        }      
        cout << max_sum - min_sum << endl;
    }
	return 0;
}
