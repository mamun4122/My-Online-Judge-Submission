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
#define    ff   first
#define    ss   second
#define    ll  long long
#define    pii   pair< ll, ll >
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
#define mx 400005
int arr[mx];
struct info
{
    int sum;
    int prop;
    int xorr;
}tree[mx*4];
info call(info a,info b)
{
    info tmp;
    ///merge two info
    tmp.sum = a.sum + b.sum;
    tmp.prop = tmp.xorr = 0;
    return tmp;
}
void init(int node,int b,int e)
{
 if(b==e)
 {
     ///do something
     tree[node].sum = tree[node].prop = tree[node].xorr = 0;
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node] = call(tree[Left],tree[Right]);
}
void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop = 0;
        tree[node].xorr = 0;
        return;
    }
 int Left = node<<1;
 int Right = (node<<1)+1;
 int mid = (b+e)>>1;
 ///update propagation
 if(tree[node].prop){
        tree[Left].prop = tree[node].prop;
        tree[Right].prop = tree[node].prop;
 }
 if(tree[node].prop)
    {
        tree[Left].xorr = tree[node].xorr;
        tree[Right].xorr = tree[node].xorr;
 }
 else
    {
        tree[Left].xorr ^= 1;
        tree[Right].xorr ^= 1;
    }
    if(tree[node].prop)
    {
        tree[Left].sum = tree[node].prop == 1? mid-b+1:0;
        tree[Right].sum = tree[node].prop == 1? e-mid:0;
    }
    if(tree[node].xorr)
        tree[Left].sum = mid-b+1-tree[Left].sum;
    if(tree[node].xorr)
        tree[Right].sum = e-mid-tree[Right].sum;

    tree[node].prop = 0;
    tree[node].xorr = 0;

}
int query(int node,int b,int e,int i,int j)
{
 if(tree[node].prop)propagate(node,b,e);
 if(tree[node].xorr)propagate(node,b,e);
 if(b == e)
    {
        ///do something
        return b;
    }
 int Left = node<<1;
 int Right = (node<<1)+1;
 int mid = (b+e)>>1;
    if(tree[Left].sum < mid-b+1)
        return query(Left,b,mid,i,j);
    else if(tree[Right].sum < e-mid)
        return query(Right,mid+1,e,i,j);
    return -1;
}
int type;
void update(int node,int b,int e,int i,int j)
{
 if(tree[node].prop)propagate(node,b,e);
 if(tree[node].xorr)propagate(node,b,e);
 if (i > e || j < b) return;
 if (b >= i && e <= j)
    {
        ///do something
        if(type == 1 || type == 2)
        {
            tree[node].sum = type == 1 ? e-b+1 : 0;
            tree[node].prop = type;
            tree[node].xorr = 0;
        }
        else
        {
            tree[node].sum = e-b+1-tree[node].sum;
            tree[node].xorr ^= 1;
        }
  return;
 }
 int Left = node*2;
 int Right = (node*2)+1;
 int mid = (b+e)/2;
 update(Left,b,mid,i,j);
 update(Right,mid+1,e,i,j);
 tree[node] = call(tree[Left],tree[Right]);
}
set<ll> st;
map<ll,int> mp;
map<int,ll> inv;
vector<pair<int,pii> > v;

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
        st.clear();
        mp.clear();
        inv.clear();
        rep(i,n)
        {
            int a;
            ll b,c;
            getI(a);
            getLL(b,c);
            v.push_back(MP(a,pii(b,c)));
            st.insert(b);
            st.insert(c);
        }
        int cnt = 1;
        ll lst = 0;
        for(auto it: st)
        {
            ll val = it;
            if(val - lst > 1)
            {
                mp[lst+1] = cnt;
                inv[cnt++] = lst+1;
            }
            mp[val] = cnt;
            inv[cnt++] = val;
            lst = val;
//            debug(val)
        }
        int tot = cnt-1;
        init(1,1,tot);

        repI(i,n)
        {
            type = v[i].ff;
            int l = mp[v[i].ss.ff];
            int r = mp[v[i].ss.ss];
            update(1,1,tot,l,r);
            ll ans = query(1,1,tot,1,tot);
//                debug(ans)
            if(ans == -1)
                ans = inv[tot]+1;
            else
                ans = inv[ans];
            printf("%lld\n",ans);

//            rep(j,tot)
//                debug(query(1,1,tot,j,j));
        }
//        debug("*********************")

    }

    return 0;
}