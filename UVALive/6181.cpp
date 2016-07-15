#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
#define pi 2*acos(0.0)
const int inf=2000000000;
int main()
{
    int i,j,k,l,P,N,t,s,r;
    char a[11000];
    scanf("%d",&P);
    for(i=1;i<=P;i++)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&i);
        getchar();
        gets(a);
        t=strlen(a);
        scanf("%d",&N);
        l=0;
        printf("%d ",i);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&k);
            l=l+k;
            if(l>t-1)
            {
                s=l%(t-1);
                l=s-1;
                printf("%c",a[s-1]);
            }
            else if(l<0)
            {
                s=t+l;
                l=s;
                printf("%c",a[s]);

            }
            else printf("%c",a[l]);
        }
        printf("\n");
    }
    return 0;
}