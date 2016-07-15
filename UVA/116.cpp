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
int arr[15][150],dp[15][150],mark[15][150];
int mod(int val)
{
    val%=n;
    if(val==0)val=n;
    return val;
}
int call(int row,int col)
{
    if(col==m+1)return 0;
    int &ret=dp[row][col];
    if(ret!=-1)return ret;
    int ans=INF;
    if(col==0)
    {
        int pos=0;
        rep(i,n)
        {
            int ans1=call(i,1);
            ans=min(ans,ans1);
        }
    }
    else
    {
        int ans1=call(mod(row+1),col+1)+arr[row][col];
        int ans2=call(mod(row-1),col+1)+arr[row][col];
        int ans3=call(mod(row),col+1)+arr[row][col];
        ans=min(ans1,ans2);
        ans=min(ans,ans3);
    }
    return ret=ans;
}
vector<int> res;
void print(int row,int col)
{
    if(col>m)return;
    res.push_back(row);
    int ans1=dp[mod(row-1)][col+1];
    int ans2=dp[mod(row)][col+1];
    int ans3=dp[mod(row+1)][col+1];
    vector<pii> tmp;
    tmp.push_back(pii(ans1,mod(row-1)));
    tmp.push_back(pii(ans2,mod(row)));
    tmp.push_back(pii(ans3,mod(row+1)));
    sort(ALL(tmp));
    print(tmp[0].ss,col+1);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
        WRITE("out.txt");
    #endif // mamun
    while(~getII(n,m))
    {
        res.clear();
        SET(dp);
        rep(i,n)rep(j,m)getI(arr[i][j]);
        int ans=call(0,0);
        int tmp=INF,pos;
        rep(i,n)
        {
            if(dp[i][1]<tmp)
            {
                tmp=dp[i][1];
                pos=i;
            }
        }
        print(pos,1);
//        sort(ALL(res));
        repI(i,res.size())
        {
            if(i)printf(" ");
            printf("%d",res[i]);
        }
        printf("\n%d\n",ans);


    }



    return 0;
}

