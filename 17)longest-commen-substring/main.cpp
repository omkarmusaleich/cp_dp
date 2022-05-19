#include <iostream>

using namespace std;
int mx=0;

void LCsubstring(string x,string y,int n,int m,int t1)
{

    if(n==0||m==0)
    {
        return ;
    }
    if(x[n-1]==y[m-1])
    {
        if(t1+1>=mx)
        {
            mx=(t1+1);
        }
        LCsubstring(x,y,n-1,m-1,++t1);
        cout<<"Commen"<<(n-1)<<" "<<(m-1)<<" "<<x[n-1]<<" "<<y[m-1]<<endl;
    }
    else{
            LCsubstring(x,y,n,m-1,0);
            LCsubstring(x,y,n-1,m,0);
    }



}
// -------------------IMP-------------------------
// in this dp approach t[n][m] is not a answer
int main()
{
    string x="labcef";
    string y="cfabcf";
    int n=x.length();
    int m=y.length();
    //LCsubstring(x,y,n,m,0);
    //cout<<mx<<endl;
    // top-Down approach DP
    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        t[i][0]=0;
    }
    for(int j=1;j<=m;j++)
    {
        t[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=(1+t[i-1][j-1]);
            }
            else{
                t[i][j]=0;
            }
        }
    }
    int mx=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<t[i][j]<<"  ";
            if(mx<t[i][j])
            {
                mx=t[i][j];
            }
        }
        cout<<endl;
    }
        cout<<endl<<"length of a maximum substring is : "<<mx<<endl;

    return 0;
}
