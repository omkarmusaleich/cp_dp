#include <iostream>

using namespace std;

int LRS(string a,string b,int n,int m)
{
    if(n==0||m==0)
    {
        return 0;
    }
    if(a[n-1]==b[m-1] && n!=m)
    {
        return 1+LRS(a,b,n-1,m-1);
    }
    else{
        return max(LRS(a,b,n,m-1),LRS(a,b,n-1,m));
    }
}

int main()
{
    // string a="aabebcdd"
    // here longest repeating subsequense is abd
    // because there are two subsequence same but different indexes
    // like a=0,1   b=2,4 d=6,7
    // than take b=a;
    // a="aabebcdd"
    // b="aabebcdd"
    // for taking subsequense between a and b -> 'a' at 0 index in a and 1 index in b like that we
    // take all other characters
    string a="aabebcdd" ;
    string b=a;
    cout<<"length of longest repeating subsequence is : "<<LRS(a,b,a.length(),b.length())<<endl;
    int N=a.length();
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
            if(a[i-1]==b[j-1] && i!=j)
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    //cout<<"length of longest repeating subsequence is : "<<t[N][N]<<endl;
    return 0;
}
