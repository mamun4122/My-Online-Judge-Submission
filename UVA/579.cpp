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
#define    getLL(a,b) 	     scanf("%lld%lld", &a, &b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld", &a, &b, &c)
#define    getF(n)           scanf("%lf",&n)


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
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int a,b,c,d;
    double res=0,k,z;
    while(scanf("%d:%d",&a,&b)&&(a||b))
    {
        /*c=12-a;
        res=c*5*6;
        z=res;
        //cout<<res<<" ";
        d=b*6;
        //cout<<b<<" ";
        res+=d;
        k=(double)360/d;
        res-=(30/k);
        */
        res=(a*5*6)+((double)b/2);
        c=b*6;
        res=fabs(res-c);
        res=min(res,360-res);
        printf("%.3lf\n",res);
    }


    return 0;
}



