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
    // A="abcedf"
    // B="aewqfl"
    // it supersequence is astring which contain both A,B sequense
    // like output="abcewqdfl" in this supersequence order of sequence of a and b string is remian
    //              -  -   -
    // _ represent a commen sequense in both string A,B
    // and it a stortest
    // length of output=A.length()+B.length()-commeon subsequense length
    //                  abcedf   + aewqfl  -  aef
    string A="abcedf",B="aewqfl";

    // first find common subsequence
    int n=A.length();
    int m=B.length();
    //cout<<"length of a Longest  commen subsequense is : "<<LCS(A,B,n,m)<<endl;

    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        t[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        t[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    cout<<" length longest common subsequense is : "<<t[n][m]<<endl;
    string sq;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(A[i-1]==B[j-1])
        {
            sq.push_back(A[i-1]);
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

    reverse(sq.begin(),sq.end());
    cout<<" common subsequese is : "<<sq<<" length of subsequence is "<<sq.length()<<endl;
    cout<<" therefore length of shortest common subsequence is "<<(n+m-sq.length())<<endl;;
    string output;
    i=0,j=0;
    int index=0;
    while((i<n) && (j<m) && (index<sq.length()))
    {
        //cout<<A[i]<<" "<<B[j]<<" "<<sq[index]<<" "<<sq<<endl;
        if((A[i]==sq[index]) && (B[j]==sq[index]))
        {
            output.push_back(sq[index]);
            i++;
            j++;
            index++;

        }
        else if(B[j]==sq[index] && A[i]!=sq[index])
        {
            output.push_back(A[i]);
            i++;

        }
        else{
            output.push_back(B[j]);
            j++;

        }
    }
    while(i<n)
    {
        output.push_back(A[i]);
        i++;
    }
    while(j<m)
    {
        output.push_back(B[j]);
        j++;
    }
    cout<<" "<<output<<endl;
    return 0;
}
