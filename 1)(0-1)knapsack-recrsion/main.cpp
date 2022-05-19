#include <bits/stdc++.h>

using namespace std;

int knapsack(int value[],int weight[],int W,int n)
{
    if(n==-1 || W==0 )
    {
        return 0;
    }
    if(weight[n]<=W)
    {
        return max(value[n]+knapsack(value,weight,W-weight[n],n-1),knapsack(value,weight,W,n-1));
    }
    else{
        return knapsack(value,weight,W,n-1);
    }
}


int main()
{
    int value[5]={2,2,4,5,7};
    int weight[5]={1,3,4,5,3};
    int W=10;
    cout<<knapsack(value,weight,W,4)<<endl;
    return 0;
}
