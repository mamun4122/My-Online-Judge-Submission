#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;

int adj[1000][1000];
int d[1000];
int color[1000];
int p[1000];
int row,srcx,destx;
bool bfs()
{
    memset(d,0,sizeof(d));
    memset(color,0,sizeof(color));
    memset(p,0,sizeof(p));
    color[srcx]=1;
    queue<int> q;
    q.push(srcx);
    while(!q.empty())
    {
        int i=q.front();
        if(i==destx)
            return true;
        q.pop();
        for(int j=1; j<=row; j++)
        {
            if(adj[i][j]==1&&color[j]==0)
            {
                q.push(j);
                color[j]=1;
                d[j]=d[i]+1;
                p[j]=i;

            }
        }
    }
    return false;
}

int main()
{
    //freopen("file.txt","r",stdin);
    //freopen("file1.txt","w",stdout);
    int t=0;
    map<string,int> m1;
    map<int,string> m2;
    int n,x;
    char a[3],b[3];
    while(1)
    {
        memset(adj,0,sizeof(adj));
        x=1;
        if(scanf("%d",&n)==EOF)
            break;
        //cout<<n<<endl;
        if(t!=0)
        {
            printf("\n");
        }
        t=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%s%s",a,b);
            if(m1.find(a)==m1.end())
            {
                m1[a]=x;
                m2[x]=a;
                x++;
            }
            if(m1.find(b)==m1.end())
            {
                m1[b]=x;
                m2[x]=b;
                x++;
            }
            adj[m1[a]][m1[b]]=1;
            adj[m1[b]][m1[a]]=1;
            //cout<<a<<" "<<b<<endl;
        }
        row=x-1;
        scanf("%s%s",a,b);
        int flag=0;
        if(m1.find(a)==m1.end())
        {
            flag=1;
        }
        if(m1.find(b)==m1.end())
        {
            flag=1;
        }
        //cout<<a<<" "<<b<<endl;
        if(flag!=1)
        {
            srcx=m1[a];
            destx=m1[b];
        }
        if(strcmp(a,b)==0)
        {
            printf("\n");
        }
        else if(n==0||flag==1)
        {
            printf("No route\n");
        }
        else if(bfs())
        {
            string s[d[destx]+1];
            s[0]=m2[srcx];
            s[d[destx]]=m2[destx];
            int x=m1[m2[destx]];
            for(int k=d[destx]-1; k>0; k--)
            {
                s[k]=m2[p[x]];
                x=p[x];
            }
            for(int k=0; k<=d[destx]-1; k++)
            {
                printf("%s %s\n",s[k].c_str(),s[k+1].c_str());
            }
        }
        else
        {
            printf("No route\n");
        }
        getchar();
        m1.clear();
        m2.clear();

    }
    return 0;
}
