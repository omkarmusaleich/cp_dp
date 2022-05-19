#include <bits/stdc++.h>

using namespace std;

bool ispal(string s,int i,int j)
{

    int mid=(j-i+1)/2;
    for(int k=0;k<mid;k++)
    {
        if(s[i+k]!=s[j-k])
        {
            return false;
        }
    }
    return true;
}

int MCM(string s,int i,int j)
{
    if(i>=j ||  ispal(s,i,j))
    {
        return 1;
    }
    int minimum=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=(MCM(s,i,k)+MCM(s,k+1,j));
        minimum=min(temp,minimum);
    }
    return minimum;
}


int numOfPartition(string s,int i,int j)
{
    if(i>=j || ispal(s,i,j))
    {
        return 0;
    }
    int number_of_partition=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=(numOfPartition(s,i,k)+1+numOfPartition(s,k+1,j));
        number_of_partition=min(number_of_partition,temp);

    }
    return number_of_partition;
}

int main()
{
    string s="abcbddacadd";
    int n=s.length();
    cout<<"number of palindrome : "<<MCM(s,0,s.length()-1)<<endl;
    cout<<"required number of partition making subsequence as palindrome is"<<endl;
    cout<<"(total palindrome osf maximum sizes possible -1): "<<MCM(s,0,s.length()-1)-1<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"minimum number of partition required "<<numOfPartition(s,0,n-1)<<endl;
    return 0;
}
