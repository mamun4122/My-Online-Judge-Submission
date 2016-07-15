#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&b,&a);
        long long int z=a,mx=a;
        while(z!=1)
        {
            if(z%2==0)
            {
                z/=2;
                mx=max(mx,z);
            }
            else
            {
                z=z*3+1;
                mx=max(mx,z);
            }
        }
        printf("%d %lld\n",b,mx);
    }
    return 0;
}

