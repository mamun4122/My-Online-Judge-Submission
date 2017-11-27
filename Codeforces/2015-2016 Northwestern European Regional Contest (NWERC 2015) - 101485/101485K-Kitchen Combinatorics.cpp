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

#ifdef mamunKmneSobPar
    #define DUMP(p) #p
    #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define DUMP(p)
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

ull MAX = 1000000000000000000LL;

bool isPossible(ull a, ull b)
{
    if(MAX / b < a) return 0;
    return 1;
}

ull dishCanBeMade[104];
ull canBe[104];
int mat[104][104];
vi dish[104];

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamunKmneSobPare
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,s,m,d,k;
    while(~getIII(n,s,m))
    {
        getII(d,k);

        ll aa[n+4];
        FOR(i,1,n)
        {
            getL(aa[i]);
        }

        CLR(canBe);

        int flg = 1;
        FOR(i,1,s+m+d)
        {
            int nn;
            getI(nn);
            FOR(j,1,nn)
            {
                int x;
                getI(x);
                dish[i].PB(x);
                debug(i, x)
            }
        }


        CLR(mat);

        FOR(i,1,k)
        {
            int x,y;
            getII(x,y);
            mat[x][y] = 1;
            mat[y][x] = 1;
        }

        ull res = 0;
        FOR(starter,1,s)
        {
            FOR(meal,1,m)
            {
                FOR(dinner,1,d)
                {

                    int a = starter;
                    int b = s + meal;
                    int c=  s + m + dinner;
                    if(mat[a][b] || mat[a][c] || mat[b][c])
                        continue;

//                    debug(a,b,c)

                    int use[1004];
                    CLR(use);

                    FOR(i,0,(int)dish[a].size()-1)
                    {
                        int x = dish[a][i];

                        use[x] ++;
                    }
                    FOR(i,0,(int)dish[b].size()-1)
                    {
                        int x = dish[b][i];

                        use[x] ++;
                    }
                    FOR(i,0,(int)dish[c].size()-1)
                    {
                        int x = dish[c][i];

                        use[x] ++;
//                        debug(x)
                    }
                    ull now = 1;

                    FOR(i,1,n)
                    {
//                        debug(a,b,c,dinner, i, use[i], dish[5][0])
                        if(use[i])
                        {
                            if(isPossible(now, aa[i])==1)
                            {
                                now *= aa[i];
                            }
                            else flg = 0;
                        }
                        if(!flg) break;
                    }


//                    if(isPossible(dishCanBeMade[a], now)==1)
//                    {
//                        now *= dishCanBeMade[a];
//                    }
//                    else flg = 0;
//
//                    if(isPossible(dishCanBeMade[b], now)==1)
//                    {
//                        now *= dishCanBeMade[b];
//                    }
//                    else flg = 0;
//
//                    if(isPossible(dishCanBeMade[c], now)==1)
//                    {
//                        now *= dishCanBeMade[c];
//                    }
//                    else flg = 0;
//
                    if(now + res <= MAX)
                    {
                        res += now;
                    }
                    else flg = 0;

                    if(!flg) break;
                }
                if(!flg) break;
            }
            if(!flg) break;
        }

        if(!flg) printf("too many\n");
        else printf("%llu\n",res);
    }


    return 0;
}