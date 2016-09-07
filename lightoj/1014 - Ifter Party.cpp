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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    vector<int> v;
    int t;
    getI(t);
    for(int i=1;i<=t;i++)
    {
        int a,b,cnt=0;
        getII(a,b);
        int k=a-b;
        printf("Case %d:",i);
        for(int j=1;j<=sqrt(k);j++)
        {
            if(k%j==0&&k/j>b)
            {
                //if(cnt)printf(" ");
                if(k/j>b)
                v.push_back(k/j);
                //printf(" %d",k/j);
                if(k/j!=j&&j>b)
                    v.push_back(j);
                  //  printf(" %d")
            }
        }
        sort(ALL(v));

        if(v.size()==0)
        {
            printf(" impossible\n");
        }
        else
        {
            for(int j=0;j<v.size();j++)
                printf(" %d",v[j]);
            puts("");
        }
        v.clear();
    }

    return 0;
}


