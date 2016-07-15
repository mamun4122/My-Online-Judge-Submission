#include<stdio.h>

int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=1;i<=T&&i<=125;i++)
    {
        int a,b,c;
        scanf("%d%d",&a,&b);
        c=a+b;
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}
