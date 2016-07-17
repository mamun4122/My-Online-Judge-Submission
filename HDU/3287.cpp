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
map<string,int> mp;
map<string,string> res;
vector<int> adj[10];
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun

    ///a
    adj[0].PB(1);
    adj[0].PB(5);
    ///b
    adj[1].PB(0);
    adj[1].PB(2);
    adj[1].PB(6);
    ///c
    adj[2].PB(1);
    adj[2].PB(3);
    ///d
    adj[3].PB(2);
    adj[3].PB(4);
    ///e
    adj[4].PB(3);
    adj[4].PB(5);
    adj[4].PB(6);
    ///f
    adj[5].PB(0);
    adj[5].PB(4);
    ///blank
    adj[6].PB(1);
    adj[6].PB(4);

    string st="ABCDEF*";
    mp[st]=1;
    queue<string> q,org;
    q.push(st);
    org.push("");
    while(!q.empty())
    {
        string u=q.front();q.pop();
        string ans=org.front();org.pop();
        res[u]=ans;

        int pos;
        repI(i,u.size())if(u[i]=='*')
        {
            pos=i;
            break;
        }

        repI(i,adj[pos].size())
        {
            int v=adj[pos][i];
            string tmp=u;
            swap(tmp[pos],tmp[v]);

            if(mp[tmp]==0)
            {
                org.push(ans+u[v]);
                mp[tmp]=mp[u]+1;
                q.push(tmp);
            }

        }
    }
    getI(t);
    rep(cs,t)
    {
        getI(cs);
        cin>>st;
        st+="*";
        printf("%d ",cs);
        if(mp[st]==0)
        {
            puts("NO SOLUTION");
        }
        else
        {
            printf("%d ",mp[st]-1);
            if(mp[st]>1)
            {
                string ress=res[st];
                reverse(ALL(ress));
                printf("%s",ress.c_str());
            }
            puts("");
        }
    }

    return 0;
}

