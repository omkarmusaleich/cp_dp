#include <bits/stdc++.h>

using namespace std;

int unboundedknapsack(int v[],int w[],int W,int n)
{
    if(n==-1||W==0)
    {
        return 0;
    }
    if(W>=w[n])
    {
        return max(v[n]+unboundedknapsack(v,w,W-w[n],n),unboundedknapsack(v,w,W,n-1));
    }
    else{
        return unboundedknapsack(v,w,W,n-1);
    }

}

int main()
{
    int v[]={2,3,4,6,5};
    int w[]={2,4,5,6,4};
    int W=27;
    cout<<unboundedknapsack(v,w,W,4)<<endl;
    // top-down approach DP
    int t[5+1][W+1];
    for(int i=1;i<=W;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=5;i++)
    {
        t[i][0]=0;
    }

    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j>=w[i-1])
            {
                t[i][j]=max(v[i-1]+t[i][j-w[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"maximum profit is : "<<t[5][W]<<endl;
    return 0;
}
