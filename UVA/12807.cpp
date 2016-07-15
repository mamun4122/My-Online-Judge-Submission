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
int t,row,col;
int dirx[]= {1,0,-1,0};
int diry[]= {0,1,0,-1};
int adj[1005][1005];
pii par[1005][1005];
int mark[1005][1005];
char arr[1005];
pii src,dest;
bool check(pii pos)
{
    if(pos.ff>=0&&pos.ff<col&&pos.ss>=0&&pos.ss<row)return true;
    return false;
}


bool bfs(pii src)
{
//    SET(par);
    par[src.ff][src.ss]=MP(-1,-1);
    CLR(mark);
    mark[src.ff][src.ss]=1;
    queue<pii> q;
    q.push(src);
    while(!q.empty())
    {
//        debug("")
        pii u = q.front();q.pop();
        if(u==dest)return true;
        pii pos;
        repI(i,4)
        {
            pos.ff=u.ff+dirx[i];
            pos.ss=u.ss+diry[i];
//            debug(pos.ff,pos.ss,adj[pos.ff][pos.ss],mark[pos.ff][pos.ss])
            if(check(pos)&&mark[pos.ff][pos.ss]==0&&adj[pos.ff][pos.ss])
            {
//                debug(pos.ff,pos.ss)
                mark[pos.ff][pos.ss]=1;
                par[pos.ff][pos.ss]=u;
                q.push(pos);
            }
        }

    }
    return false;
}
vector<pii> res;
vector<int> dir;
string call(int cur,int next)
{
    if(cur==-1)
    {
        switch(next)
        {
        case 0:
            return "Turn to the east.";
            break;
        case 1:
            return "Turn to the south.";
            break;
        case 2:
            return "Turn to the west.";
            break;
        case 3:
            return "Turn to the north.";
            break;
        }
    }
    else if(cur==0)
    {
        if(next==1)return "Turn right.";
        else return "Turn left.";
    }
    else if(cur==1)
    {
        if(next==2)return "Turn right.";
        else return "Turn left.";
    }
    else if(cur==2)
    {
        if(next==3)return "Turn right.";
        else return "Turn left.";
    }
    else if(cur==3)
    {
        if(next==0)return "Turn right.";
        else return "Turn left.";
    }
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        CLR(arr);
        getII(col,row);
        getchar();
        gets(arr);
        rep(i,row)
        {
            gets(arr);
            rep(j,col)
            {
                if(arr[j]=='*')adj[j-1][i-1]=1;
                else adj[j-1][i-1]=0;
            }
//            debug(arr);
        }
        gets(arr);
        getII(src.ff,src.ss);
        getII(dest.ff,dest.ss);
//        debug(adj[src.ff][src.ss])
//        debug(adj[src.ff][src.ss])
//        repI(i,row)
//        {
//            repI(j,col)printf("%d ",adj[i][j]);
//            puts("");
//        }
//        debug(dest.ff,dest.ss);
        bool ans=bfs(src);
        if(ans==false)puts("No route found.");
        else
        {
            res.clear();
            dir.clear();
            pii cur=dest;
            while(par[cur.ff][cur.ss].ff!=-1)
            {
                res.push_back(cur);
                cur=par[cur.ff][cur.ss];
            }
            res.push_back(src);
            reverse(ALL(res));
            dir.clear();
//            repI(i,res.size())debug(res[i].ff,res[i].ss);
            pii pos=src;
            repI(i,res.size()-1)
            {
                pos=res[i];
//                debug(pos.ff,pos.ss)
                repI(j,4)
                {
                    pii tmp;
                    tmp.ff=pos.ff+dirx[j];
                    tmp.ss=pos.ss+diry[j];
                    if(tmp==res[i+1])
                    {
                        dir.push_back(j);
                        break;
                    }
                }
            }
//            repI(i,dir.size())debug(dir[i])
            int now=-1;
            repI(i,dir.size())
            {
                printf("%s\n",call(now,dir[i]).c_str());
                now=dir[i];
                int cnt=0;
                while(i<dir.size()&&dir[i]==now)
                {
                    i++;
                    cnt++;
                }
                i--;
                printf("Continue %d km.\n",cnt);
            }
            puts("You have reached your destination.");

        }
        puts("");

    }



    return 0;
}

