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
#include <ctime>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define repI(i,n) for( i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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

#define iseq(a,b) (fabs(a-b)<EPS)

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************
vector<string> v;
map<string,int> mp;
vector<int> edge[210];
int mark[210],dist[210];

bool cmp(string x,string y)
{
    if(x.size()!=y.size())return false;
    int flag=0;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=y[i])flag++;
        if(flag>1)return false;
    }
    return true;
}

void bfs(int src,int dest)
{
    mark[src]=1;
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(u==dest)return;
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(!mark[v])
            {
                mark[v]=1;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs,n,m;
    getI(t);
    getchar();
        string x;
        getline(cin,x);
    repI(cs,t)
    {
        v.clear();
        mp.clear();
       // debug(cs)
        if(cs)puts("");
        int cnt=0;
        while(getline(cin,x))
        {
            //debug(x)
            if(x[0]=='*')break;
            v.push_back(x);
            //debug(x,cnt)
            mp[x]=cnt++;
        }
        repI(i,cnt)edge[i].clear();

        string y,z;
        repI(i,cnt)
        {
            y=v[i];
            for(j=i+1;j<cnt;j++)
            {
                z=v[j];
                if(cmp(y,z))
                {
                    edge[mp[y]].push_back(mp[z]);
                    edge[mp[z]].push_back(mp[y]);
                }
            }
        }
//        string y,z;
        while(getline(cin,x))
        {
            if(x.empty())break;
            stringstream ss;
            ss<<x;
            ss>>y>>z;
            //debug(mp[y],mp[z])
            CLR(mark);
            CLR(dist);
            bfs(mp[y],mp[z]);
            cout<<y<<" "<<z<<" "<<dist[mp[z]]<<endl;
        }
    }




    return 0;
}


