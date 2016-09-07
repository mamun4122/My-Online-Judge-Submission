#include<stdio.h>
#include<math.h>
 
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int a,b,c=0,d,e;
        scanf("%d%d",&a,&b);
        if(a>b){c=a-b;c=c*4;}
        else if(b>a){c=b-a;c=c*4;}
        d=a*4;
        e=c+11+d+8;
        printf("Case %d: %d\n",i,e);
    }
    return 0;
}