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
int par[200010];
int res[200010];
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
        /*int v=find_representative(par[r]);
        if(v!=r)
        {
            res[v]+=res[r];
            res[r]=0;
            par[r]=v;
        }
        else
        {
            par[r]=v;
        }
        return par[r];*/
    }
}
int Union(int a,int b)
{
    int u=find_representative(a);
    int v=find_representative(b);
    //if(u==v) puts("THEY ARE ALREADY FRIENDS");
    if(u!=v)
    {
        int ans=res[u]+res[v];
        par[u]=v; //or you can write par[v]=u too
        res[v]+=res[u];
        res[u]=0;
        return ans;
    }
    else
        return res[u];
}

int main()
{
   //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    map<string,int> mp;
    while(t--)
    {
        //debugI();
        int n;
        getI(n);
        for(int i=1; i<=n*2; i++)
        {
            makeset(i);
            res[i]=1;
        }
        int cnt=1;
        string a,b;
        while(n--)
        {
            cin>>a;
            cin>>b;
            //cout<<a<<" "<<b<<endl;
            if(mp[a]==0)mp[a]=cnt++;
            if(mp[b]==0)mp[b]=cnt++;
            int ans=Union(mp[a],mp[b]);
            printf("%d\n",ans);
        }
        mp.clear();
    }

    return 0;
}


