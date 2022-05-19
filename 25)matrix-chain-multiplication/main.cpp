#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;
int t[N][N];
int MCM(int a[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp1=MCM(a,i,k)+MCM(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        // if(ans>temp1)
        // {
        //     ans=temp1;
        // }
        ans=min(ans,temp);
    }
    return t[i][j]=ans;
}

int main()
{
    memset(t,-1,sizeof(t));
    int a[]={20,30,10,20};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<MCM(a,1,3)<<endl;
    return 0;
}
