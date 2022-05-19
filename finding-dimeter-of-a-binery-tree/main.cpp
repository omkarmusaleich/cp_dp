#include <bits/stdc++.h>

using namespace std;
/*
           1
          /  \
         2    3
        / \    \
       4   5    8
          / \
         6   7

    ** dimeter is a distance longest path distance between any two leaf node**
     in this case node 6->8 or node 7->8 having longest path length (5 unit)
     it is not mandetory that path must go through root node

*/
int solve(Node *root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }

    int l=solve(root->left, ans);
    int r=solve(root->right, ans);

    int temp=1+max(l,r);
    int res=max(1+r+h,temp);
    ans=max(ans,res);
    return temp;
}


int main()
{
    int ans=INT_MIN;
    solve(root,ans); // here solve can not give optimal ans always
    cout<<ans<<endl;
    return 0;
}
