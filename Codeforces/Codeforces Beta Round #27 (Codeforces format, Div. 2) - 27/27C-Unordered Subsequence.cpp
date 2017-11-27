#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
vector<int> Sequence,I,L;

int LisNlogK()
{
    int i;
    I.clear();
    L.clear();
    I.push_back(-INF);
    for( i = 1; i <= n; i++ )I.push_back(INF);
    int LisLength = 0;
    for( i = 0; i < n; i++ )
    {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while( low <= high )
        {
            mid = ( low + high ) / 2;
            if( I[mid] <= Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = Sequence[i];
        if( LisLength < low )
            LisLength = low;
        L.push_back(low);
    }
    return LisLength;
}

#define MAX 100005

pii treemx[MAX*4];
pii treemn[MAX*4];

pii callmx(pii a,pii b)
{
    pii tmp;
    tmp.ff = max(a.ff,b.ff);
    if(tmp.ff == a.ff)tmp.ss = a.ss;
    else tmp.ss = b.ss;
    return tmp;
}
pii callmn(pii a,pii b)
{
    pii tmp ;
    tmp.ff= min(a.ff,b.ff);
    if(tmp.ff == a.ff)tmp.ss = a.ss;
    else tmp.ss = b.ss;
    return tmp;
}

void init(int node,int b,int e)
{
 if(b==e)
 {
  treemx[node].ff = treemn[node].ff = Sequence[b-1];
  treemx[node].ss = treemn[node].ss = b;
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 treemx[node]=callmx(treemx[Left],treemx[Right]);
 treemn[node]=callmn(treemn[Left],treemn[Right]);
}
pii querymx(int node,int b,int e,int i,int j)
{
 if (i > e || j < b) return pii(-INF,0);
 if (b >= i && e <= j) return treemx[node];
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 pii p1=querymx(Left,b,mid,i,j);
 pii p2=querymx(Right,mid+1,e,i,j);
 return callmx(p1,p2);
}
pii querymn(int node,int b,int e,int i,int j)
{
 if (i > e || j < b) return pii(INF,0);
 if (b >= i && e <= j) return treemn[node];
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 pii p1=querymn(Left,b,mid,i,j);
 pii p2=querymn(Right,mid+1,e,i,j);
 return callmn(p1,p2);
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
//        CLR(mark);
        Sequence.clear();
        rep(i,n)
        {
            int x;
            getI(x);
            Sequence.push_back(x);
        }
        init(1,1,n);
        int val = LisNlogK();
        repI(i,n)Sequence[i] *= -1;
        int val1 = LisNlogK();
        if(val == n || val1==n || n<3)
        {
            puts("0");
            continue;
        }
        int a,b,c;
        int flg = 0;
        rep(i,n)
        {
            if(i==1)continue;
            if(i==n)continue;
            int val = Sequence[i-1]*-1;
            pii bammx = querymx(1,1,n,1,i-1);
            pii danmx = querymx(1,1,n,i+1,n);
            debug(bammx.ff,bammx.ss);
            if(bammx.ff>val && danmx .ff>val)
            {
                a = bammx.ss;
                b = i;
                c = danmx.ss;
                flg = 1;
            }
            if(flg)break;
            pii bammn = querymn(1,1,n,1,i-1);
            pii danmn = querymn(1,1,n,i+1,n);
            debug(bammn.ff,bammn.ss);
            if(bammn.ff<val && danmn .ff<val)
            {
                a = bammn.ss;
                b = i;
                c = danmn.ss;
                flg = 1;
            }
            if(flg)break;

        }
        if(flg)
        {
            printf("3\n");
            printf("%d %d %d\n",a,b,c);
        }
        else
        {
            printf("%d\n",n);
            repI(i,n)
            {
                if(i)printf(" ");
                printf("%d",i+1);
            }
            puts("");
        }


    }

    return 0;
}