#include <iostream>

using namespace std;

int solve(Node* root,int &res)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=solve(root->left,res);
    int r=solve(root->right,res);

    int temp=max(l,r)+root->value;
    int ans=max(temp,l+r+root->value);
    res=max(res,ans);

    return temp;
}

int main()
{
    int res=INT_MIN;
    solve(root,res);
    cout<<res<<endl;
    return 0;
}
