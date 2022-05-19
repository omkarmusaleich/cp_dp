#include <iostream>

using namespace std;

bool subsetsum(int a[],int w,int n)
{
    if(n==-1||w==0)
    {
        if(w==0)
        {
            return true;
        }
        else{
            return false;
        }
    }
     if(w>=a[n])
     {
         return (subsetsum(a,w-a[n],n-1)||subsetsum(a,w,n-1));
     }
     else{
        return subsetsum(a,w,n-1);
     }
}

int main()
{
    // given array is a[5]={2,3,4,8,10} w=11 find if any subset having sum=11 like{3,8} print yes
    int a[]={2,3,4,8,10};
    int w=14;
    // recursive way of solving
    //bool x=subsetsum(a,w,4);
    //cout<<x;
    // top-down approach  dp

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
                t[i][j]=(t[i-1][j-a[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    if(t[5][w])
    {
        cout<<"subsetsum "<<w<<" is possible"<<endl;
    }
    else{
        cout<<"subsetsum "<<w<<" is not  possible"<<endl;
    }
    return 0;
}
