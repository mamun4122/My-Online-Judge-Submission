#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

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
int t,n,m;
map<string,int> mp;
#define mx 100010
int par[mx*2];
void makeset(int n){
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
  par[u]=v; //or you can write par[v]=u too

 }
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n)
    {
    rep(i,n+n)makeset(i);
        cin>>m;
        int k;
        cin>>k;
        rep(i,n)
        {
            string s;
            cin>>s;
            mp[s]=i;
        }
        rep(i,m)
        {
            int type;
            cin>>type;
            string bb,cc;
            cin>>bb>>cc;
            int x,y,j,k;
            int b=mp[bb],c=mp[cc];
            x=find_representative(b);
            y=find_representative(c);
            j=find_representative(b+n);
            k=find_representative(c+n);
            switch(type)
            {

            case 1:
                if(x==k||y==j)puts("NO");
                else
                {
                    Union(x,y);
                    Union(j,k);
                    puts("YES");
                }
                break;
            case 2:
                if(x==y||j==k)puts("NO");
                else
                {
                    par[j]=y;
                    par[k]=x;
                    puts("YES");
                }
                break;
            }

        }
        rep(i,k)
        {
            string bb,cc;
            cin>>bb>>cc;
            int x,y,j,k;
            int b=mp[bb],c=mp[cc];
            x=find_representative(b);
            y=find_representative(c);
            j=find_representative(b+n);
            k=find_representative(c+n);
            if(x==y||j==k)puts("1");
            else if(x==k||y==j)
                puts("2");
            else puts("3");
        }

        return 0;
    }
}