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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

#define MAX 200005
int arr[MAX];


int tree[MAX*4];

vector<pair<pii,int> >v;

void init(int node,int b,int e)
{
 if(b==e)
 {
  tree[node] = v[b-1].ff.ss;
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node] = max(tree[Left],tree[Right]);
}
int findleft(int node,int b,int e,int i,int j,int val)
{
 if (i > e || j < b) return 0;
 if(tree[node] < val)return 0;
 if (b ==  e)
    {
        return b;
    }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 int p2 = findleft(Right,mid+1,e,i,j,val);
 if(p2 != 0)return p2;
 int p1 = findleft(Left,b,mid,i,j,val);
 return max(p1,p2);
}

int findright(int node,int b,int e,int i,int j,int val)
{
 if (i > e || j < b) return n+1;
 if(tree[node] < val)return n+1;
 if (b ==  e)
    {
        return b;
    }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 int p1 = findright(Left,b,mid,i,j,val);
 if(p1 != n+1)return p1;

 int p2 = findright(Right,mid+1,e,i,j,val);
 return min(p1,p2);
}
int ans[MAX];

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        v.clear();
        rep(i,n)
        {
            int x,y;
            getII(x,y);
            v.push_back(MP(pii(x,y),i));
        }
        sort(ALL(v));
        init(1,1,n);
        rep(i,n)
        {
//            debug(v[i-1].ff.ff,v[i-1].ff.ss,v[i-1].ss)

            int lft = findleft(1,1,n,1,i-1,v[i-1].ff.ss);

            int rght = findright(1,1,n,i+1,n,v[i-1].ff.ss);
//            debug(lft,rght)
            if(lft == 0 && rght == n+1)
                ans[v[i-1].ss] = -1;
            else if(lft == 0) ans[v[i-1].ss] = v[rght-1].ss;
            else if(rght == n+1) ans[v[i-1].ss] = v[lft-1].ss;
            else
            {
                int ami = v[i-1].ff.ff;
                int lftpos = v[lft-1].ff.ff;
                int rghtpos = v[rght-1].ff.ff;
                if(ami-lftpos > rghtpos - ami)
                    ans[v[i-1].ss] = v[rght-1].ss;
                else if(ami-lftpos == rghtpos - ami)
                {
                    if(v[lft-1].ff.ss > v[rght-1].ff.ss)
                        ans[v[i-1].ss] = v[lft-1].ss;
                    else
                        ans[v[i-1].ss] = v[rght-1].ss;
                }
                else ans[v[i-1].ss] = v[lft-1].ss;
            }
        }
        rep(i,n)
        {
            if(i > 1)printf(" ");
            printf("%d",ans[i]);
        }
        puts("");
    }

    return 0;
}