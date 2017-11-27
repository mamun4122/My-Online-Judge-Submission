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
#define MAX 2000006
int arr[MAX];


pii tree[MAX*4];

void init(int node, int b, int e)
{
 if(b == e)
 {
     tree[node] = pii(-1,b);
  return;
 }
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 init(Left, b, mid);
 init(Right, mid+1, e);
 tree[node] = tree[Left];
 if(tree[Right].ff < tree[node].ff)
        tree[node] = tree[Right];
}
void getans(int node, int b, int e)
{
 if(b == e)
 {
     arr[b] = tree[node].ff;
     if(arr[b] == -1)
            arr[b] = 0;
  return;
 }
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 getans(Left, b, mid);
 getans(Right, mid+1, e);
}
pii query(int node, int b, int e, int i, int j)
{
 if (i > e || j < b) return pii(INF,b);
 if (b >= i && e <= j) return tree[node];
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 pii p1 = query(Left,b,mid,i,j);
 pii p2 = query(Right,mid+1,e,i,j);
 pii ret = p1;
 if(p2.ff < p1.ff)
        ret = p2;
    return ret;
}
void update(int node, int b, int e, int i, int newvalue)
{
 if (i > e || i < b) return;
 if (b >= i && e <= i) {
  tree[node] = pii(newvalue,b);
  return;
 }
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 update(Left,b,mid,i,newvalue);
 update(Right,mid+1,e,i,newvalue);
 tree[node] = tree[Left];
 if(tree[Right].ff < tree[node].ff)
        tree[node] = tree[Right];
}
vector<string> fck;
vector<int> v[100005];
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> t)
    {
        repI(i,t)v[i].clear();
        fck.clear();
        int len = 0;
//        SET(arr);
        int mx = 0;
        string s;
        repI(cs,t)
        {
            cin >> s;
            fck.push_back(s);
            cin >> n;
            rep(i,n)
            {
                cin >> m;
                v[cs].PB(m);
                mx = max(mx, m+(int)s.size()-1);
            }
        }
        init(1,1,mx);
        repI(cs,fck.size())
        {
            s = fck[cs];
//            debug(s)
            int tmp = s.size()-1;
            repI(i,v[cs].size())
            {
                int l = v[cs][i];
                int r = l + tmp;
                pii vua = query(1,1,mx,l,r);
//                debug(l,r)
                while(vua.ff == -1)
                {
                    int ind = vua.ss - l;
//                    debug(ind,l,vua.ss)
                    update(1,1,mx,vua.ss,s[ind]-'a');
                    vua = query(1,1,mx,l,r);
                }
            }
//            debug("sssss")
        }
        getans(1,1,mx);
        rep(i,mx)
        {
            printf("%c",arr[i]+'a');
        }
        puts("");
    }

    return 0;
}