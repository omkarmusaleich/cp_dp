#include <bits/stdc++.h>

using namespace std;

int rodcutting(int l[],int v[],int len,int n)
{
    if(len==0 || n==-1)
    {
        return 0;
    }
    if(len>=l[n])
    {
        return max(v[n]+rodcutting(l,v,len-l[n],n),rodcutting(l,v,len,n-1));
    }
    else{
        return rodcutting(l,v,len,n-1);
    }
}

int main()
{
    // it is same as unbounded knapsack
    // given a rod arry indecate length of rods in certain cases it not given than we have 1,2,...N rod length continuolys
    // senond array its correspoding value
    int l[]={1,2,5,6,7};
    int v[]={1,2,6,8,10};
    int length=25;
    cout<<rodcutting(l,v,length,4)<<endl;

    // top-down approach DP
    int t[5+1][length+1];
    for(int i=1;i<=25;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=5;i++)
    {
        t[i][0]=0;
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=length;j++)
        {
            if(j>=l[i-1])
            {
                t[i][j]=max(v[i-1]+t[i][j-l[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"maximum profit from rod after cutting  is "<<t[5][length]<<endl;
    return 0;
}
