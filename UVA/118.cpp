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
int strtx,strty;
char dir;
int mark[102][102];
int dirx,diry;
char movepos(char cur,char nxt)
{
    if(cur=='N')
    {
        if(nxt=='R')return 'E';
        else return 'W';
    }
    if(cur=='S')
    {
        if(nxt=='R')return 'W';
        else return 'E';
    }
    if(cur=='E')
    {
        if(nxt=='R')return 'S';
        else return 'N';
    }
    if(cur=='W')
    {
        if(nxt=='R')return 'N';
        else return 'S';
    }
}
bool check(pii pos)
{
    if(pos.ff<0||pos.ff>n||pos.ss<0||pos.ss>m)return false;
    return true;
}
int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getII(n,m);
    queue<pii> q;
    CLR(mark);
    string s;
    char dir,tm;
    while(~scanf("%d %d %c",&strtx,&strty,&dir))
    {
        while(!q.empty())q.pop();
        int flag=0;

        q.push(make_pair(strtx,strty));

        cin>>s;
//        debug(s)

        repI(i,s.size())
        {
            pii pos,tmp;
            tm=dir;
            if(s[i]!='F')dir=movepos(dir,s[i]);
            else
            {
                pos=q.front();
                q.pop();
                tmp=pos;
                switch(dir)
                {
                case 'N':
                    pos.ss++;
                    break;
                case 'E':
                    pos.ff++;
                    break;
                case 'W':
                    pos.ff--;
                    break;
                case 'S':
                    pos.ss--;
                    break;
                }
                if(check(pos))q.push(pos);
                else if(mark[tmp.ff][tmp.ss])
                {
                    dir=tm;
                    q.push(tmp);
                }
                else
                {
                    mark[tmp.ff][tmp.ss]=1;
                    flag=1;
                    q.push(tmp);
                    break;

                }
            }
            if(flag)break;
//            debug(q.front().ff,q.front().ss,dir)
        }
        printf("%d %d %c",q.front().ff,q.front().ss,dir);
        if(flag)printf(" LOST");
        puts("");

    }





return 0;
}


