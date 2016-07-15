#include<stdio.h>

int main()
{
    int t=0;
    int n;
    while(scanf("%d",&n))
    {
        t++;
        int res=1;
        int j=0;
        if(n<0)
            break;
        while(res<n)
        {
            j++;
            res=res*2;
        }
        printf("Case %d: %d\n",t,j);
    }
    return 0;
}
