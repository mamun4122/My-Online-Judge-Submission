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


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define    debug(a)     { cout << a <<endl; }

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)


#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
int v[100005];

int main()
{
   // READ("in.txt");
    //WRITE("out.txt");
    int n,x;
    //vector<int> v;
    while(scanf("%d",&n)!=EOF)
    {
        CLR(v);
        getI(x);
        //int k;
        for(int i=1; i<=n; i++)
        {
            getI(v[i]);
            //v.push_back(k);
        }
        int ans=0,z=0;
        int res=INF;
        for(int i=1;i<=n;i++)
        {
            int k=i;
            ans=0;
            for(int j=i;j<=n;j++)
            {
                ans+=v[j];

                if(ans>=x)
                {

                    while(ans-v[k]>=x)
                        ans-=v[k++];
                    //k--;
                    i=k+1;
                    res=min(res,j-k+1);
                    break;
                }
            }
        }
        if(res==INF)res=0;
        printf("%d\n",res);
        //v.clear();
    }

    return 0;
}


