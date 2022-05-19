#include <iostream>

using namespace std;


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    int t[n+1][m+1];
    for(int i=1;i<=m;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        t[i][0]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<t[n][m]<<endl;
    return 0;
}
