#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int main()
{
    //freopen("file.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y,mx,z;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        if(y>m)
        {
            z=x-y+m;
        }
        else
            z=x;
        if(i==1)mx=z;
        else mx=max(mx,z);
    }
    printf("%d\n",mx);
    return 0;
}