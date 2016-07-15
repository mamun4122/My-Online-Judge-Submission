#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int res=n;
        while(n>2)
        {
            res+=(n/3);
            n=(n/3)+(n%3);
        }
        if(n==2)res++;
        printf("%d\n",res);
    }
    return 0;
}
