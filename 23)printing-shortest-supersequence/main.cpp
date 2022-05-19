#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a="abcdefs",b="aefsbdeps";
    int N=a.length();
    int M=b.length();
    int t[N+1][M+1];
    for(int i=0;i<=N;i++)
    {
        t[i][0]=0;
    }
    for(int j=0;j<=M;j++)
    {
        t[0][j]=0;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
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
    cout<<t[N][M]<<"  "<<N+M<<endl;
    string out;
    int i=N,j=M;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            out.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(t[i-1][j]>t[i][j-1])
        {
            out.push_back(a[i-1]);
            i--;
        }
        else{
            out.push_back(b[j-1]);
            j--;
        }

    }
    while(i>0)
    {
        out.push_back(a[i-1]);
        i--;
    }
    while(j>0)
    {
        out.push_back(b[j-1]);
        j--;
    }
    reverse(out.start(),out.end());
    cout<<"shortest common subsequence is: "<<out<<endl;
    cout<<" its length is : "<<out.length()<<endl;
    return 0;
}
