#include <bits/stdc++.h>

using namespace std;

int a[4][4];

bool issafe(int x,int y,int n)
{
    int row=0;
    for(row=0;row<x;row++)
    {
        if(a[row][y]==1)
        {
            return false;
        }
    }

    row=x;
    int col=y;
    while(row>=0 && col>=0)
    {
        if(a[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }

    row=x,col=y;
    while(row>=0 && col<n)
    {
        if(a[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQuene(int x,int n)
{
    if(x>=n)
    {
        return true;
    }
    for(int col=0;col<n;col++)
    {
        if(issafe(x,col,n))
        {
            a[x][col]=1;
            if(nQuene(x+1,n))
            {
                return true;
            }
            a[x][col]=0;
        }
    }
    return false;
}

int main()
{
    memset(a,0,sizeof a);
    if(nQuene(0,4))
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
