#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;
int t[N][N];

bool ispal(string s,int i,int j)
{
    int midsize=(j-i+1)/2;
    for(int k=0;k<midsize;k++)
    {
        if(s[i+k]!=s[j-k])
        {
            return false;
        }
    }
    return true;
}

int MCMPal(string s,int i,int j)
{
    if(i>=j || ispal(s,i,j))
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int minimum_num_partition=INT_MAX;
    for(int k=i;k<j;k++)
    {
        //int temp=(MCMPal(s,i,k)+1+MCMPal(s,k+1,j));
        int temp=(1+(t[i][k]!=-1?t[i][k]:MCMPal(s,i,k))+(t[k+1][j]!=-1?t[k+1][j]:MCMPal(s,k+1,j)));//optimize
        minimum_num_partition=min(minimum_num_partition,temp);
    }
    return t[i][j]=minimum_num_partition;
}

int main()
{
    memset(t,-1,sizeof(t));
    string s;
    cin>>s;
    int n=s.length();
    cout<<"minimum number of partition required for making palindrome substring "<<MCMPal(s,0,n-1)<<endl;
    return 0;
}
