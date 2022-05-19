#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={1,1,2,3};
    int diff=1;
    int sum=accumulate(a,a+4,0);
    // let s1,s2 be a two set with diff 1
    // s1+s2=sumofarray
    // s1-s2=diff
    // 2s1=sumofarray+diff
    // s1=(sumofarray+diff)/2
    // output a count of sets with s1 sum
    int val=(sum+diff)/2;
    int t[4+1][val+1];
    for(int i=1;i<=val;i++)
    {
        t[0][i]=0;
    }
    for(int i=0;i<=4;i++)
    {
        t[i][0]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=val;j++)
        {
            if(j>=a[i-1])
            {
                t[i][j]=t[i-1][j-a[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"pair of subset having difference of sum "<<diff<<" is "<<t[4][val]<<endl;
    return 0;
}
