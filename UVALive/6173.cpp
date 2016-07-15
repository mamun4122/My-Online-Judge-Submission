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
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    long long i,j,k,t,m,n,c,b,l;
    string a;
    scanf("%lld",&t);
    while(t--)
    {
        a.clear();
        cin>>i>>b>>a;
        l=a.size();
        k=0;
        m=b-1;
        for(j=0;a[j]!='\0';j++)
        {
            c=a[j]-48;
            k=((k%m)*(b%m))%m;
            k=((k%m)+(c%m))%m;
        }
        printf("%lld %lld\n",i,k);
    }
    return 0;
}