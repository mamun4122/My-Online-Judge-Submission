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

int arr[505][505];
int sum[505][505];
int maxi[505][505];
int fin[505][505];
#define MAX 505
int tree[MAX*4];
int idx;
void init(int node, int b, int e)
{
 if(b == e)
 {
  tree[node] = arr[idx][b];
  return;
 }
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 init(Left, b, mid);
 init(Right, mid+1, e);
 tree[node] = max(tree[Left],tree[Right]);
}
void init1(int node, int b, int e)
{
 if(b == e)
 {
  tree[node] = arr[b][idx];
  return;
 }
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 init1(Left, b, mid);
 init1(Right, mid+1, e);
 tree[node] = max(tree[Left],tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
 if (i > e || j < b) return -1;
 if (b >= i && e <= j) return tree[node];
 int Left = node*2;
 int Right = node*2+1;
 int mid = (b+e)/2;
 int p1 = query(Left,b,mid,i,j);
 int p2 = query(Right,mid+1,e,i,j);
 return max(p1, p2);
}


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
//        CLR(sum);
        rep(i,n)rep(j,m)arr[i][j] = INF;
//        CLR(arr);
        int k;
        getI(k);
        int q;
        getI(q);
        rep(i,q)
        {
            int a,b;
            getII(a,b);
            getI(arr[a][b]);
//            sum[a][b] = 1;
        }
//        rep(i,n)
//        {
//            rep(j,m)printf("%d ",sum[i][j]);
//            puts("");
//        }
//        rep(i,n)rep(j,m)sum[i][j] += sum[i][j-1];
//        rep(i,n)rep(j,m)sum[i][j] += sum[i-1][j];

//        rep(i,n)
//        {
//            rep(j,m)printf("%d ",arr[i][j]);
//            puts("");
//        }
//        puts("");
        rep(i,n)
        {
            idx = i;
            init(1,1,m);
            rep(j,m)
                maxi[i][j] = query(1,1,m,max(1,j-k+1),j);
            rep(j,m)arr[i][j] = maxi[i][j];
        }
//        rep(i,n)
//        {
//            rep(j,m)printf("%d ",arr[i][j]);
//            puts("");
//        }
//        puts("");

        rep(i,m)
        {
            idx = i;
            init1(1,1,n);
            rep(j,n)
                maxi[j][i] = query(1,1,n,max(1,j-k+1),j);
//            if(i == 2)rep(j,n)debug(maxi[j][i],arr[j][i])
            rep(j,n)arr[j][i] = maxi[j][i];
        }

//        rep(i,n)
//        {
//            rep(j,m)printf("%d ",arr[i][j]);
//            puts("");
//        }
//        puts("");
        int ans = INF;
        rep(i,n)
        {
            if(i+k-1 > n)break;
            rep(j,m)
            {
                if(j+k-1 > m)break;
                ans = min(ans,arr[i+k-1][j+k-1]);
            }
        }
        if(ans == INF)ans = -1;
        printf("%d\n",ans);

    }
    return 0;
}