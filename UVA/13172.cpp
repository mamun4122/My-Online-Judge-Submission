#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 1e9;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
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
int adj[1005][1005];
int dist[1005][1005];
//int closest[10];
int num[10];
pii res[(1<<6)+5][10][10];
int dp[(1<<6)+5][10][10];
vector<int> edge[1005];
int tot;
int d[1005];
int fuck1[1005],fuck2[1005];
int mark[1005];
struct node
{
    int u,w;
    node(int a,int b)
    {
        u=a;
        w=b;
    }
    bool operator< (const node &p)const
    {
        return w > p.w;
    }
};
int dijktra(int src, int dest)
{
    rep(i,n)d[i] = INF;
    priority_queue<node> q;
    d[src] = 0;
    q.push(node(src,0));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        if(u == dest)
            return d[u];
        repI(i,edge[u].size())
        {
            int v = edge[u][i];
            if(d[u] + adj[u][v] < d[v])
            {
                d[v] = d[u] + adj[u][v];
                q.push(node(v,d[v]));
            }
        }
    }
    return INF;
}
//
//pii findclosest(int src)
//{
//    rep(i,n)d[i] = INF;
//    priority_queue<node> q;
//    d[src] = 0;
//    q.push(node(src,0));
//    while(!q.empty())
//    {
//        node top = q.top();
//        q.pop();
//        int u = top.u;
//        debug(u)
//        int flag = 1;
//        repI(i,tot)
//            if(u == num[i])
//                flag = 0;
//
//        if(flag)
//            return pii(d[u],u);
//            debug("fff")
//        repI(i,edge[u].size())
//        {
//            debug("fff")
//            int v = edge[u][i];
//            debug(v,adj[u][v])
//            if(d[u] + adj[u][v] < d[v])
//            {
//                d[v] = d[u] + adj[u][v];
//                q.push(node(v,d[v]));
//            }
//        }
//    }
//}
void calcAllPair()
{
    repI(i,tot)
    {
        FOR(j,i+1,tot-1)
        {
            int distan = dijktra(num[i], num[j]);
            dist[i][j] = distan;
            dist[j][i] = distan;
//            debug(i,j,distan)
        }
    }
}
pii etoborokno(pii a, pii b)
{
    if(a.ff < b.ff)return a;
    if(a.ff == b.ff)
        return a.ss < b.ss ? a : b;
    return b;
}
//int strt;
int cs;
pii parinakisu(int src1,int src2)
{

    rep(i,n)fuck1[i] = fuck2[i] = INF;
    priority_queue<node> q;
    fuck1[src1] = 0;
    q.push(node(src1,0));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        repI(i,edge[u].size())
        {
            int v = edge[u][i];
            if(fuck1[u] + adj[u][v] < fuck1[v])
            {
                fuck1[v] = fuck1[u] + adj[u][v];
                q.push(node(v,fuck1[v]));
            }
        }
    }
    fuck2[src2] = 0;
    q.push(node(src2,0));
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        repI(i,edge[u].size())
        {
            int v = edge[u][i];
            if(fuck2[u] + adj[u][v] < fuck2[v])
            {
                fuck2[v] = fuck2[u] + adj[u][v];
                q.push(node(v,fuck2[v]));
            }
        }
    }
    pii ans = pii(INF,INF);
    rep(i,n)if(!mark[i] && fuck1[i]+fuck2[i] < ans.ff)
        ans = pii(fuck1[i]+fuck2[i],i);
    return ans;
}

pii call(int mask,int prev,int strt)
{
//    debug(strt)
    if(POPCOUNT(mask) == tot)
    {
        ///fuck here
        return parinakisu(num[strt],num[prev]);
    }
    int &ret = dp[mask][prev][strt];
    if(ret == cs)
        return res[mask][prev][strt];
    ret = cs;
    pii res1 = pii(INF,INF);
    repI(i,tot)
    {
        if(bitCheck(mask,i) == 0)
        {
            pii tmp = call(bitOn(mask,i),i,strt==tot?i:strt);
            tmp.ff += prev == tot?0:dist[prev][i];
            res1 = etoborokno(res1, tmp);
        }
    }
    res[mask][prev][strt] = res1;


    return res1;
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
    WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    cs = 1;
    while(~getII(n,m))
    {
//        CLR(adj);
        rep(i,n)rep(j,n)adj[i][j] = i==j?0:INF;
        rep(i,n)edge[i].clear();
        rep(i,m)
        {
            int u,v,w;
            getIII(u,v,w);
//            debug(u,v,adj[u][v],)
            if(adj[u][v] == INF && u != v)
            {
//                debug(u,v)
                edge[u].PB(v);
                edge[v].PB(u);
            }
            adj[u][v] = min(adj[u][v],w);
            adj[v][u] = adj[u][v];
        }
//        rep(i,n)For
        rep(i,n)sort(ALL(edge[i]));
//        dijktra(1,227);
//        debug("");
        int q;
        getI(q);
        rep(i,q)
        {
//            SET(dp);

            getI(tot);
            repI(i,tot)
            getI(num[i]);

            calcAllPair();
            CLR(mark);
            repI(i,tot)mark[num[i]] = 1;
//            pii ans = pii(INF,INF);
            cs++;
            pii ans = call(0,tot,tot);
            printf("%d %d\n", ans.ss, ans.ff);

        }
        puts("---");
    }

    return 0;
}


