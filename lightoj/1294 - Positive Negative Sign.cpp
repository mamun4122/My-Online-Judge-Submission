#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
using namespace std;



int main()
{
    long long int n,m,sum=0,k;
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        sum=0;
        scanf("%lld%lld",&n,&m);
        int flag=1;
        k=m*m;
        //cout<<k<<endl;
        sum+=(k*((n/m)/2));
        printf("Case %d: %lld\n",i,sum);
    }



    return 0;
}
