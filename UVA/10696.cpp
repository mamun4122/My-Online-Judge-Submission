#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n,k;
    while(scanf("%d",&n)&&n)
    {
        if(n<101)
        {
            printf("f91(%d) = 91\n",n);
        }
        if(n>=101)
        {
            k=n-10;
            printf("f91(%d) = %d\n",n,k);
        }
    }
    return 0;
}
