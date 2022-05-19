#include <bits/stdc++.h>

using namespace std;


int solve(Node* root,int& res)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    int temp=max(max(l,r)+root->value,root->value);
    int ans=max(temp,l+r+root->value);
    res=max(res,ans);
    return temp;

}

int main()
{
    // in this problem node value may be negative
    /*

            10
           /  \
          5    9
         / \    \
        1   6    -25
           /    /   \
          -5   10    11

    maximum path sum here is 6 to 9  (6+5+10+9) in this path both node are not leaf node
    */
    // here we can not get a ans because we dont construst binery tree
    int res=INT_MIN;
    solve(root,res);
    cout<<res<<endl;
    return 0;
}
