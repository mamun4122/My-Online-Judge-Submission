#include<stdio.h>


int main()
{
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    long long ans=0;
    long long row=n/a;
    if(n%a!=0)row++;
    long long column = m/a;
    if(m%a!=0)column++;
    ans=row*column;
    printf("%lld\n",ans);


    return 0;
}