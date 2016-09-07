#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

#define mx 510

vector<int> g[mx],cost[mx];
struct node
{
    int u,w;
    node(int a,int b){u=a;w=b;}
    bool operator< (const node &p)const {return w > p.w;}
};
int d[mx];
void dijktra(int n)
{
    for(int i=0;i<mx;i++)d[i]=INF;
    priority_queue<node> q;
    q.push(node(n,0));
    d[n]=0;
    while(!q.empty())
    {
        node top=q.top();q.pop();
        int u=top.u;
        //debugI();
        //debug(u);
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(max(cost[u][i],d[u])<d[v])
            {
                d[v]=max(cost[u][i],d[u]);
                //cout<<v<<" "<<d[v]<<endl;
                q.push(node(v,d[v]));
            }
        }
    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    for(int cs=1;cs<=t;cs++)
    {

        for(int i=0;i<mx;i++)
        {
            g[i].clear();
            cost[i].clear();
        }
//        q.clear();
        int n,m;
        getII(n,m);
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
            getIII(u,v,w);
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int x;
        getI(x);
        dijktra(x);
        printf("Case %d:\n",cs);
        for(int i=0;i<n;i++)
        {
            //if(i==x)continue;
            if(d[i]!=INF)
                printf("%d\n",d[i]);
            else
                printf("Impossible\n");
        }
    }


    return 0;
}


