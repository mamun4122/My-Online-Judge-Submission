
#include<cstdio>
#include<string.h>
int main()
{
    int n,b;
    float a[1002],res;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        res=0.0;
        memset(a,0,sizeof(a));
        scanf("%d",&b);
        for(int j=1;j<=b;j++)
        {
            scanf("%f",&a[j]);
            res+=a[j];
        }
        res=res/b;
        int cnt=0;
        for(int j=1;j<=b;j++)
        {
            if(a[j]>res)
                cnt++;
        }
        res=((float)cnt/b)*100;
        printf("%.3f%%\n",res);
        //printf("\%\n");
    }
    return 0;
}


