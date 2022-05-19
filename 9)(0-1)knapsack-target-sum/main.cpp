#include <bits/stdc++.h>

using namespace std;

int targetsum(int a[],int n,int w,int sum)
{
    if(n==-1)
    {
        if(sum==w)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    return (targetsum(a,n-1,w,sum+a[n])+targetsum(a,n-1,w,sum-a[n]));
}

int main()
{
    int a[]={1,1,2,3,1};
    int w=0;
    cout<<targetsum(a,4,w,0)<<endl;
    // top-down approach DP
    // here we assigne a sign to it number is array (+,-)
    // and sum of them should be given sum (w);
    // 0=+1 +1 +2 -3 -1
    // it is similer  to differ between two sub set
    // s1-s2=diff
    // (1+1+2)-3-1
    // (1+1+2)-(3+1)
    // s1=diff+arraysum/2
    // than find count of s1 set
    int s1=(accumulate(a,a+5,0)+w)/2;
    cout<<s1<<endl;
    int t[5+1][s1+1];
    for(int i=1;i<=s1;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=5;i++)
    {
        t[i][0]=1;
    }

    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=s1;j++)
        {
            if(j>=a[i-1])
            {
                t[i][j]=t[i-1][j-a[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"such number of combination is "<<t[5][s1]<<endl;
    return 0;
}
