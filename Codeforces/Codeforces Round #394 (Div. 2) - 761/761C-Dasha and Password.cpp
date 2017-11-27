#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 1e5;
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
string arr[88];
int dp[55][10];
int value(char x)
{
    if(isdigit(x))return 0;
    if(isalpha(x))return 1;
    return 2;
}
int minuss(int num)
{
    num--;
    if(num<0)num=m-1;
    return num;
}
int alft[55];//,arght[55];
int diglft[55];
int onno[55];
int call(int num,int mask)
{
//    debug(mask)
    if(POPCOUNT(mask)==3)return 0;
    if(num==n)return INF;
    int &ret=dp[num][mask];
    if(ret!=-1)return ret;
    ret=INF;
    ret=min(ret,call(num+1,bitOn(mask,0))+alft[num]);
    ret=min(ret,call(num+1,bitOn(mask,1))+diglft[num]);
    ret=min(ret,call(num+1,bitOn(mask,2))+onno[num]);
//    debug(num,ret)
    return ret;
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m)
    {
        repI(i,n)cin>>arr[i];
//        SET(dp);
        repI(i,n)
        {
            /// alpha
            int lft=INF,rght=0;
            repI(j,m)
            {
                if(isalpha(arr[i][j]))
                {
                    lft=j;
                    break;
                }
            }
            int flg=0;
            ROF(j,m-1,0)
            {
                rght++;
                if(isalpha(arr[i][j]))
                {
                    flg=1;
                    break;
                }
            }
//            debug(isalpha('*'))
            if(!flg)rght=INF;
//            debug(lft,rght)
            alft[i]=min(lft,rght);
            /// digit
            lft=INF,rght=0;
            repI(j,m)
            {
                if(isdigit(arr[i][j]))
                {
                    lft=j;
                    break;
                }
            }
            flg=0;
            ROF(j,m-1,0)
            {
                rght++;
                if(isdigit(arr[i][j]))
                {
                    flg=1;
                    break;
                }
            }
            if(!flg)rght=INF;
            diglft[i]=min(lft,rght);
            ///onno tar jonno
            lft=INF,rght=0;
            repI(j,m)
            {
                if(!isalpha(arr[i][j])&&!isdigit(arr[i][j]))
                {
                    lft=j;
                    break;
                }
            }
            flg=0;
            ROF(j,m-1,0)
            {
                rght++;
                if(!isalpha(arr[i][j])&&!isdigit(arr[i][j]))
                {
                    flg=1;
                    break;
                }
            }
            if(!flg)rght=INF;
            onno[i]=min(lft,rght);
        }
//        repI(i,n)debug(alft[i],diglft[i],onno[i])
        SET(dp);
        cout<<call(0,0)<<endl;

    }


    return 0;
}