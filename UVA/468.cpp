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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double



const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************
int t,n,m;

struct data
{
    char x;
    int val;
    data()
    {
        ;
    }
    data(char xx,int yy)
    {
        x=xx;val=yy;
    }
};

vector<data>v,p;
map<char,char>mp;
map<char,int>inv;

bool cmp(const data &a,const data &b)
{
    if(a.val>b.val)return true;
    return false;
}


int main() {
//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    int flg=0;
    while(t--)
    {
        inv.clear();
        if(flg)puts("");
        flg=1;
        v.clear();
        p.clear();
        mp.clear();
        string a,b;
        cin>>a>>b;
//        debug(a,b);
        int x[54],y[54];
        CLR(x);
        CLR(y);
        repI(i,a.size())
        {
            if(a[i]>='A'&&a[i]<='Z')x[a[i]-65]++;
            else x[a[i]-97+26]++;
        }
        repI(i,b.size())
        {
            if(b[i]>='A'&&b[i]<='Z')y[b[i]-65]++;
            else y[b[i]-97+26]++;
        }
        repI(i,52)if(x[i])v.push_back(i<26?data(i+65,x[i]):data(i-26+97,x[i]));
        repI(i,52)if(y[i])p.push_back(i<26?data(i+65,y[i]):data(i-26+97,y[i]));
        sort(ALL(v),cmp);sort(ALL(p),cmp);
        for(int i=0,j=0;i<p.size();i++,j++)
        {
            if(i>=v.size())break;
//            debug(p[i].x,p[i].val,v[i].x,v[i].val)
            mp[p[i].x]=v[i].x;
            inv[p[i].x]=1;
        }
        repI(i,b.size())if(inv[b[i]])printf("%c",mp[b[i]]);
        puts("");

    }



    return 0;
}

