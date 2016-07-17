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
#define mamu
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
int adj[105][105];//[105];
string s;
int dist[105][105][105],dest[105][105][105];
bool color[105][105][105];
bool mark[15][15];

int dirx[]= {0,0,1,-1};
int diry[]= {1,-1,0,0};

typedef pair<pii,int> piii;
piii make(int x,int y,int z)
{
    return make_pair(make_pair(x,y),z);
}
bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)return false;
    if(adj[x][y]==0)return false;
    if(mark[x][y])return false;
    return true;
}
int arr[3];
int bfs(int frst,int scnd,int thrd)
{
    vector<int>v;
    queue<piii> q;
    set<int>st;
    color[frst][scnd][thrd]=1;
    dist[frst][scnd][thrd]=0;
    q.push(make(frst,scnd,thrd));
    pii f,s,t;
    while(!q.empty())
    {
        piii tmp=q.front();
        q.pop();
//        debug(tmp.ff.ff/n,tmp.ff.ff%n,tmp.ff.ss/n,tmp.ff.ss%n,tmp.ss/n,tmp.ss%n,dist[tmp.ff.ff][tmp.ff.ss][tmp.ss])

//        debug("**")
        if(dest[tmp.ff.ff][tmp.ff.ss][tmp.ss])return dist[tmp.ff.ff][tmp.ff.ss][tmp.ss];
        repI(i,4)
        {
            if(i==1||i==3)
            {
                f=make_pair(tmp.ff.ff/n,tmp.ff.ff%n);
                s=make_pair(tmp.ff.ss/n,tmp.ff.ss%n);
                t=make_pair(tmp.ss/n,tmp.ss%n);
            }
            else if(i==0||i==2)
            {
                t=make_pair(tmp.ff.ff/n,tmp.ff.ff%n);
                s=make_pair(tmp.ff.ss/n,tmp.ff.ss%n);
                f=make_pair(tmp.ss/n,tmp.ss%n);
            }
//            debug(i)
//        debug(f.ff,f.ss,s.ff,s.ss,t.ff,t.ss,dist[tmp.ff.ff][tmp.ff.ss][tmp.ss])

            v.clear();
//            st.clear();
            CLR(mark);
            int cnt=0;

            int x,y;
            int flag=0;
            x=f.ff+dirx[i];
            y=f.ss+diry[i];
            if(check(x,y))
            {
                mark[x][y]=1;
                flag=1;
                v.push_back(x*n+y);
                cnt++;
//                st.insert(x*n+y);
            }
            else
            {
                cnt++;
                mark[f.ff][f.ss]=1;
                v.push_back(f.ff*n+f.ss);
//                st.insert(f.ff*n+f.ss);
            }
            x=s.ff+dirx[i];
            y=s.ss+diry[i];
            if(check(x,y))
            {
//                if(mark[x][y]==0)
//                {
                    cnt++;
                    mark[x][y]=1;
                    flag=1;
                    v.push_back(x*n+y);
//                    st.insert(x*n+y);
//                }

            }
            else
            {
//                if(mark[s.ff][s.ss]==0)
//                {
                    cnt++;
                    mark[s.ff][s.ss]=1;
                    v.push_back(s.ff*n+s.ss);
//                    st.insert(s.ff*n+s.ss);
//                }
            }
            x=t.ff+dirx[i];
            y=t.ss+diry[i];
            if(check(x,y))
            {
//                if(mark[x][y]==0)
//                {
                    cnt++;
                    mark[x][y]=1;
                    flag=1;
                    v.push_back(x*n+y);
//                st.insert(x*n+y);
//                }
            }
            else
            {
//                if(mark[t.ff][t.ss]==0)
//                {
                    cnt++;
                    mark[t.ff][t.ss]=1;
                    v.push_back(t.ff*n+t.ss);
//                    st.insert(t.ff*n+t.ss);
//                }
            }
            if(flag&&cnt==3)
            {
//                debug("m",v[0]/n,v[0]%n,v[1]/n,v[1]%n,v[2]/n,v[2]%n)
                sort(ALL(v));
                if(color[v[0]][v[1]][v[2]]==0)
                {
//                    debug("ccc")
                    color[v[0]][v[1]][v[2]]=1;
                    dist[v[0]][v[1]][v[2]]=1+dist[tmp.ff.ff][tmp.ff.ss][tmp.ss];
                    q.push(make(v[0],v[1],v[2]));
                }
            }
        }
    }
    return -1;
}


int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        CLR(adj);
        CLR(dist);
        CLR(dest);
        CLR(color);

        getI(n);
        vector<int>v,dst;
        repI(i,n)
        {
            cin>>s;
//            debug(s)
            repI(j,n)
            {
                if(s[j]=='.')adj[i][j]=1;
                else if(s[j]!='#'&&s[j]!='X')
                {
                    adj[i][j]=1;
                    v.push_back(i*n+j);
                }
                else if(s[j]!='#'&&s[j]=='X')
                {
                    adj[i][j]=1;
                    dst.push_back(i*n+j);
                }
            }
        }
        sort(ALL(v));
        sort(ALL(dst));
        sort(ALL(v));
        dest[dst[0]][dst[1]][dst[2]]=1;
        debug("m",dst[0],dst[1],dst[2]);
        int ans=bfs(v[0],v[1],v[2]);
        printf("Case %d: ",cs);
        if(ans==-1)printf("trapped\n");
        else printf("%d\n",ans);
    }
    return 0;
}

