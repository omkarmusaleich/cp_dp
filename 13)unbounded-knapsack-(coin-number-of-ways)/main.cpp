#include <iostream>

using namespace std;

int coinways(int c[],int sum,int n)
{
    if(n==-1 || sum==0)
    {
        if(sum==0)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    if(sum>=c[n])
    {
        return (coinways(c,sum-c[n],n)+coinways(c,sum,n-1));
    }
    else{
        return coinways(c,sum,n-1);
    }
}

int main()
{
    // coin[]={1,2,3};
    // find the number of ways that you can make sum =5 each coin take any number of time
    int coin[]={1,2,3,5};
    int sum=5;
    cout<<coinways(coin,sum,3)<<endl;

    // top-down approach DP
    int t[4+1][sum+1];
    for(int i=1;i<=sum;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=4;i++)
    {
        t[i][0]=1;
    }

    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=coin[i-1])
            {
                t[i][j]=(t[i][j-coin[i-1]]+t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[4][sum]<<endl;
    return 0;
}
