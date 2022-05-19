#include <iostream>

using namespace std;

bool subsetsum(int a[],int sum,int n)
{
    if(sum==0 || n==-1)
    {
        if(sum==0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    if(sum>=a[n])
    {
        return (subsetsum(a,sum-a[n],n-1)||subsetsum(a,sum,n-1));
    }
    else{
        return subsetsum(a,sum,n-1);
    }
}

int main()
{
    int a[]={1,5,11,6,1};
    int sum=0;
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        sum+=a[i];
    }

    if(sum&1!=0)
    {
        cout<<"Equal partision is not possible "<<endl;
    }
    else{
        // recursive way
        //cout<<subsetsum(a,sum/2,4);

        int w=sum/2;
        // top-down approach dp
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
             cout<<"Equal partision is  possible "<<endl;
        }
        else{
             cout<<"Equal partision is not possible "<<endl;
        }
    }
    return 0;
}
