#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t,n,a,b,c;
    float k;
    long long sum;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d%d%d",&a,&b,&c);
            //k=(float)a/b;
            sum+=c*a;
            //printf("%f ",sum);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
