#include<bits/stdc++.h>

using namespace std;

vector<int>v(0);

void  minimumcoin(int c[],int sum,int n,int i)
{
    if(n==-1||sum==0)
    {

        if(sum==0)
        {
            v.push_back(i);
            return;
        }
        else{
            return ;
        }
    }
    if(sum>=c[n])
    {
        minimumcoin(c,sum-c[n],n,i+1);

        minimumcoin(c,sum,n-1,i);
    }
    else{
        minimumcoin(c,sum,n-1,i);
    }
}



int  minimumCoins(int c[],int sum,int n,int i)
{
    if(n==-1||sum==0)
    {

        if(sum==0)
        {
            return i;
        }
        else{
            return -1;
        }
    }
    if(sum>=c[n])
    {
        int temp1=minimumCoins(c,sum-c[n],n,i+1);
        int temp2=minimumCoins(c,sum,n-1,i);
        int out=0;
        if(temp1>0 && temp2<0)
        {
            out=temp1;
        }
        if(temp2>0 && temp1<0)
        {
            out=temp2;
        }
        if(temp1>0 && temp2>0)
        {
            out=min(temp1,temp2);
        }
        return out;
    }
    else
    {
        return minimumCoins(c,sum,n-1,i);
    }
}


int main()
{
    int c[]={11,6,5,23};
    int sum=35;
    /*
    minimumcoin(c,sum,3,0);
    /for(auto &value: v)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    cout<<"minimum number of coin required : "<<*min_element(v.begin(),v.end())<<endl;
    cout<<minimumCoins(c,sum,3,0)<<endl;
    */

    // top-down approach DP
    int t[4+1][sum+1];
    for(int i=0;i<=4;i++)
    {
        t[i][0]=-1;
    }
    for(int i=0;i<=sum;i++)
    {
        t[0][i]=0;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=c[i-1])
            {

              int temp1=t[i][j-c[i-1]];
              if(temp1==-1)
              {
                  temp1=1;
              }
              else if(temp1>0)
              {
                  ++temp1;
              }
              int temp2=t[i-1][j];
              if(temp1>0 && temp2>0)
              {
                  t[i][j]=min(temp1,temp2);
              }
              else
              {
                  t[i][j]=max(temp1,temp2);
              }

            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"minimum number of coins required is :: "<<t[4][sum]<<endl;
    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
    // another method ..

    return 0;
}
