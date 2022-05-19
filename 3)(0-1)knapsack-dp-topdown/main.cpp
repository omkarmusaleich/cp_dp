#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;


int main()
{
    // if(n==0 || w==0) this base condition in recursion code become initial state of matrix
    int n,W;
    cin>>n>>W;
    int v[n],w[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int t[n+1][W+1];
    // initialise the array
    for(int i=0;i<=W;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        t[i][0]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j>=w[i-1])
            {
                t[i][j]=max(v[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][W]<<endl;
    return 0;
}
