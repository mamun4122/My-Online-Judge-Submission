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
#include <ctime>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

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

#define iseq(a,b) (fabs(a-b)<EPS)

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



//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
int func(int a)
{
    int cnt=0;
    while(a)
    {
        cnt++;
        a/=10;
    }
    return cnt;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs=1,n,m;
    while(getI(n)&&n)
    {
        printf("Case %d:\n",cs++);
        int sum=0;
        rep(i,n)
        {
            getI(m);
            sum+=m;
        }
        //debug("sum",sum);
        if(sum%n==0)
        {
            int x=sum/n;
            if(x>=0)
                printf("%d\n",sum/n);
            else
                printf("- %d\n",abs(sum/n));
            continue;
        }
        //double avg=(double)sum/n;
        if(abs(sum)>=n)
        {
            int x=gcd(abs(sum),n);
            sum/=x;
            n/=x;
            int a=sum/n;
            int b=abs(sum)%n;
            debug(a,b,n,x)
            int cntb=0,cntc=0,tmp,tot=0;
            cntb=func(b);
            cntc=func(n);
            tot=func(abs(a));
            if(a<0)tot+=2;

            rep(i,tot)printf(" ");

            rep(i,cntc-cntb)printf(" ");

            printf("%d\n",b);
            if(a<0)printf("- ");
            printf("%d",abs(a));
            rep(i,cntc)printf("-");
            printf("\n");
            rep(i,tot)
            printf(" ");
            printf("%d\n",n);
            continue;

        }
        else
        {
            int x=gcd(abs(sum),n);
            int b=sum/x;
            int c=n/x;
            debug(b,c,x)
            int cntb=func(abs(b)),cntc=func(c);
            rep(i,cntc-cntb)
            printf(" ");
            if(b<0)printf("  ");
            printf("%d\n",abs(b));
            if(b<0)printf("- ");
            rep(i,cntc)printf("-");
            printf("\n");

            if(b<0)printf("  ");
            printf("%d\n",c);

        }
    }




    return 0;
}


