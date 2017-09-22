#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 10000050;
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

//namespace mcmf{
//    const int MAX = 20005;
////    const int INF = 1LL << 60;
//
//    int cap[MAX], flow[MAX], cost[MAX], dis[MAX];
//    int n, m, s, t, Q[4*MAX], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];
//
//    void init(int nodes, int source, int sink){
//        m = 0, n = nodes, s = source, t = sink;
//        for (int i = 0; i <= n; i++) last[i] = -1;
//    }
//
//    void addEdge(int u, int v, int c, int w){
//        adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
//        adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
//    }
//
//    bool spfa(){
//        int i, j, x, f = 0, l = 0;
//        for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;
//
//        dis[s] = 0, Q[l++] = s;
//        while (f < l){
//            i = Q[f++];
//            for (j = last[i]; j != -1; j = link[j]){
//                if (flow[j] < cap[j]){
//                    x = adj[j];
//                    if (dis[x] > dis[i] + cost[j]){
//                        dis[x] = dis[i] + cost[j], from[x] = j;
//                        if (!visited[x]){
//                            visited[x] = 1;
//                            if (f && rand() & 7) Q[--f] = x;
//                            else Q[l++] = x;
//                        }
//                    }
//                }
//            }
//            visited[i] = 0;
//        }
//        return (dis[t] != INF);
//    }
//
//    pair <int, int> solve(){
//        int i, j;
//        int mincost = 0, maxflow = 0;
//
//        while (spfa()){
//            int aug = INF;
//            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
//                aug = min(aug, cap[j] - flow[j]);
//            }
//            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
//                flow[j] += aug, flow[j ^ 1] -= aug;
//            }
//            maxflow += aug, mincost += aug * dis[t];
//        }
//        return make_pair(mincost, maxflow);
//    }
//}
//
//class MincostMaxFlow
//{
//private:
//
//	struct Edge
//	{
//		Edge(int s, int d, int cap, int cos): source(s), dest(d), residue(cap), cost(cos) { }
//		int source, dest, residue, cost;
//	};
//
//	int N;
//	vector< vector<int> > graph;
//	vector<Edge> edges;
//
//public:
//
//	void init(int n)
//	{
//		clear();
//		N = n;
//		graph.resize(N);
//	}
//
//	/// cap = source to dest er capacity
//	/// cap2 = dest to source er capacity
//	/// bi directional e cap2 = cap
//	void addEdge(int source, int dest, int cap, int cap2, int cos)
//	{
//		if (source >= N || dest >= N) { N = max(source,dest)+1; graph.resize(N); }
//		graph[source].push_back(edges.size());
//		graph[dest].push_back(edges.size()+1);
//		edges.push_back(Edge(source, dest, cap, cos));
//		edges.push_back(Edge(dest, source, cap2, -cos));
//	}
//
//	void clear() { N = 0; graph.clear(); edges.clear(); }
//
//	/// <flow_size, flow_cost>
//	pair<int, int> flow(int source, int dest)
//	{
//		int resFlow = 0, resCost = 0;
//		vector<int> pot(N, INF);
//		pot[source] = 0;
//
//		for (int step = 0; step < N; ++step)
//			for (int i = 0; i < edges.size(); ++i)
//			{
//				Edge & e = edges[i];
//				if (e.residue > 0)
//					pot[e.dest] = min(pot[e.dest], pot[e.source] + e.cost);
//			}
//
//		while (1)
//		{
//			vector<int> prev(N, -1), best(N, INF);
//			prev[source] = -2;
//			best[source] = 0;
//
//			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
//			manage.push(make_pair(0, source));
//
//			while (!manage.empty())
//			{
//				int node = manage.top().second, act = manage.top().first;
//				manage.pop();
//				if (best[node] < act) continue;
//
//				for (int i = 0; i < graph[node].size(); ++i)
//				{
//					Edge & e = edges[graph[node][i]];
//					int cost = best[node] + pot[node] - pot[e.dest] + e.cost;
//					if (e.residue > 0 && cost < best[e.dest])
//					{
//						best[e.dest] = cost;
//						prev[e.dest] = graph[node][i];
//						manage.push(make_pair(best[e.dest], e.dest));
//					}
//				}
//			}
//			if (prev[dest] == -1) break;
//
//			for (int i = 0; i < N; ++i)
//			{
//				if (best[i] == INF) pot[i] = INF;
//				else if (pot[i] < INF) pot[i] += best[i];
//			}
//
//			int fl = INF, node = dest;
//			while (prev[node] != -2)
//			{
//				fl = min(fl, edges[prev[node]].residue);
//				node = edges[prev[node]].source;
//			}
//
//			node = dest;
//			while (prev[node] != -2)
//			{
//				edges[prev[node]].residue -= fl;
//				edges[prev[node]^1].residue += fl;
//				resCost += fl * edges[prev[node]].cost;
//				node = edges[prev[node]].source;
//			}
//			resFlow += fl;
//		}
//
//		return make_pair(resCost, resFlow);
//	}
//}mcmf;
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};
const int MAXN=20000+5;
//const int INF=1<<28;
struct MCMF{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool inq[MAXN];
	int d[MAXN],p[MAXN],a[MAXN];
	void init(int n)
	{
		this->n=n;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addedge(int from,int to,int cap,int cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(int &flow,int& cost)
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
		cost+=d[t];
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	int mincost(int s,int t)
	{
		this->s=s;this->t=t;
		int flow=0,cost=0;
		while(spfa(flow,cost));
		return cost;
	}
}mcmf;

int in[105][105],out[105][105];
int arr[105][105];
int getVal(int row,int col)
{
    return row*m+col;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        int tot = n*m;
        repI(i,n){
            repI(j,m) {
                in[i][j] = getVal(i,j);
                out[i][j] = in[i][j]+tot;
            }
        }
//        mcmf.clear();
        mcmf.init(out[n-1][m-1]+1);
//        mcmf::init(out[n-1][m-1]+1,in[0][0],out[n-1][m-1]);

        repI(i,n)repI(j,m){
            getI(arr[i][j]);
            int cap = 1;
            if((i==0&&j==0) || (i==n-1&&j==m-1))cap  = 2;
            //            debug(i,j,in[i][j],out[i][j],cap,arr[i][j]);
//            mcmf::addEdge(in[i][j],out[i][j],cap,-arr[i][j]);
            mcmf.addedge(in[i][j],out[i][j],cap,-arr[i][j]);
//            if(i+1 < n )mcmf::addEdge(out[i][j],in[i+1][j],1,0);
            if(i+1 < n )mcmf.addedge(out[i][j],in[i+1][j],1,0);
//            if(j+1 < m )mcmf::addEdge(out[i][j],in[i][j+1],1,0);
            if(j+1 < m )mcmf.addedge(out[i][j],in[i][j+1],1,0);
        }
//        debug("");
//        pair <int, int> ans = mcmf::solve();
        int ans = mcmf.mincost(in[0][0],out[n-1][m-1]);
//        debug(ans.ff,ans.ss);
        printf("Case %d: %d\n",cs,-ans-arr[0][0]-arr[n-1][m-1]);

    }

    return 0;
}

