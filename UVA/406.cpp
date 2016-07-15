#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
vector<int> prime;
bool mark[1009];
void func(int n)
{
    prime.push_back(1);
    if(n>=2)
        prime.push_back(2);
    for(int i=4; i<=n; i+=2)mark[i]=0;
    for(int i=3; i<=n; i+=2)
    {
        if(mark[i])
        {
            prime.push_back(i);
            for(int j=i+i; j<=n; j+=i)
            {
                mark[j]=0;
            }
        }
    }
}
int main()
{
    memset(mark,1,sizeof(mark));
    int a,c,flag=0,sz,x,z;
    while(scanf("%d%d",&a,&c)!=EOF)
    {
        func(a);
        sz=prime.size();
        if(sz%2==0)
        {
            x=c*2;
            z=sz/2-c;
        }
        else
        {
            x=c*2-1;
            z=sz/2+1-c;
        }
        if(c*2>=sz||c*2-1>=sz){x=sz;z=0;}
        printf("%d %d:",a,c);
        for(int i=z,j=1; j<=x&&i<sz; j++,i++)
        {
            printf(" %d",prime[i]);
        }
        printf("\n\n");
        prime.clear();
    }
    return 0;
}


