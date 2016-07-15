#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            res+=(i*i);
        }
        printf("%d\n",res);
    }

    return 0;
}
