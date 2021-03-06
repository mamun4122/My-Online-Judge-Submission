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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
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
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

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
#define mx 1005
int par[mx];
void makeset(int n){
    for(int i=1;i<=n;i++)par[i]=i; //at first every element is parent of itself.
}
int find_representative(int r)
{
 if(par[r]==r) return r;  //if r is parent of itself than r is representative
 else
 {
  return par[r]=find_representative(par[r]); //else find representative of parent of r
 }
}
void Union(int a,int b)
{
 int u=find_representative(a);
 int v=find_representative(b);
 //if(u==v) puts("THEY ARE ALREADY FRIENDS");
 if(u!=v)
 {
  par[u]=v; //or you can write par[v]=u too

 }
}
int weight;
int dp[mx][mx];
int beauty[mx],wght[mx];
vector<int>adj[mx];
int mark[mx];
int cnt;
int call(int pos,int w)
{
    if(pos==cnt)return 0;
    int &ret=dp[pos][w];
    if(ret!=-1)return ret;
    ret=0;
    ret=max(ret,call(pos+1,w));
    int tot=0,totb=0;
    repI(i,adj[pos].size())
    {
        int val=adj[pos][i];
        tot+=wght[val];
        totb+=beauty[val];
        if(wght[val]<=w)ret=max(ret,call(pos+1,w-wght[val])+beauty[val]);
    }
//    debug(tot)
    if(tot<=w)
    {
        ret=max(ret,call(pos+1,w-tot)+totb);
    }
    return ret;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        CLR(mark);
        rep(i,n)adj[i].clear();
        makeset(n);

        getI(weight);
        rep(i,n)getI(wght[i]);
        rep(i,n)getI(beauty[i]);
        rep(i,m)
        {
            int a,b;
            getII(a,b);
            Union(a,b);
            ///ami 1ta bal
//            if(a>b)swap(a,b);
//            if(find_representative(a)!=find_representative(b))
//            {
//                for(int i=a;i<b;i++)Union(i,i+1);
//            }
        }
        rep(i,n)find_representative(i);
        cnt=1;
        rep(i,n)
        {
            int par=find_representative(i);
            if(mark[par]==0)
            {
                mark[par]=cnt;
                cnt++;
            }
            adj[mark[par]].PB(i);
        }
//        debug(cnt,weight)
//        rep(i,cnt-1)
//        {
//            repI(j,adj[i].size())printf("%d ",adj[i][j]);
//            puts("");
//        }
        SET(dp);
        int ans=call(1,weight);
        printf("%d\n",ans);

    }


    return 0;
}