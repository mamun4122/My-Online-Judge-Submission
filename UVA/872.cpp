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
#define    bitOn(a,k)         (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
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
int deg[30];
vector<int> adj[30];
int mp[30];
char inv[30];
int cnt;
bool newahoise[30];
vector<int> tmp;
vector<vector<int> >ans;
void tropo(int count)
{
//    debug(count,cnt)
    if(count==cnt)
    {
        ans.push_back(tmp);
        return;
    }
    repI(i,cnt)
    {
        if(deg[i]==0&&!newahoise[i])
        {
//            debug(inv[i])
            tmp.push_back(i);
            newahoise[i]=1;
            repI(j,adj[i].size())deg[adj[i][j]]--;
            tropo(count+1);
            repI(j,adj[i].size())deg[adj[i][j]]++;
            newahoise[i]=0;
            tmp.pop_back();

        }
    }
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun

    ///RIP String Input -_-

     getI(t);
    getchar();
     rep(cs,t)
     {
         if(cs>1)puts("");
         ans.clear();tmp.clear();
         CLR(newahoise);
         CLR(deg);

         getchar();

         string s;
         getline(cin,s);
         debug(s)
         cnt=0;
         vector<char> v;
         repI(i,s.size())
         {
             v.push_back(s[i]);
            i++;
         }
         sort(ALL(v));
         repI(i,v.size())
         {
            mp[v[i]-'A']=cnt;
            inv[cnt++]=v[i];

         }
         repI(i,cnt)adj[i].clear();
         getline(cin,s);
         debug(s);
         repI(i,s.size())
         {
//             debug(s[i])
             adj[mp[s[i]-'A']].push_back(mp[s[i+2]-'A']);
             deg[mp[s[i+2]-'A']]++;
             i+=3;
         }
         tropo(0);
         if(ans.size()==0)puts("NO");
         else
         {
             repI(i,ans.size())
             {
                 repI(j,cnt)
                 {
                     if(j)printf(" ");
                     printf("%c",inv[ans[i][j]]);
                 }
                 puts("");
             }

         }



     }



    return 0;
}

