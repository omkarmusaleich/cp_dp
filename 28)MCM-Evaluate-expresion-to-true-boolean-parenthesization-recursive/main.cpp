#include <bits/stdc++.h>

using namespace std;

int MCMbool(string s,int i,int j,char istrue)
{
    if(i>j)
    {
        return false;
    }
    if(i==j)
    {
        if(istrue=='T')
        {
            if(s[i]=='T')
            {
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(s[i]=='F')
            {
                return true;
            }
            else{
                return false;
            }
        }
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt=MCMbool(s,i,k-1,'T');
        int lf=MCMbool(s,i,k-1,'F');
        int rt=MCMbool(s,k+1,j,'T');
        int rf=MCMbool(s,k+1,j,'F');
        if(s[k]=='&')
        {
            if(istrue=='T')
            {
                ans=ans+lt*rt;
            }
            else{
                ans=ans+(lt*rf)+(lf*rt)*(lf*rf);
            }

        }
        else if(s[k]=='|')
        {
            if(istrue=='T')
            {
                ans=ans+(lt*rf)+(lf*rt)+(rt*lt);
            }
            else{
                ans=ans+(lf*rf);
            }
        }
        else{
            if(istrue=='T')
            {
                ans=ans+(lf*rt)+(lt*rf);
            }
            else{
                ans=ans+(lt*rt)+(lf*rf);
            }
        }

    }
    return ans;
}


int main()
{
    string s="T|F^T";
    int n=s.length();
    cout<<MCMbool(s,0,n-1,'F');
    return 0;
}
