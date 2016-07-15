#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
    int n,sum,a[53],res,t=1;
    while(scanf("%d",&n)&&n)
    {
        sum=0;res=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sum/=n;
        res=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>sum)
            {
                res+=(a[i]-sum);
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",t++,res);
    }
    return 0;
}
