#include <bits/stdc++.h>
using namespace std;

void merge(string st[],int l,int m,int r)
{
    int n1=m-l+1,n2=r-m,k=0,i=0,j=0;
    string left[n1], right[n2];
    for(i=0;i<n1;i++)
         left[i] = st[l+i];
    for(j=0;j<n2;j++)
         right[j] = st[m+j+1];
  
     i=0,j=0,k=l;
     while(i<n1 && j<n2)
     {
         if((left[i]).length() <= (right[j]).length())
         {
            st[k] = left[i];
            i++;
         }
         else
         {
            st[k] = right[j];
            j++;
         }
         k++;
     }
     
     while(i<n1)
     {
        st[k] = left[i];
        i++;
        k++;
     }
     while(j<n2)
     {
         st[k] = right[j];
         j++;
         k++;
     }
}

void merge_sort(string stri[],int l,int r)
{
    if(l<r)
    {
       int m = l+(r-l)/2;
       merge_sort(stri,l,m);
       merge_sort(stri,m+1,r);
       merge(stri,l,m,r);
    }
}

int main() {
    string str[50];
    int T=0;
    scanf("%d ", &T);
    while(T--)
    {
        string line;
        getline(cin, line);
        stringstream stream(line);
        int n=0;
        while(stream >> str[n]) ++n;
        merge_sort(str,0,n-1);
        int i=0;
        for(i=0;i<n;i++)
            cout << str[i] << " ";
        cout << endl;
    }
	return 0;
}
