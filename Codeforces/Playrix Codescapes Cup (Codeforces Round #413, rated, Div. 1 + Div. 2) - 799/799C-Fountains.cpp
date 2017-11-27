#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = -3e5;
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
vector<pii> v[2];

#define MAX 100005
int arr[MAX];

int cur;
pii tree[MAX*4];
pii call(pii a, pii b)
{
    pii tmp;
    tmp.ff = max(a.ff,b.ff);
    tmp.ss = max(a.ss,b.ss);
    tmp.ss = max(tmp.ss,min(a.ff,b.ff));
    return tmp;
}

void init(int node,int b,int e)
{
 if(b==e)
 {
  tree[node] = pii(INF,INF);
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node] = pii(INF,INF);
}
pii res;
void query(int node,int b,int e,int i,int j)
{
 if (i > e || j < b) return;
 if (b >= i && e <= j)
    {
        res = call(res, tree[node]);
        return;// tree[node];
    }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 query(Left,b,mid,i,j);
 query(Right,mid+1,e,i,j);

}
void update(int node,int b,int e,int i,int newvalue)
{
 if (i > e || i < b) return;
 if (b >= i && e <= i) {
        pii tmp = pii(newvalue,INF);
        tree[node] = call(tree[node], tmp);
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 update(Left,b,mid,i,newvalue);
 update(Right,mid+1,e,i,newvalue);
 tree[node] = call(tree[Left],tree[Right]);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> t >> n >> m)
    {
        n++;
        m++;
        v[0].clear();
        v[1].clear();
        int maxa = INF;
        int maxb = INF;
        rep(i,t)
        {
            char x;
            int b,c;
            cin >> b >> c >> x;
            c++;
            if(x == 'C' && c <= n){
                v[0].PB(pii(b,c));
                maxa = max(maxa,b);
            }
            else if(x == 'D' && c <= m){
                v[1].PB(pii(b,c));
                maxb = max(maxb,b);
            }
        }
        n++;
        m++;
        int ans = 0;
        ans = max(maxa+maxb, ans);
        int tot = 100001;
        init(1,1,tot);
        repI(i,v[0].size())
        {
            update(1,1,tot,v[0][i].ss,v[0][i].ff);
        }
        repI(i,v[0].size())
        {
            res = pii(INF,INF);
            int cur = v[0][i].ff;
            int lft = n - v[0][i].ss;
            query(1,1,tot,1,lft);
            if(lft < v[0][i].ss)
                cur += res.ff;
            else
            {
                if(res.ff == cur)
                    cur += res.ss;
                else cur += res.ff;
            }
            ans = max(ans,cur);
        }
        /// diamond
        init(1,1,tot);
        repI(i,v[1].size())
        {
            update(1,1,tot,v[1][i].ss,v[1][i].ff);
        }
        repI(i,v[1].size())
        {
            res = pii(INF,INF);
            int cur = v[1][i].ff;
            int lft = m - v[1][i].ss;
            query(1,1,tot,1,lft);
            if(lft < v[1][i].ss)
                cur += res.ff;
            else
            {
                if(res.ff == cur)
                    cur += res.ss;
                else cur += res.ff;
            }
            ans = max(ans,cur);
        }
        cout << ans << endl;

    }
    return 0;
}