#include <bits/stdc++.h>

using namespace std;
long count1=0;
const int M=1e9+7;
//-------------------------------------------------------------------------

bool counta(vector<int>&a,int val,int k,int i)
{
     if(i==0 || k==0)
     {
         if(k==0)
         {

             return false;
         }
         if(i==0)
         {

             return true;
         }
     }
     if(k!=a[i+1] && k!=a[i-1])
     {

         a[i]=k;
         bool y=counta(a,val,val,i-1);

         if(y)
         {
             count1=(count1+1)%M;
         }
         a[i]=0;
         counta(a,val,k-1,i);

     }
     else{
          counta(a,val,k-1,i);
     }


 }

 //---------------------------------------------------------------------------

int main()
{
    //761 99 1
    int n=10;
    int k=5;
    int x=1;
    vector<int>v(n,0);
    v[0]=1;
    v[n-1]=x;
    counta(v,k,k,n-2);
    cout<<count1<<endl;
    return 0;
}
