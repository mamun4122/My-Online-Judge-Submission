#include<stdio.h>

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",c*(2*a-b)/(a+b));
    }
    return 0;
}
