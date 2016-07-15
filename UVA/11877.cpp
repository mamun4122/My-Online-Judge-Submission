#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int res=0;
        while(n>1)
        {
            n=n-3+1;
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
