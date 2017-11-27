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


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double



const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

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
int arr[1005][1005];
int mark[1005][1005];
int visit[1005][1005];
int pre[1005][1005];

char s[1005][1005];
int cnt=0,tot;
int dirx[]={1,-1,0,0};
int diry[]={0,0,1,-1};
bool check(int srcx,int srcy)
{
    if(srcx>0&&srcx<=n&&srcy>0&&srcy<=m&&mark[srcx][srcy]==0)return true;
    return false;
}
bool check1(int srcx,int srcy)
{
    if(srcx>0&&srcx<=n&&srcy>0&&srcy<=m&&visit[srcx][srcy]==0)return true;
    return false;
}
bool check2(int srcx,int srcy)
{
    if(srcx>0&&srcx<=n&&srcy>0&&srcy<=m)return true;
    return false;
}
void dfs(int srcx,int srcy)
{
    cnt++;
    mark[srcx][srcy]=tot;
    repI(i,4)
    {
        int posx=srcx+dirx[i];
        int posy=srcy+diry[i];
        if(check(posx,posy)&&arr[posx][posy])
            dfs(posx,posy);
    }
}
void dfs1(int srcx,int srcy)
{
    visit[srcx][srcy]=1;
    pre[srcx][srcy]=cnt;
    repI(i,4)
    {
        int posx=srcx+dirx[i];
        int posy=srcy+diry[i];
        if(check1(posx,posy)&&arr[posx][posy])
            dfs1(posx,posy);
    }
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");
    while(~getII(n,m))
    {
        getchar();
        CLR(arr);
        CLR(mark);
        CLR(visit);
        CLR(pre);

        rep(i,n)
        {
            gets(s[i]);
            repI(j,m)
            {
                if(s[i][j]!='*')arr[i][j+1]=1;
            }
        }
        tot=1;
        rep(i,n)
        {
            rep(j,m)
            {
                if(arr[i][j]&&!mark[i][j])
                {
                    cnt=0;
                    dfs(i,j);
                    tot++;
                    cnt%=10;
                    dfs1(i,j);
                }

            }
        }
        int posx[5],posy[5];
        rep(i,n)
        {
            rep(j,m)
            {
                if(!arr[i][j])
                {
                    int ans=1;
                    repI(k,4)
                    {
                        posx[k]=i+dirx[k];
                        posy[k]=j+diry[k];
                        if(check2(posx[k],posy[k])&&arr[posx[k]][posy[k]])
                        {
                            ans+=pre[posx[k]][posy[k]];
                        }
                        for(int l=k-1;l>=0;l--)
                        {
                            if(mark[posx[k]][posy[k]]==mark[posx[l]][posy[l]])
                            {
                                ans-=pre[posx[k]][posy[k]];
                                break;
                            }
                        }
                    }
                    ans%=10;
                    s[i][j-1]=ans+48;
                }
            }
        }
        rep(i,n)puts(s[i]);



    }




    return 0;
}