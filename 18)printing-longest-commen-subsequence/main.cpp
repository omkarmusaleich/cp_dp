#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x="abcdef",y="ablpdffe";
    int n=x.length(),m=y.length();
    // calculate maximum length by top-down-approach
    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        t[i][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        t[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    cout<<"length of a subsequense "<<t[n][m]<<endl;
    string str;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            str.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1])
            {
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(str.begin(),str.end());
    cout<<"longest subsequence is : "<<str<<endl;
    return 0;
}
