#include <iostream>

using namespace std;

int LCS(string s1,string s2,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }

    if(s1[n-1]==s2[m-1])
    {
        return 1+LCS(s1,s2,n-1,m-1);
    }
    else{
        return max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
    }
}

int main()
{
    // string s1=abcedf s2=abwepojkfp
    // logest subsequense is abef of length 4 subsequence is not mendetory to be continuous
    // logest substring is ab (substring is continuous )

    string s1="abcedf",s2="abwepojkfp";
    // recursive approach
    cout<<"longest common subsequence in strings by recursive : "<<LCS(s1,s2,s1.length(),s2.length())<<endl;
    return 0;
}
