#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

#define ALL(p) p.begin(),p.end()
#define mem(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
#define mx 1000000
bool mark[mx];
vector<int>prime;

void sieve()
{
    mem(mark,0);
    prime.PB(2);
    for(int i=3;i<=10000;i+=2)
    {
        if(mark[i]==0)
        {
            prime.PB(i);
            for(int j=i;j<=mx;j+=i*2)
                mark[j]=1;
        }
    }
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    sieve();
    //for(int i=0;i<prime.size();i++)
        //cout<<prime[i]<<" ";
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,res=0;
        scanf("%d",&n);
        for(int i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++)
        {
            int cnt=0;
            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    cnt++;
                    n/=prime[i];
                }
                res=max(res,cnt);
            }
        }
        if(n)res=max(res,1);
        printf("%d\n",res);
    }



    return 0;
}
