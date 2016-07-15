#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,a;
    char c[100];
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int cnt=0,temp=0;
        scanf("%d\n",&a);
        scanf("%s",c);
        int x=strlen(c);
        for(int j=0; j<x; j++)
        {
            if(c[j]=='.')
                temp++;
            else if(temp>0)
                temp++;
            if(temp==3)
            {
                cnt++;
                temp=0;
            }
        }
        if(temp>0)cnt++;
        printf("Case %d: %d\n",i,cnt);
    }

    return 0;
}
