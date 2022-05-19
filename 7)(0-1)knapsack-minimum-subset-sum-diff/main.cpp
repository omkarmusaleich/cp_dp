#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={11,5,1,6,3};
    int sum=accumulate(a,a+5,0);
    int w=sum/2;
    bool t[5+1][w+1];
    for(int i=1;i<=w;i++)
    {
        t[0][i]=false;
    }
    for(int i=0;i<=5;i++)
    {
        t[i][0]=true;
    }

    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j>=a[i-1])
            {
                t[i][j]=(t[i-1][j-a[i-1]]||t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    int w1=0;
    for(int j=w;j>=0;j--)
    {
        if(t[5][j])
        {
            w1=j;
            break;
        }
    }
    cout<<"minimum sum difference between the subsets "<<(sum-w1-w1)<<" "<<w1<<endl;
    return 0;
}
