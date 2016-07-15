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
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

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
int par[5010];
int res[5010];
int result;
void makeset(int n)
{
    par[n]=n; //at first every element is parent of itself.
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
        int ans=res[u]+res[v];
        par[v]=u; //or you can write par[v]=u too
        res[u]+=res[v];
        res[v]=0;
        result=max(result,ans);
    }
    else
        result=max(result,res[u]);
}

int main()
{
  // READ("in.txt");
    //WRITE("out.txt");
    int c,r;
    map<string,int> m;
    while(scanf("%d%d",&c,&r)&&(c||r))
    {
        result=1;
        string a,b;
        int cnt=1;
        for(int i=1;i<=c;i++)
        {
            cin>>a;
            //debug(a);
            if(m[a]==0)m[a]=cnt++;
            makeset(i);
            res[i]=1;
        }
        for(int i=1;i<=r;i++)
        {
            cin>>a>>b;
            Union(m[b],m[a]);
        }
        printf("%d\n",result);
        m.clear();
    }

    return 0;
}



