#include<stdio.h>
 
int main()
{
    int T,n,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        if(n>=10)
        printf("%d 10\n",n-10);
        else
        printf("0 %d\n",n);
    }
    return 0;
}