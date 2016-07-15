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

vector<int> prime;
bool mark[101];
void func(int n)
{
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
//    READ("file.txt");
//    WRITE("file2.txt");
    memset(mark,1,sizeof(mark));
    func(100);
    int ind[101];
    ind[1]=0;
    //memset(ind,0,sizeof(ind));
    int sz=prime.size();
    vector<int> v;
    vector< vector<int> > ans;
    for(int i=1;i<=sz;i++)
        v.push_back(0);
    for(int i=2;i<=100;i++)
    {
        int k=i,l=0;
        while(k>1)
        {
            if(k%prime[l]==0)
            {
                ind[i]=max(ind[i-1],l);
                k/=prime[l];
                v[l]++;
            }
            else
                l++;
        }
        ans.push_back(v);
    }
    int n,cnt=0;
    while(scanf("%d",&n)&&n)
    {
        cnt=0;
        if(n<10)
            printf("  ");
        else if(n<100)
            printf(" ");
        printf("%d! =",n);
        int k=ind[n];
        for(int j=0;j<=k;j++)
        {
            cnt++;
            if(ans[n-2][j]<10)
                printf("  ");
            else if(ans[n-2][j]<100)
                printf(" ");
            printf("%d",ans[n-2][j]);
            if(cnt==15&&j<k)
            {
                cnt=0;
                printf("\n      ");
            }
        }
        printf("\n");
            //cout<<ans[n-2][j]<<" ";
    }
    return 0;
}


