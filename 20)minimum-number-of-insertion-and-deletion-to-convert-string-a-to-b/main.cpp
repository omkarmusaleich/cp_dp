#include <iostream>

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
    // take a as bigger string than b
    //string a="heap",b="pea";
    string a,b;
    cin>>a>>b;
    // first we convert a(heap) to ea by deleting h,p and than insert p than output become string b(pea)
    //                        here ea is a common subsequence
    // therefore first find common subsequence and than number of deletion =a.length()-subseq.length();
    // and number of insertion is b.length()-subseq.length()
    int subseqlength=LCS(a,b,a.length(),b.length());
    cout<<"subsequence length is : "<<subseqlength<<endl;
    int n=a.length(),m=b.length();
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
            if(a[i-1]==b[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
     cout<<"subsequence length is : "<<t[n][m]<<endl;
     cout<<"number of deletion is "<<(a.length()-t[n][m])<<endl;
     cout<<"number of insertion is "<<(b.length()-t[n][m])<<endl;
    return 0;
}
