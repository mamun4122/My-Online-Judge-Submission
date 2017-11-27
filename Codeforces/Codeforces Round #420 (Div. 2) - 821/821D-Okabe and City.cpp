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
vector<int> row[10005],col[10005];
int dist[10005];
//int cost[10005][10005];
unordered_map<int,int> cost[10005];
pii arr[10005];
bool actv[10005][10005];
priority_queue<pair<int,int> > pq;
void inRow(int r,int c,int cur,int id)
{
    if(r < 1 || r > n) return;
    repI(i,row[r].size())
    {
        int cc = row[r][i];
        int w = 1;
        if(abs(cc - c) <= 1 && cur == 0)
            w = 0;
        int nxtId = cost[r][cc];
//        if(nxtId == m+1)
        if(w+dist[id] < dist[nxtId])
        {
            dist[nxtId] = w+dist[id];
            pq.push(pii(-dist[nxtId],nxtId));
        }
    }
    if(r == n && actv[n][m] == 0 && cur < 2)
    {
        int w = 1;
        int nxtId = cost[n][m];
        if(w + dist[id] < dist[nxtId])
        {
            dist[nxtId] = w+dist[id];
            pq.push(pii(-dist[nxtId],nxtId));
        }
    }
}
void inCol(int r,int c,int cur, int id)
{
    if(c < 1 || c > m) return;
    repI(i,col[c].size())
    {
        int rr = col[c][i];
        int w = 1;
        if(abs(rr - r) <= 1 && cur == 0)
            w = 0;
        int nxtId = cost[rr][c];
        if(w+dist[id] < dist[nxtId])
        {
            dist[nxtId] = w+dist[id];
            pq.push(pii(-dist[nxtId],nxtId));
        }
    }
    if(c == m && actv[n][m] == 0 && cur < 2)
    {
        int w = 1;
        int nxtId = cost[n][m];
        if(w + dist[id] < dist[nxtId])
        {
            dist[nxtId] = w+dist[id];
            pq.push(pii(-dist[nxtId],nxtId));
        }
    }
}

int dijktra(int dest)
{
    while(!pq.empty())pq.pop();
    MEM(dist,63);
    pq.push(MP(0,cost[1][1]));
    dist[cost[1][1]] = 0;
    while(!pq.empty())
    {
        pii a = pq.top();pq.pop();
        int id = a.ss;
//        debug(arr[id].ff,arr[id].ss)
        if(a.ss == dest)
            return dist[a.ss];
        if(a.ff > dist[a.ss])
            continue;
        int r = arr[id].ff;
        int c = arr[id].ss;
        /// row gulai gelam
        inRow(r,c,0,id);
        inRow(r+1,c,1,id);
        inRow(r+2,c,2,id);
        inRow(r-1,c,1,id);
        inRow(r-2,c,2,id);
        /// col gulai gelam
        inCol(r,c,0,id);
        inCol(r,c+1,1,id);
        inCol(r,c+2,2,id);
        inCol(r,c-1,1,id);
        inCol(r,c-2,2,id);
    }

    return -1;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        int q;
        getI(q);
        rep(i,n)row[i].clear(),cost[i].clear();
        rep(i,m)col[i].clear();
//        CLR(cost);
        CLR(actv);
        rep(i,q)
        {
            int x,y;
            getII(x,y);
            row[x].PB(y);
            col[y].PB(x);
            cost[x][y] = i;
            actv[x][y] = 1;
            arr[i] = pii(x,y);
        }
//        row[n].PB(m);
//        col[m].PB(n);
        rep(i,n)UNIQUE(row[i]);
        rep(i,m)UNIQUE(col[i]);
        if(cost[n][m] == 0)
            cost[n][m] = q+1,arr[q+1] = pii(n,m);
        int ans = dijktra(cost[n][m]);
        printf("%d\n",ans);
    }
    return 0;
}