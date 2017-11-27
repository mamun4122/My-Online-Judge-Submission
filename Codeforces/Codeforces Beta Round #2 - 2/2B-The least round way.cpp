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
#define MAX 1005
#define two 0
#define five 1
int arr[MAX][MAX];
int div1[2][MAX][MAX];
int dp[2][MAX][MAX];
int call(int ind,int x,int y)
{
    if(x == n-1 && y == m-1)
        return div1[ind][x][y];
    if(x >= n || y >= m)
        return 1e9;
    int &ret = dp[ind][x][y];
    if(ret != -1)
        return ret;
    ret = 1e9;
    ret = min(ret, call(ind,x+1,y)+div1[ind][x][y]);
    ret = min(ret, call(ind,x,y+1)+div1[ind][x][y]);
    return ret;
}
void print(int ind,int x,int y)
{
    if(x == n-1 && y == m-1)
    {
        puts("");
        return;
    }
    if(call(ind,x+1,y) <= call(ind,x,y+1))
    {
        printf("D");
        print(ind,x+1,y);
    }
    else
    {
        printf("R");
        print(ind,x,y+1);
    }
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        CLR(div1);
        SET(dp);
        pii indx;
        int flag = 0;
        repI(i,n)repI(j,n)
        {
            getI(m);
            arr[i][j] = m;
            if(m == 0)
            {
                indx = pii(i,j);
                flag = 1;
                continue;
            }
            while(m%2 == 0 && m) m /= 2, div1[two][i][j]++;
            while(m%5 == 0 && m) m /= 5, div1[five][i][j]++;
        }
        m = n;
        int anst = call(two,0,0);
        int ansf = call(five,0,0);
        if(flag && min(ansf,anst) >= 1)
        {
            debug("");
            printf("1\n");
            repI(i,indx.ff)printf("D");
            repI(i,n-1)printf("R");
            FOR(i,indx.ff+1,n-1)printf("D");
            puts("");
        }
        else if(anst <= ansf)
        {
            printf("%d\n",anst);
            print(two,0,0);
        }
        else
        {
            printf("%d\n",ansf);
            print(five,0,0);
        }
    }
    return 0;
}