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
#define    FOR(i,L,R)       for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R)       for (int i = (int)(L); i >= (int)(R); i--)
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
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi                vector < int >
#define    vii                vector < vector < int > >
#define    pii                pair< int, int >
#define    ff                first
#define    ss                second
#define    ll               long long
#define    ull                unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

int kdx[]={-1,1,0,0,-1,-1,1,1};
int kdy[]={0,0,-1,1,-1,1,1,-1};

int hdx[] = {-2,-2,2,2,-1,-1,1,1};
int hdy[] = {1,-1,-1,1,2,-2,-2,2};

pii wking, wbishop, wknight, bking;

int check(pii wk, pii wb, pii wkn, pii bk)
{
    int mark[8][8];
    CLR(mark);

    if(wk.ff == wb.ff && wk.ss==wb.ss) return 0;
    if(wk.ff == wkn.ff && wk.ss==wkn.ss) return 0;
    if(wk.ff == bk.ff && wk.ss==bk.ss) return 0;
    if(wb.ff == wkn.ff && wb.ss == wkn.ss) return 0;
    if(wb.ff == bk.ff && wb.ss == bk.ss) return 0;
    if(wkn.ff == bk.ff && wkn.ss == bk.ss) return 0;

    FOR(i,0,7)
    {
        int x = wk.ff + kdx[i];
        int y = wk.ss + kdy[i];

        if(x==bk.ff && y==bk.ss) return 0;
    }
    FOR(i,0,7)
    {
        int x = wk.ff + kdx[i];
        int y = wk.ss + kdy[i];
        if(x>=0 && y>=0 && x<8 && y<8)
        {
            mark[x][y]++;
        }
    }
    FOR(i,0,7)
    {
        int x = wkn.ff + hdx[i];
        int y = wkn.ss + hdy[i];
        if(x>=0 && y>=0 && x<8 && y<8)
        {
            mark[x][y]++;
        }
    }
    for(int i=wb.ff-1, j=wb.ss-1; i>=0 && j>=0; i--, j-- )
    {
        mark[i][j]++;
        if(i==wk.ff && j==wk.ss) break;
        if(i==wkn.ff && j==wkn.ss) break;
        if(i==bk.ff && j==bk.ss) break;
    }
    for(int i=wb.ff-1, j=wb.ss+1; i>=0 && j<8; i--, j++ )
    {
        mark[i][j]++;
        if(i==wk.ff && j==wk.ss) break;
        if(i==wkn.ff && j==wkn.ss) break;
        if(i==bk.ff && j==bk.ss) break;
    }
    for(int i=wb.ff+1, j=wb.ss+1; i<8 && j<8; i++, j++ )
    {
        mark[i][j]++;
        if(i==wk.ff && j==wk.ss) break;
        if(i==wkn.ff && j==wkn.ss) break;
        if(i==bk.ff && j==bk.ss) break;
    }
    for(int i=wb.ff+1, j=wb.ss-1; i<8 && j>=0; i++, j-- )
    {
        mark[i][j]++;
        if(i==wk.ff && j==wk.ss) break;
        if(i==wkn.ff && j==wkn.ss) break;
        if(i==bk.ff && j==bk.ss) break;
    }

    FOR(i,0,7)
    {
        int x = bk.ff + kdx[i];
        int y = bk.ss + kdy[i];

        if(x==wk.ff && y==wk.ss)
        {
            if(mark[x][y]==0) return 0;
            //return 1;
        }
        if(x==wb.ff && y==wb.ss)
        {
            if(mark[x][y]==0) return 0;
            //return 1;
        }
        if(x==wkn.ff && y==wkn.ss)
        {
            if(mark[x][y]==0) return 0;
            //return 1;
        }

        if(x>=0 && y>=0 && x<8 && y<8)
        {
            if(mark[x][y]==0) return 0;
        }
    }
//    if(wb.ff==3 && wb.ss==3){
//            debug("**", bking.ff, bking.ss, mark[bking.ff][bking.ss])
//    }
    if(mark[bking.ff][bking.ss]==0) return 0;

//    if(wb.ff==3 && wb.ss==3){
//            debug("**", bking.ff, bking.ss)
//    FOR(i,0,7)
//    {
//        FOR(j,0,7)
//        {
//            cout << mark[i][j] << " ";
//        }
//        cout << endl;
//    }}
    return 1;
}

void nowPrint(int kerDara, int r, int c)
{
    debug(kerDara)
    char k[3] = {'K', 'B', 'N'};
    cout << k[kerDara] ;
    cout << (char)(r + 'a') ;
    cout << (char)(c+'0'+1) << endl;
}

int bishopRun()
{
    for(int i=wbishop.ff-1, j=wbishop.ss-1; i>=0 && j>=0; i--, j-- )
    {
        if(i==wking.ff && j==wking.ss) break;
        if(i==wknight.ff && j==wknight.ss) break;
        if(i==bking.ff && j==bking.ss) break;
        int kk = check(wking, MP(i,j), wknight, bking);
        if(kk==1)
        {
            nowPrint(1, i, j);
            return 1;
        }
    }

    for(int i=wbishop.ff-1, j=wbishop.ss+1; i>=0 && j<8; i--, j++ )
    {
        if(i==wking.ff && j==wking.ss) break;
        if(i==wknight.ff && j==wknight.ss) break;
        if(i==bking.ff && j==bking.ss) break;
        int kk = check(wking, MP(i,j), wknight, bking);
        if(kk==1)
        {
            nowPrint(1, i, j);
            return 1;
        }
    }
    for(int i=wbishop.ff+1, j=wbishop.ss+1; i<8 && j<8; i++, j++ )
    {
        if(i==wking.ff && j==wking.ss) break;
        if(i==wknight.ff && j==wknight.ss) break;
        if(i==bking.ff && j==bking.ss) break;
        int kk = check(wking, MP(i,j), wknight, bking);
        if(kk==1)
        {
            nowPrint(1, i, j);
            return 1;
        }
    }
    for(int i=wbishop.ff+1, j=wbishop.ss-1; i<8 && j>=0; i++, j-- )
    {
        if(i==wking.ff && j==wking.ss) break;
        if(i==wknight.ff && j==wknight.ss) break;
        if(i==bking.ff && j==bking.ss) break;

        int kk = check(wking, MP(i,j), wknight, bking);
        if(kk==1)
        {
            nowPrint(1, i, j);
            return 1;
        }
    }
    return 0;
}

int knightRun()
{
    // horse
    int dx[] = {-2,-2,2,2,-1,-1,1,1};
    int dy[] = {1,-1,-1,1,2,-2,-2,2};

    FOR(i,0,7)
    {
        int x = wknight.ff + dx[i];
        int y = wknight.ss + dy[i];
        if(x>=0 && y>=0 && x<8 && y<8)
        {
            int kk = check(wking, wbishop, MP(x,y), bking);
            debug(kk, wknight.ff, wknight.ss, x, y)
            if(kk==1)
            {
                nowPrint(2, x, y);
                return 1;
            }
        }
    }
    return 0;
}

int kingRun()
{
    // 8 direction
    int dx[]={-1,1,0,0,-1,-1,1,1};
    int dy[]={0,0,-1,1,-1,1,1,-1};

    FOR(i,0,7)
    {
        int x = wking.ff + dx[i];
        int y = wking.ss + dy[i];

        if(x>=0 && y>=0 && x<8 && y<8)
        {
            int kk = check(MP(x,y) , wbishop, wknight, bking);
            if(kk==1)
            {
                nowPrint(0, x, y);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
//    #ifdef dipta007
        READ("chess2.in");
        WRITE("chess2.out");
//    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string wk, wb, wkn, bk;
    while( cin >> wk )
    {
        cin >> wb;
        cin >> wkn;
        cin >> bk;

        wking.ff = wk[0] - 'a';
        wking.ss = wk[1] - '0' - 1;

        wbishop.ff = wb[0] - 'a';
        wbishop.ss = wb[1] - '0' - 1;

        wknight.ff = wkn[0] - 'a';
        wknight.ss = wkn[1] - '0' - 1;

        bking.ff = bk[0] - 'a';
        bking.ss = bk[1] - '0' - 1;

        int flg = 0;
        flg = flg || bishopRun();

        flg = flg || knightRun();

        flg = flg || kingRun();

        if(flg==0) cout << "impossible" << endl;
    }

    return 0;
}