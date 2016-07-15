#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    vector<int> v;
    int a,b,c,t=1,d;
    while(scanf("%d%d",&a,&b)&&(a&&b))
    {
        int res=0;
        if(a>b)
            res=a-b;
        for(int i=1;i<=a;i++)
        {
            scanf("%d",&c);
            if(i==1)
                d=c;
            else
                d=min(d,c);
        }
        for(int j=1;j<=b;j++)
        {
            scanf("%d",&c);
        }
        if(res!=0)
            printf("Case %d: %d %d\n",t++,res,d);
        else
            printf("Case %d: %d\n",t++,res);

    }
    return 0;
}
