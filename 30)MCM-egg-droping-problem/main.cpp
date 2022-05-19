#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;
int t[N][N];
/*
int solve(int e,int f)
{
    if(f==0 || e==0)
    {
        return f;
    }
    if(f==1)
    {
        return 1;
    }
    int mini=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(solve(e,f-k),solve(e-1,k-1));
        mini=min(mini,temp);
    }
    return mini;
}

*/

// memoziation +recursion
int solveop(int e,int f)
{
    if(f==0 || e==0)
    {
        return f;
    }
    if(f==1)
    {
        return 1;
    }
    if(t[e][f]!=-1)
    {
        return t[e][f];
    }
    int ans=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(solveop(e,f-k),solveop(e-1,k-1));
        ans=min(ans,temp);
    }

    return t[e][f]=ans;

}
int main()
{
    // there are f floors and we have e eggs and we have to find minimum number of attempt required to identify
    // threshould floor (the floor from above floor if we can drop a egg than it break ans if we can drop from
    // below than it cant break and we reuse that egg again but attempt increase by +1
    // we can find the minimum attempt required for worst case when floor at the top like that case .
    int e=5,f=10; // e- number of eggs     f-number of floors
    //cout<<solve(e,f)<<endl;

    // optimal
    memset(t,-1,sizeof(t));
    cout<<solveop(e,f)<<endl;
    for(int i=0;i<=e;i++)
    {
        for(int j=0;j<=f;j++)
        {
            if(t[i][j]==-1)
            {
                cout<<-1<<"  ";
            }
            else{
                cout<<t[i][j]<<"   ";
            }

        }
        cout<<endl;
    }
    return 0;
}
