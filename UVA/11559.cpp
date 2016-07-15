#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    //freopen("file.txt","r",stdin);
    int n,b,h,w,x;
    while(scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF)
    {
        int p[h];
        bool a[h];
        memset(a,0,sizeof(a));
        for(int i=0; i<h; i++)
        {
            scanf("%d",&p[i]);
            for(int j=0; j<w; j++)
            {
                scanf("%d",&x);
                if(x>=n)
                {
                    a[i]=true;
                }
            }
        }
        int res=0;
        int flag=0;
        for(int i=0; i<h; i++)
        {
            if(a[i]==true)
            {
                int k=p[i]*n;
                if(flag==0)
                {
                    res=k;
                }
                else
                {
                    res=min(res,k);
                }
                flag=1;
            }
        }
        if(flag==0||res>b)
        {
            printf("stay home\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }

    return 0;
}
