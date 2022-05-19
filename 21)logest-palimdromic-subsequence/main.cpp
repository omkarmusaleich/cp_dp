#include <bits/stdc++.h>

using namespace std;

int LCS(string a,string b ,int n,int m)
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
        return max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
    }
}

int main()
{
    // string a="anbcplbaw"
    // palimdroms ={a,n,b,....,aa,bb,acc,bcb,abcba}
    // longest is abcba
    // if we reverse the string a (b="wablpcbna")
    // and if we take LCS of a and b than we get longest palimdrome
     string a="anbclplbaw";
     string b=a;
     reverse(b.begin(),b.end());
     cout<<"length of longest paildrome made by from a string a "<<LCS(a,b,a.length(),a.length())<<endl;
     // print that palimdromic subsequence
     int N=a.length();
     int t[N+1][N+1];// a and b having same length b is reverse of a
     for(int i=0;i<=N;i++)
     {
         t[i][0]=0;
     }
     for(int j=0;j<=N;j++)
     {
         t[0][j]=0;
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
     cout<<"length of subsequense is"<<t[N][N]<<endl;
     string out;
     int i=N,j=N;
     while(i>0 && j>0 )
     {

         if(a[i-1]==b[j-1])
         {
             out.push_back(a[i-1]);
             i--;
             j--;
         }
         else if(t[i-1][j]>t[i][j-1])
         {
             i--;
         }
         else{
            j--;
         }
     }
     cout<<"palimdromic subsequence is "<<out<<endl;
    return 0;
}
