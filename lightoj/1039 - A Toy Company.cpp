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
string strt,fin;
int forbid[30][30][30];
int mark[30][30][30];
int dist[30][30][30];
int finx,finy,finz;
int mod(int num)
{
    if(num<0)num+=26;
    return num%26;
}

int bfs(int x,int y,int z)
{
    if(forbid[x][y][z])return -1;
    if(forbid[finx][finy][finz])return -1;
    mark[x][y][z]=1;
    dist[x][y][z]=0;
//    debug("")
    queue<int> q;
    q.push(x);q.push(y);q.push(z);
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        z=q.front();q.pop();
//        debug(x,y,z)
        if(x==finx&&y==finy&&z==finz)break;
        int xx=mod(x+1),yy=y,zz=z;
        if(!mark[xx][yy][zz]&&!forbid[xx][yy][zz])
        {
            q.push(xx);q.push(yy);q.push(zz);
            mark[xx][yy][zz]=1;
            dist[xx][yy][zz]=dist[x][y][z]+1;
        }
        xx=mod(x-1);
        if(!mark[xx][yy][zz]&&!forbid[xx][yy][zz])
        {
            q.push(xx);q.push(yy);q.push(zz);
            q.push(xx);q.push(yy);q.push(zz);
            mark[xx][yy][zz]=1;
            dist[xx][yy][zz]=dist[x][y][z]+1;
        }
        xx=x;yy=mod(y+1);
        if(!mark[xx][yy][zz]&&!forbid[xx][yy][zz])
        {
            q.push(xx);q.push(yy);q.push(zz);
            mark[xx][yy][zz]=1;
            dist[xx][yy][zz]=dist[x][y][z]+1;
        }
        yy=mod(y-1);
        if(!mark[xx][yy][zz]&&!forbid[xx][yy][zz])
        {
            q.push(xx);q.push(yy);q.push(zz);
            mark[xx][yy][zz]=1;
            dist[xx][yy][zz]=dist[x][y][z]+1;
        }
        yy=y;zz=mod(z+1);
        if(!mark[xx][yy][zz]&&!forbid[xx][yy][zz])
        {
            q.push(xx);q.push(yy);q.push(zz);
            mark[xx][yy][zz]=1;
            dist[xx][yy][zz]=dist[x][y][z]+1;
        }
        zz=mod(z-1);
        if(!mark[xx][yy][zz]&&!forbid[xx][yy][zz])
        {
            q.push(xx);q.push(yy);q.push(zz);
            mark[xx][yy][zz]=1;
            dist[xx][yy][zz]=dist[x][y][z]+1;
        }


    }


    return dist[finx][finy][finz];

}


int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        cin>>strt>>fin;
//        debug(strt,fin)
        CLR(forbid);
        CLR(mark);
        SET(dist);
        getI(n);
        string a,b,c;
        rep(i,n)
        {
            cin>>a>>b>>c;
//            debug(a,b,c)
            repI(j,a.size())repI(k,b.size())repI(l,c.size())
            {
                forbid[a[j]-'a'][b[k]-'a'][c[l]-'a']=1;
            }
        }
        finx=fin[0]-'a';
        finy=fin[1]-'a';
        finz=fin[2]-'a';
        int res=bfs(strt[0]-'a',strt[1]-'a',strt[2]-'a');
        printf("Case %d: %d\n",cs,res);
    }




    return 0;
}

