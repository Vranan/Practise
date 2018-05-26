#include <iostream>
using namespace std;

int main()
{
    int S,Ni,Hi,temp=1,i,no;
    cin >> S;
    while(S--)
    {
        cin >> Ni;
        if(Ni%2 == 0)
        {   
            while(Ni--)
              cin >> Hi;
              
            cout << "no" << endl;
        }    
       else {         
        no = 0; 
        for(i = 1;i <= Ni;i++)
        {
            cin >> Hi;
            //cout << "Hi.1 = " << Hi << ", ";
            if(Hi != 1 && i == 1)
            {
                no = 1;
            }
            else if((Hi != (temp+1)) && (i<=(Ni+1)/2) && (i != 1))
            {   
                no = 1;
            }
            else if ((Hi != (temp-1)) && (i>(Ni+1)/2))
            {
                no = 1;
            }
            temp = Hi;
        }
        
        if((temp == 1) && (i == Ni+1) && (no == 0))
            cout << "yes";
        else if(((temp != 1) && (i == Ni+1)) || (no == 1))
            cout << "no";
            
        cout << endl; 
       }
    }
    return 0;
}