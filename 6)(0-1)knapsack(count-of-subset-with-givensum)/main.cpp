#include <iostream>

using namespace std;

int countsubset(int a[],int w,int n,int countsub)
{
    if(n==-1||w==0)
    {
        if(w==0)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    if(w>=a[n])
    {
        return countsub+=(countsubset(a,w-a[n],n-1,countsub)+countsubset(a,w,n-1,countsub));
    }
    else{
        return countsub+=(countsubset(a,w,n-1,countsub));
    }
}

int main()
{
    int a[]={2,3,5,6,8,10,1};
    int w=10;
    // recursive way
    //cout<<countsubset(a,w,6,0)<<endl;

    // top down approach DP
    int t[7+1][w+1];
    for(int i=1;i<=w;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=7;i++)
    {
        t[i][0]=1;
    }

    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j>=a[i-1])
            {
                t[i][j]=(t[i-1][j-a[i-1]]+t[i-1][j]);
            }
            else{
                t[i][j]=(t[i-1][j]);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<=7;i++)
    {
        for(int j=0;j<=w;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"count of subset "<<t[7][w]<<endl;
    return 0;
}
