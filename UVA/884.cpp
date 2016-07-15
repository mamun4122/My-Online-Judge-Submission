#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    vector<int> prime;
    bool mark[1000009];
    memset(mark,1,sizeof(mark));
    prime.push_back(2);
    for(int i=4; i<=1000000; i+=2)mark[i]=0;
    for(int i=3; i*i<=1000000; i+=2)
    {
        if(mark[i])
        {
            prime.push_back(i);
            for(int j=i+i; j<=1000000; j+=i)
            {
                mark[j]=0;
            }
        }
    }
    int n,mx,k,sz=prime.size();
    map<int,int> m;
    m[0]=m[1]=0;
    mx=0;
    for(int i=2; i<=1000000; i++)
    {
        k=i;
        if(mark[k])mx++;
        else
        {
            int f=sqrt(k);
            for(int j=0; j<sz&&prime[j]<=f; j++)
            {
                while(k%prime[j]==0)
                {
                    k=k/prime[j];
                    mx++;
                }
            }
            if(k>1)
                mx++;
        }
        m[i]=mx;
    }
    while(scanf("%d",&n)!=EOF)
    {
        cout<<m[n]<<endl;
    }
    return 0;
}
