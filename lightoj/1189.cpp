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

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
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
ll fact[1000];
#define mx 1000000000000000000
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    //debug(mx);
    fact[0]=1;
    for(int i=1;i<=21;i++)
    {
        fact[i]=fact[i-1]*i;
        //debug(fact[i]);
    }
    int t;
    getI(t);
    ll k;
    for(int i=1;i<=t;i++)
    {
        vector<int> v;
        getL(k);
        int x=INF;
        for(int j=0;j<=20;j++)
        {
            if(fact[j]>k){x=j-1;break;}
            if(fact[j]==k){x=j;break;}
        }
        ll sum=k;
        while(x>=0&&sum>0)
        {
            if(sum>=fact[x])
            {
                sum-=fact[x];
                v.push_back(x);
            }
            x--;
        }
        sort(ALL(v));
        if(sum!=0)
            printf("Case %d: impossible\n",i);
        else
        {
            printf("Case %d: ",i);
            for(int j=0;j<v.size();j++)
            {
                if(j>0)printf("+");
                printf("%d!",v[j]);
            }
            puts("");
        }
    }

    return 0;
}


