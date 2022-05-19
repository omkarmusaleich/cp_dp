#include <bits/stdc++.h>

using namespace std;

int t[100][100];

int LCS(string s1,string s2,int n,int m)
{
    if(n==0||m==0)
    {
        return 0;
    }
    if(t[n][m]!=-1)
    {
        return t[n][m];
    }

    if(s1[n]==s2[m])
    {
        return t[n][m]=(1+LCS(s1,s2,n-1,m-1));
    }
    else{
        return t[n][m]=max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
    }
}

int main()
{
    memset(t,-1,sizeof(t));
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    cout<<LCS(s1,s2,n,m)<<endl;
    return 0;
}
