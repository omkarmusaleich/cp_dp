#include <bits/stdc++.h>

using namespace std;

int main()
{
    // single source shortest path
    int v,e;
    cin>>v>>e;
    int dis[v+1];
    dis[1]=0;
    for(int i=2;i<=v;i++)
    {
        dis[i]=INT_MAX;
    }
    vector<pair<pair<int,int>,int>>Edges;
    for(int i=0;i<e;i++)
    {
        int s,e,d;
        cin>>s>>e>>d;
        pair<int,int>p={s,e};
        Edges.push_back({p,d});
    }
    // O(|E|*|v|-1)
    for(int i=0;i<v-1;i++)
    {
        for(auto it=Edges.begin();it!=Edges.end();it++)
        {
            int s,e,d;
            s=((it->first).first);
            e=((it->first).second);
            d=(it->second);
            if((dis[s]+d)<dis[e])
            {
                dis[e]=dis[s]+d;
            }
        }
    }
    for(auto val:dis)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
