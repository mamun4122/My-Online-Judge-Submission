#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
////const int INF = 0x7f7f7f7f;
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
struct Edge{
	int from,to;
	ll cap,flow,cost;
	Edge(int from,int to,ll cap,ll flow,ll cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};
const int MAXN=500+5;
const ll INF=1e17;
struct MCMF{
	int n,m,s,t;
	vector<Edge> edges;
	vector<ll> G[MAXN];
	bool inq[MAXN];
	ll d[MAXN],p[MAXN],a[MAXN];
	void init(int n)
	{
		this->n=n;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addEdge(int from,int to,ll cap,ll cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(ll &flow,ll& cost)
	{
		for(int i=0;i<n;++i) d[i]=INF,inq[i]=0;
		queue<int> que;
		que.push(s);
		inq[s]=1;d[s]=0;p[s]=0;a[s]=INF;
		while(!que.empty())
		{
			int x=que.front();que.pop();
			inq[x]=0;
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
				{
					d[e.to]=d[x]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[x],e.cap-e.flow);
					if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
				}
			}
		}
		if(d[t]==INF) return 0;
		flow+=a[t];
		/// changed here
		cost+=d[t]*a[t];
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	pair<ll,ll> mincost(int s,int t)
	{
		this->s=s;this->t=t;
		ll flow=0,cost=0;
		while(spfa(flow,cost));
		return {flow,cost};
	}
}mcmf;
pair<int,pii> arr[5005];

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m)){
        mcmf.init(n+1);
        rep(i,m){
            getIII(arr[i].ff,arr[i].ss.ff,arr[i].ss.ss);
        }
        ll x,y;
        getLL(x,y);
        rep(i,m){
            mcmf.addEdge(arr[i].ff,arr[i].ss.ff,y,arr[i].ss.ss);
            mcmf.addEdge(arr[i].ss.ff,arr[i].ff,y,arr[i].ss.ss);
        }
        mcmf.addEdge(0,1,x,0);
        pair<ll,ll> ans = mcmf.mincost(0,n);
//        debug(ans.ff,ans.ss);
        if(ans.ff != x)puts("Impossible.");
        else printf("%lld\n",ans.ss);
    }

    return 0;
}

