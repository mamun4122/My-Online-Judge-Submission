#include<iostream>
using namespace std;
#include<stdio.h>

long long int a,b,c;
long long int k;
long long int bigmod(long long int i,long long int j)
{
    if(j==0)return 1;
    if(j%2==0)
    {
        k=bigmod(i,j/2);
        return ((k%c)*(k%c))%c;
    }
    else{
        return ((i%c)*(bigmod(i,j-1)%c))%c;
    }
}

int main()
{
    long long int res;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
        res=bigmod(a,b);
        printf("%lld\n",res);
        k=0;
    }

}
