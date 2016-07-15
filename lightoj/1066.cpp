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
template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
int t,n,m;
string s[15];
pii strt;
int mark[15][15];
int dist[15][15];
bool check(pii pos,char x)
{
//    debug(pos.ff,pos.ss)
    if(pos.ff<0||pos.ff>=n||pos.ss<0||pos.ss>=n)return false;
    if(s[pos.ff][pos.ss]=='#')return false;
    if(s[pos.ff][pos.ss]=='.')return true;
    if(s[pos.ff][pos.ss]<=x)return true;
    if(s[pos.ff][pos.ss]==x+1)return true;
    return false;
}
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int bfs(pii src,char dest,char c)
{
//    debug(c,dest)
    mark[src.ff][src.ss]=1;
    dist[src.ff][src.ss]=0;
    queue<pii> q;
    q.push(src);
    while(!q.empty())
    {
        pii tmp=q.front();q.pop();
//        debug(tmp.ff,tmp.ss,dist[tmp.ff][tmp.ss],s[tmp.ff][tmp.ss])
        if(s[tmp.ff][tmp.ss]==dest)
        {
//            debug("mam")
            strt=tmp;
            return dist[tmp.ff][tmp.ss];
        }
        repI(i,4)
        {
            pii pos;
            pos.ff=tmp.ff+dirx[i];
            pos.ss=tmp.ss+diry[i];
            if(check(pos,c)&&mark[pos.ff][pos.ss]==0)
            {
                mark[pos.ff][pos.ss]=1;
                dist[pos.ff][pos.ss]=dist[tmp.ff][tmp.ss]+1;
//                debug("")
                q.push(pos);
//                debug(pos.ff,pos.ss,dist[pos.ff][pos.ss])
            }
        }


    }
    return -1;
}

int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        getI(n);
        repI(i,n)
        {
            cin>>s[i];
//            debug(s[i])
        }
        printf("Case %d: ",cs);
        int flag=0,ans=0;
        char mx='A';
        repI(i,n)repI(j,n)
        {
//            debug(s[i][j])
            if(s[i][j]=='A')
            {
                flag=1;
                strt.ff=i;
                strt.ss=j;
                mx=max(mx,'A');
            }
            else if(s[i][j]!='.'&&s[i][j]!='#')
                mx=max(mx,s[i][j]);
        }
        char st='A';
//        debug(st,mx)
        if(!flag)puts("0");
        else
        {
            while(st<mx)
            {
                CLR(mark);SET(dist);
                int tmp=bfs(strt,st+1,st);
//                debug(tmp)
                st++;
                if(tmp==-1)
                {
                    ans=-1;
                    break;
                }
                else ans+=tmp;
            }
            if(ans==-1)puts("Impossible");
            else printf("%d\n",ans);
        }
    }





    return 0;
}


