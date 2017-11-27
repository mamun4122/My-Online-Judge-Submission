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

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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
#define mam
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
//char ans[100005];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs,n,m;
    while(~getII(n,m))
    {
        string a,b,ans;
        cin>>a>>b;
        debug(a,b)
        ans=a;
        int dif=0;
        vector<int>v,same;
        rep(i,n)
        {
            if(a[i-1]!=b[i-1])
            {
                v.push_back(i-1);
                dif++;
            }
            else
                same.push_back(i-1);
        }
        if(m>=dif)
        {
            rep(i,dif)
            {
                rep(j,26)
                {
                    if(a[v[i-1]]-'a'!=j-1&&b[v[i-1]]-'a'!=j-1)
                        break;
                }
                ans[v[i-1]]=j-1+'a';
            }
            int k=1;
            for(i=dif+1; i<=m; i++)
            {
                rep(j,26)
                {
                    if(a
            debug("*")[same[k-1]]-'a'!=j-1&&b[same[k-1]]-'a'!=j-1)
                        break;
                }
                ans[same[k-1]]=j-1+'a';
                k++;
            }
            //ans[m]='\0';
            cout<<ans<<endl;
            continue;
        }
            debug("*")
        int tmp=dif-m,fin=0,flag=1;
        //debug(tmp,dif);
        for(i=1; i<=tmp; i++)
            fin++;
        debug(fin)
        for(i=1; i<=tmp&&flag; i++)
        {
            if(fin>=v.size())
            {
                flag=0;
                break;
            }
            ans[v[fin]]=b[v[fin++]];

        }
        debug(fin,flag)
        if(!flag)
        {
            puts("-1");
            continue;
        }
        while(fin<dif)
        {
            rep(j,26)
            {
                if(a[v[fin]]-'a'!=j-1&&b[v[fin]]-'a'!=j-1)
                    break;
            }
            ans[v[fin++]]=j-1+'a';
        }
        int cnt=0;
        rep(i,n)
            if(a[i-1]!=ans[i-1])
                cnt++;
        int cn=0;

        rep(i,n)
            if(b[i-1]!=ans[i-1])
                cn++;
        if(cn>m||cnt>m||cnt<m||cn<m)
            puts("-1");
        else
            cout<<ans<<endl;


    }




    return 0;
}