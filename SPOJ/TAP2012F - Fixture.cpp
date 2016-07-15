#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
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
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
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
map<pair<pii,int>,int > mp;
map<int,pii > inv;
vector<int> adj[10005];
int deg[10005];
pair<pii,int> call(int i,int j,int k)
{
    return MP(MP(i,j),k);
}
void dfs(int src)
{
    int frst=inv[src].ff;
    int scnd=inv[src].ss;
//    debug(frst,scnd)
    if(frst==1)printf("%d",scnd);
    else if(scnd==1)printf("%d",frst);
    if(adj[src].size()==0)return;
    dfs(adj[src][0]);
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    while(~getI(n)&&n!=-1)
    {
        ///clear part
        rep(i,10000)adj[i].clear();
        CLR(deg);
        inv.clear();
        mp.clear();

        string st;
        int tot=0;
        int ager;
        rep(i,n)
        {
            if(i==1)continue;
            cin>>st;
            map<pii,int >tmp;
            int sz=st.size();
//            pair<pii,int > ager;
            repI(k,sz)
            {
                int j=st[k]-'0';

                pii pos=MP(i,j);
                pii anthr=MP(j,i);
                tmp[pos]++;
                tmp[anthr]++;

                if(mp[(call(i,j,tmp[pos]))]==0)
                {
                    mp[call(i,j,tmp[pos])]=++tot;
                    mp[call(j,i,tmp[anthr])]=tot;
                }

                inv[mp[call(i,j,tmp[pos])]]=MP(i,j);

                if(k==0)ager=mp[call(i,j,tmp[pos])];
                else
                {
                    adj[ager].push_back(mp[call(i,j,tmp[pos])]);
                    ager=mp[call(i,j,tmp[pos])];
                    deg[ager]++;
                }
            }
        }
//        int strt;
//        rep(i,tot)if(deg[i]==0)
//        {
//            strt=i;
////            debug(strt);
//            dfs(strt);
//        }
//        puts("");
        queue<int> q;
        rep(i,tot)
        {
            if(deg[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int src=q.front();
            q.pop();
            int frst=inv[src].ff;
            int scnd=inv[src].ss;
            if(frst==1)printf("%d",scnd);
            else if(scnd==1)printf("%d",frst);
            repI(i,adj[src].size())
            {
                int v=adj[src][i];
                deg[v]--;
                if(deg[v]==0)q.push(v);
            }
        }
        puts("");
    }



    return 0;
}

