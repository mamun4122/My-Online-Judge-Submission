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
int arr[50][50];
int cum[50][50];
int histogram(int row,int col)
{
    stack<pii> st;
    st.push(pii(-INF,0));
    int lft[50],rght[50];
    rep(i,col)
    {
        while(st.top().ff>=cum[row][i])st.pop();
        lft[i]=st.top().ss;
        st.push(pii(cum[row][i],i));
    }
    while(!st.empty())st.pop();
    st.push(pii(-INF,col+1));
    ROF(i,col,1)
    {

        while(st.top().ff>=cum[row][i])st.pop();
        rght[i]=st.top().ss;
        st.push(pii(cum[row][i],i));
    }
    int res=-INF;
    rep(i,col)
    {
        res=max(res,cum[row][i]*(rght[i]-lft[i]-1));
    }
//    if(row==8)
//    {
//        rep(i,col)debug(i,lft[i],rght[i])
//    }
    return res;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
        WRITE("out.txt");
    #endif // mamun
    getI(t);
    getchar();
    getchar();
    rep(cs,t)
    {
        if(cs>1)puts("");
        CLR(cum);
        CLR(arr);
        string s;
        int row=1;
        int col=-INF;
        while(getline(cin,s))
        {
//            debug(s);
            if(s.empty())break;
            col=max(col,(int)s.size());
            repI(i,s.size())
            {
                arr[row][i+1]=s[i]-48;
            }
            row++;
        }
        row--;
//        rep(i,row)
//        {
//            rep(j,col)printf("%d ",arr[i][j]);
//            puts("");
//        }
//        puts("");
        int ans=0;
        rep(i,row)
        {
            rep(j,col)
            {
                if(i==1)cum[i][j]=arr[i][j];
                else
                {
                    if(arr[i][j]&&arr[i-1][j])cum[i][j]=cum[i-1][j]+1;
                    else cum[i][j]=arr[i][j];
                }
            }
            ans=max(ans,histogram(i,col));
        }
//        rep(i,row)
//        {
//            rep(j,col)printf("%d ",cum[i][j]);
//            puts("");
//        }
        printf("%d\n",ans);
    }


    return 0;
}

