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
int mark[20][20];
int fin[20][20];
int dist[20][20];
int cnt[20][20];
int dirx[]= {1,1,2,2,-1,-1,-2,-2};
int diry[]= {2,-2,1,-1,2,-2,1,-1};

vector<pair<pii,int> > v;
void reset()
{
//    CLR(mark);
    CLR(fin);
//    SET(dist);
    CLR(cnt);
    v.clear();
}
queue<pii> q;
bool check(pii pos)
{
    if(pos.ff>0&&pos.ff<=n&&pos.ss>0&&pos.ss<=m)return true;
    return false;
}


void call(pii src,int cost,int baki)
{
//    if(baki==0)return;
    pii pos;
    repI(i,8)
    {
        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];
        if(check(pos)&&mark[pos.ff][pos.ss]==0)
        {
            mark[pos.ff][pos.ss]=1;
            dist[pos.ff][pos.ss]=cost+1;
//            fin[pos.ff][pos.ss]+=cost+1;
            cnt[pos.ff][pos.ss]++;
            q.push(pos);
//            call(pos,cost,baki-1);
        }

    }

}


void bfs(pii src,int dewajabe)
{
    q.push(src);

    dist[src.ff][src.ss]=0;
    cnt[src.ff][src.ss]+=1;
    mark[src.ff][src.ss]=1;

    while(!q.empty())
    {
        pii pos=q.front();
//        debug(pos.ff,pos.ss,dist[pos.ff][pos.ss],fin[pos.ff][pos.ss]);
        q.pop();
        call(pos,dist[pos.ff][pos.ss],dewajabe);
    }
}



int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        reset();
        string s;
        getII(n,m);
        int tot=0;
        rep(i,n)
        {
            cin>>s;
//            debug(s)
            repI(j,m)if(s[j]!='.')
            {
                tot++;
                CLR(mark);
                SET(dist);
//                v.push_back(make_pair(make_pair(i,j+1),s[j]-'0'));
                bfs(pii(i,j+1),s[j]-'0');
//                debug("")
                rep(k,n)rep(l,m)
                {
                    if(dist[k][l]!=-1)
                        fin[k][l]+=ceil((double)dist[k][l]/(s[j]-'0'));
                }
            }
        }
        int ans=INF;
        rep(i,n)
        {
            rep(j,m)
            {
                if(cnt[i][j]==tot)
                {
                    ans=min(ans,fin[i][j]);
                }
            }
        }
        printf("Case %d: ",cs);
        if(ans==INF)printf("-1\n");
        else printf("%d\n",ans);
    }




    return 0;
}


