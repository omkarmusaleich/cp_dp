#include <bits/stdc++.h>

using namespace std;

int LCS(string a,string b,int n,int m)
{
    if(n==0||m==0)
    {
        return 0;
    }
    if(a[n-1]==b[m-1])
    {
        return (1+LCS(a,b,n-1,m-1));
    }
    else{
        return max(LCS(a,b,n,m-1),LCS(a,b,n-1,m));
    }
}

int main()
{
    string a="agbcagt";
    // find longest palimdrome by taking LCS(longest common subsequence of a string a and reverse of a)
    // substract length of palimdrome from length of (string a)
    string b=a;
    reverse(b.begin(),b.end());
    int N=a.length();
    cout<<"minimum number of deletion required : "<<N-LCS(a,b,N,N)<<endl;

    // top-down approach
    int t[N+1][N+1];
    for(int i=0;i<=N;i++)
    {
        t[i][0]=0;
        t[0][i]=0;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(a[i-1]==b[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    cout<<"minimum number of deletion required : "<<(N-t[N][N])<<endl;
    return 0;
}
