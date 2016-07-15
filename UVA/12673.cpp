#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);

#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);

#define PB(x) push_back(x)

#define FOREACH(i,t) for(typeof(t.begin()) i=t.begin(); i!=t.end();i++)
#define ALL(p) p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()

#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p, 0,sizeof(p))

#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d %d",&a,&b)
#define getIII(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define getL(a) scanf("%lld",&a)
#define getLL(a,b) scanf("%lld %lld",&a,&b)
#define getLLL(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define getC(n) scanf("%c",&n)
#define getF(n) scanf("%lf",&n)
#define getS(n) scanf("%s",&n)

#define vi vector <int>
#define vii vector < vector <int> >
#define pii pair <int,int>
#define ff first
#define ss second
#define ll long long

template < class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template < class T > inline T gcd(T a,T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ); }
template < class T > inline T lcm(T a,T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }



#define dipta007
#ifdef dipta007
    #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)
#endif

struct debugger {
    template <typename T> debugger& operator, (const T& v) {
        cerr << v << " ";
        return *this;
    }
}dbg;




int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m;
    while(~getII(n,m))
    {
        vi v;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            getII(x,y);
            if(x-y>0) res+=3;
            else
                v.PB(x-y);
        }
        sort(ALL(v));
        reverse(ALL(v));
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                if(m>0)
                {
                    m--;
                    res+=3;
                }
                else
                {
                    res+=1;
                }
            }
            else
            {
                if(m>abs(v[i]))
                {
                    m=m-(abs(v[i])+1);
                    res+=3;
                }
                else if(m==abs(v[i]))
                {
                    m-=abs(v[i]);
                    res+=1;
                }
                else break;
            }
        }
        printf("%d\n",res);
    }

    return 0;
}
