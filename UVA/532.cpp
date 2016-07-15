#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int l,r,c,srcx,srcy,srcz,enx,eny,enz;
int adj[33][33][33];
int d[33][33][33];
int color[33][33][33];
bool bfs()
{
    memset(d,0,sizeof(d));
    memset(color,0,sizeof(color));
    queue<int> a,b,c;
    a.push(srcx);
    b.push(srcy);
    c.push(srcz);
    while(!a.empty())
    {
        int e,f,g;
        e=a.front();
        a.pop();
        f=b.front();
        b.pop();
        g=c.front();
        c.pop();
        if(enx==e&&eny==f&&enz==g)
            return true;
        if(adj[e][f+1][g]==1&&color[e][f+1][g]==0)
        {
            a.push(e);
            b.push(f+1);
            c.push(g);
            color[e][f+1][g]=1;
            d[e][f+1][g]=d[e][f][g]+1;
        }
        if(adj[e][f-1][g]==1&&color[e][f-1][g]==0)
        {
            a.push(e);
            b.push(f-1);
            c.push(g);
            color[e][f-1][g]=1;
            d[e][f-1][g]=1+d[e][f][g];
        }
        if(adj[e][f][g+1]==1&&color[e][f][g+1]==0)
        {
            a.push(e);
            b.push(f);
            c.push(g+1);
            color[e][f][g+1]=1;
            d[e][f][g+1]=d[e][f][g]+1;
        }

        if(adj[e][f][g-1]==1&&color[e][f][g-1]==0)
        {
            a.push(e);
            b.push(f);
            c.push(g-1);
            color[e][f][g-1]=1;
            d[e][f][g-1]=1+d[e][f][g];
        }

        if(adj[e+1][f][g]==1&&color[e+1][f][g]==0)
        {
            a.push(e+1);
            b.push(f);
            c.push(g);
            color[e+1][f][g]=1;
            d[e+1][f][g]=1+d[e][f][g];
        }

        if(adj[e-1][f][g]==1&&color[e-1][f][g]==0)
        {
            a.push(e-1);
            b.push(f);
            c.push(g);
            color[e-1][f][g]=1;
            d[e-1][f][g]=1+d[e][f][g];
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d%d",&l,&r,&c)&&(l||r||c))
    {
        char a;
        //getchar();
        bool flag;
        memset(adj,0,sizeof(adj));
        for(int i=1; i<=l; i++)
        {
            for(int j=1; j<=r; j++)
            {
                for(int k=1; k<=c; k++)
                {
                    scanf(" %c",&a);
                    if(a=='S')
                    {
                        adj[i][j][k]=1;
                        srcx=i;
                        srcy=j;
                        srcz=k;
                    }
                    if(a=='E')
                    {
                        adj[i][j][k]=1;
                        enx=i;
                        eny=j;
                        enz=k;
                    }
                    if(a=='.')
                    {
                        adj[i][j][k]=1;
                    }
                }
            }
        }
        flag=bfs();
        if(flag)
        {
            printf("Escaped in %d minute(s).\n",d[enx][eny][enz]);
        }
        else
        {
            printf("Trapped!\n");
        }
    }
    return 0;
}
