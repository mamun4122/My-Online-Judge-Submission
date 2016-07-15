#include<stdio.h>

int main()
{
    int a,b,c,d,res,k;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)&&(a||b||c||d))
    {
        res=1080;
        k=a-b;
        if(k<0)
            k+=40;
        res+=k*9;
        k=c-b;
        if(k<0)
            k+=40;
        res+=k*9;
        k=c-d;
        if(k<0)
            k+=40;
        res+=k*9;
        printf("%d\n",res);
    }
    return 0;
}
