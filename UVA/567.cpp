#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
int adj[22][22];
int color[22];
int d[22];
int srcx,destx;
int bfs()
{
    memset(color,0,sizeof(color));
    memset(d,0,sizeof(d));
    queue<int> a;
    color[srcx]=1;
    a.push(srcx);
    while(!a.empty())
    {
        int g=a.front();
        a.pop();
        if(g==destx)
            return d[destx];
        for(int i=1; i<=20; i++)
        {
            if(adj[g][i]==1&&color[i]==0)
            {
                color[i]=1;
                a.push(i);
                d[i]=d[g]+1;
            }
        }
    }
}

int main()
{
    //freopen("file.txt","r",stdin);
    int t=1,flag=0;
    int n;
    while(1)
    {
        memset(adj,0,sizeof(adj));

        for(int i=1; i<20; i++)
        {
            if(scanf("%d",&n)==EOF)
                flag=1;
            if(flag==1)
            {
                break;
            }
            for(int j=1; j<=n; j++)
            {
                int x;
                scanf("%d",&x);
                adj[i][x]=1;
                adj[x][i]=1;
            }
        }
        if(flag==1)
        {
            break;
        }
        printf("Test Set #%d\n",t);
        scanf("%d",&n);
        for(int j=1; j<=n; j++)
        {
            scanf("%d%d",&srcx,&destx);
            int res=bfs();
            if(srcx<10)printf(" ");
            printf("%d to ",srcx);
            if(destx<10)printf(" ");
            printf("%d: %d\n",destx,res);
        }
        printf("\n");
        t++;
    }
    return 0;
}
