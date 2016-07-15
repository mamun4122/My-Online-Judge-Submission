#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
int x[]= {0,0,1,-1};
int y[]= {1,-1,0,0};
int adj[1004][1004];
int color[1004][1004];
int d[1004][1004];
int row,column;
int srcx,srcy,destx,desty;
void bfs()
{
    memset(color,0,sizeof(color));
    memset(d,0,sizeof(d));
    queue<int> a,b;
    color[srcx][srcy]=1;
    a.push(srcx);
    b.push(srcy);
    while(!a.empty())
    {
        int g=a.front();
        a.pop();
        int h=b.front();
        b.pop();
        if(g==destx&&h==desty)
            return;
        for(int i=0; i<4; i++)
        {
            int e=g+x[i];
            int f=h+y[i];
            if(adj[e][f]==0&&color[e][f]==0)
            {
                a.push(e);
                b.push(f);
                color[e][f]=1;
                d[e][f]=d[g][h]+1;
            }
        }
    }
}

int main()
{
    int n,r,bmbs,c;
    //freopen("file.txt","r",stdin);
    while(scanf("%d%d",&row,&column))
    {
        if(row==0&&column==0)
            break;
        memset(adj,-1,sizeof(adj));
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=column;j++)
                adj[i][j]=0;
        }
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&r);
            scanf("%d",&bmbs);
            for(int j=1;j<=bmbs;j++)
            {
                scanf("%d",&c);
                adj[r+1][c+1]=1;
            }
        }
        scanf("%d%d%d%d",&srcx,&srcy,&destx,&desty);
        srcx++;srcy++;destx++;desty++;
        bfs();
        printf("%d\n",d[destx][desty]);
    }
    return 0;
}

