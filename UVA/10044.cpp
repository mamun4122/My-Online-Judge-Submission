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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}

//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
//******************DELETE****************
int t,n,m;
string st;
map<string,int> mp;
vector<int> edge[10005];
vector<int> v;
vector<string> vs;
int dist[100005],mark[100005];


void reset(int x)
{
    rep(i,x)edge[i].clear();
    mp.clear();
    v.clear();
    vs.clear();

}
void bfs(int src)
{
    mark[src]=1;
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        repI(i,edge[u].size())
        {
            int v=edge[u][i];
            if(mark[v]==0)
            {
                q.push(v);
                mark[v]=1;
                dist[v]=dist[u]+1;
//                debug(dist[v])
            }
        }
    }
}


int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        printf("Scenario %d\n",cs);
        getII(n,m);
        getchar();
        int cnt=1;
        int strt=-1;
        rep(i,n)
        {
            getline(cin,st);
//            debug(st)
            string tmp="";
            repI(j,st.size())
            {
                if(st[j]==','&&st[j-1]=='.')
                {
                    if(!mp[tmp])mp[tmp]=cnt++;
                    if(tmp=="Erdos, P.")strt=mp[tmp];
//                    debug(tmp,mp[tmp])
                    v.push_back(mp[tmp]);
                    tmp="";
                    j++;
                }
                else if(st[j]==':')
                {
                    if(!mp[tmp])mp[tmp]=cnt++;
                    if(tmp=="Erdos, P.")strt=mp[tmp];
//                    debug(tmp)
//                    debug(tmp,mp[tmp])
                    v.push_back(mp[tmp]);
                    tmp="";
                    repI(j,v.size())
                    {
                        for(int k=j+1; k<v.size(); k++)
                        {
                            edge[v[j]].push_back(v[k]);
                            edge[v[k]].push_back(v[j]);
                        }
                    }
                    v.clear();
                    break;
                }
                else tmp+=st[j];

            }
        }
        if(strt==-1)strt=cnt++;
//        debug(strt)
        SET(dist);
        CLR(mark);
        bfs(strt);
        rep(i,m)
        {
            getline(cin,st);
            if(!mp[st])mp[st]=cnt++;
            printf("%s ",st.c_str());
            if(dist[mp[st]]==-1)puts("infinity");
            else printf("%d\n",dist[mp[st]]);
        }

        reset(cnt);
    }




    return 0;
}


