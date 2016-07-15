#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
int x[]= {1,-1,1,-1,2,2,-2,-2};
int y[]= {2,2,-2,-2,1,-1,1,-1};
int color[65][65];
int d[65][65];
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
        for(int i=0; i<8; i++)
        {
            int e=g+x[i];
            int f=h+y[i];
            if((e<1||e>8)||(f<1||f>8))
                continue;
            if(color[e][f]==0)
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
    //freopen("file.txt","r",stdin);
    char a[3],b[3];
    //string a,b;
    while(1)
    {
        if(scanf("%s%s",&a,&b)==EOF)
            break;
        //scanf("%s%s",&a,&b);
        srcx=a[0]-96;
        srcy=a[1]-48;
        destx=b[0]-96;
        desty=b[1]-48;
        bfs();
        //cout<<a<<" "<<b<<endl;
        printf("To get from %s to %s takes %d knight moves.\n",a,b,d[destx][desty]);
    }
    return 0;
}


