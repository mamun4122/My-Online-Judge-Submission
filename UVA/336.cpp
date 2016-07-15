#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<cstring>
using namespace std;

int adj[32][32],src,ttl,sz;
int color[32];
int bfs()
{
    int res=sz-1;
    memset(color,0,sizeof(color));
    queue<int> q,r;
    q.push(src);
    r.push(ttl);
    color[src]=1;
    while(!q.empty())
    {
        int i=q.front();q.pop();
        int j=r.front();r.pop();
        for(int l=1;l<=sz;l++)
        {
            if(j==0)
                break;
            if(adj[i][l]==1&&color[l]==0)
            {
                res--;
                color[l]=1;
                q.push(l);
                r.push(j-1);

            }
        }
    }
    return res;
}

int main()
{
    map<int,int> mymap;
    map<int,int>::iterator it;
    int n,t=1;
    while(scanf("%d",&n)&&n)
    {
        memset(adj,0,sizeof(adj));
        int x=1;
        int a,b;
        for(int i=1;i<=n;i++)
        {

            scanf("%d%d",&a,&b);
            if(mymap.find(a)==mymap.end())
            {
                mymap[a]=x;
                x++;
            }
            if(mymap.find(b)==mymap.end())
            {
                mymap[b]=x;x++;
            }
            adj[mymap[a]][mymap[b]]=1;
            adj[mymap[b]][mymap[a]]=1;

        }
        sz=x-1;
        /*for(int i=1;i<=sz;i++)
        {
            for(int j=1;j<=sz;j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;

        }
        for(it=mymap.begin();it!=mymap.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<sz<<endl;*/
        while(scanf("%d%d",&a,&b)&&(a||b))
        {
            src=mymap[a];
            ttl=b;
            int res=bfs();
            if(res<0)res=0;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t,res,a,b);
            t++;
        }
        mymap.clear();
    }

    return 0;
}
