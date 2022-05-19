#include <bits/stdc++.h>

using namespace std;
const int N=10;
int t[N][N];

int knapsackmemo(int value[],int weight[],int w,int n)
{

    if(n==0 || w==0)
    {
        return 0;
    }

    if(t[n][w]!=-1)
    {
        return t[n][w];
    }

    if(w>=weight[n])
    {

        return t[n][w]=max(value[n]+knapsackmemo(value,weight,w-weight[n],n-1),knapsackmemo(value,weight,w,n-1));
    }
    else{

        return t[n][w]=knapsackmemo(value,weight,w,n-1);
    }
}

int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            t[i][j]=-1;
        }
    }
    int n,w;
    cin>>n>>w;
    int value[n+1],weight[n+1];
    cout<<"enter "<<n<<" value of a item"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>value[i];
    }
    cout<<"enter "<<n<<" weight of a item"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i];
    }
    cout<<knapsackmemo(value,weight,w,n);
    return 0;
}
