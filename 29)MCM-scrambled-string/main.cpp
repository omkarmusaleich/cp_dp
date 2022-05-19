#include <bits/stdc++.h>

using namespace std;

map<string,bool>m;
bool solve(string a,string b)
{
    if(a==b)
    {
        return true;
    }
    if(a.length()<=1)
    {
        return false;
    }
    int n=a.length();
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        bool x1=(solve(a.substr(0,(i+1)),b.substr(n-i-1,(i+1))) && solve(a.substr(i+1,n-1-i),b.substr(0,n-1-i)));
        bool x2=( solve( a.substr(0,i+1),b.substr(0,i+1) ) && solve(a.substr(i+1,n-i-1),b.substr(i+1,n-i-1) )  );
        if(x1||x2)
        {
            flag=true;
            break;
        }
    }
    return flag;
}
// optimize code
bool solveop(string a,string b)
{
    if(a==b)
    {
        return true;
    }
    if(a.length()<=1)
    {
        return false;
    }
    int n=a.length();
    bool flag=false;
    string key=a;
    key.push_back('#');
    key+=b;

    if(m.find(key)!=m.end())
    {
        return m[key];
    }
    for(int i=0;i<n-1;i++)
    {
        bool x1=(solve(a.substr(0,(i+1)),b.substr(n-i-1,(i+1))) && solve(a.substr(i+1,n-1-i),b.substr(0,n-1-i)));
        bool x2=( solve( a.substr(0,i+1),b.substr(0,i+1) ) && solve(a.substr(i+1,n-i-1),b.substr(i+1,n-i-1) )  );
        if(x1||x2)
        {
            flag=true;
            break;
        }
    }
    return m[key]=flag;
}


int main()
{
    // string s="great"
    // we make it binery tree with constrain no node except leaf node having 2 node (not empty)

    //       great
    /*      /    \
           gr    eat         on this binery tree we can swap (0 or more times)any two node of the non leaf node
          / \    /  \          and the resultent string is a scrambled string
          g  r   e   at
                     / \     suppose we change e at than resultant is substring (ate)-->grate
                     a  t

    */

    //string a="greatomkar";
    //b="aterg";
    //string b="graterkaom";
    string a="abcde",b="cbaed";
    /*
    if(a.length()!=b.length())
    {
        cout<<"they are not screabled string :"<<endl;
    }
    else{
        if(solve(a,b))
        {
            cout<<"they are scrambled string"<<endl;
        }
        else{
            cout<<"they are not scrambled string"<<endl;
        }
    }*/

    if(a.length()!=b.length())
    {
        cout<<"they are not screabled string :"<<endl;
    }
    else{
        if(solveop(a,b))
        {
            cout<<"they are scrambled string"<<endl;
        }
        else{
            cout<<"they are not scrambled string"<<endl;
        }
    }
    for(auto val:m)
    {
        cout<<val.first<<"  "<<val.second<<endl;
    }
    return 0;
}
