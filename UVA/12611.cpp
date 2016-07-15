#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int r,l,x1,x2,y;
        scanf("%d",&r);
        l=(r*100)/20;
        x1=(l*45)/100;
        x2=(l*55)/100;
        y=(l*60)/200;
        printf("Case %d:\n",i);
        printf("%d %d\n%d %d\n%d %d\n%d %d\n",-x1,y,x2,y,x2,-y,-x1,-y);
    }

    return 0;
}
