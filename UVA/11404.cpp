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
pair<int,char> dp[1005][1005];
int vis[1005][1005];
string s;
pair<int,char> call(int lft,int rght)
{
    char tmp='z'+1;
//    debug(tmp)
    if(lft>rght)return make_pair(0,tmp);
    if(vis[lft][rght])return dp[lft][rght];
    vis[lft][rght]=1;
    pair<int,char> ans;
    if(s[lft]==s[rght])
    {
        ans.ff=call(lft+1,rght-1).ff+(lft==rght?1:2);
        ans.ss=s[lft];

    }
    else
    {
        if(call(lft+1,rght).ff>call(lft,rght-1).ff)ans=call(lft+1,rght);
        else if(call(lft+1,rght).ff<call(lft,rght-1).ff)ans=call(lft,rght-1);
        else
        {
            ans.ff=call(lft+1,rght).ff;
            ans.ss=min (call(lft+1,rght).ss,call(lft,rght-1).ss);
        }

    }
    //ans=max(call(lft+1,rght),call(lft,rght-1));
    return dp[lft][rght]=ans;
}
string ans;
int flag;
//void print(int lft,int rght,string frst,string scnd)
//{
//    if(lft>rght)
//    {
//        if(flag)ans=min(ans,frst+scnd);
//        else ans=frst+scnd;
//        flag=1;
//        return;
//    }
//    if(s[lft]==s[rght])
//    {
//        frst+=s[lft];
//        if(lft!=rght)scnd=s[lft]+scnd;
//        print(lft+1,rght-1,frst,scnd);
//    }
//    else if(dp[lft+1][rght]>dp[lft][rght-1])print(lft+1,rght,frst,scnd);
//    else if(dp[lft+1][rght]<dp[lft][rght-1])print(lft,rght-1,frst,scnd);
//    else
//    {
//        print(lft+1,rght,frst,scnd);
//        print(lft,rght-1,frst,scnd);
//    }
//}
void print(int lft,int rght)
{
//    debug(lft,rght)
    if(lft>rght)return;
    if(s[lft]==s[rght])
    {
        printf("%c",s[lft]);
        print(lft+1,rght-1);
        if(lft!=rght)printf("%c",s[lft]);
    }
    else if(dp[lft+1][rght].ff>dp[lft][rght-1].ff)print(lft+1,rght);
    else if(dp[lft+1][rght].ff<dp[lft][rght-1].ff)print(lft,rght-1);
    else if(dp[lft+1][rght].ss<dp[lft][rght-1].ss)print(lft+1,rght);
    else if(dp[lft+1][rght].ss>dp[lft][rght-1].ss)print(lft,rght-1);
    else
    {
        if(s[lft]==dp[lft+1][rght].ss)print(lft,rght-1);
        else if(s[rght]==dp[lft+1][rght].ss)print(lft+1,rght);
        else print(lft+1,rght);
    }
//    else
//    {
//        print(lft+1,rght);
//    }
}

int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    while(cin>>s)
    {
        CLR(vis);
        flag=0;
//        debug(call(0,s.size()-1))
        pair<int,char> res=call(0,s.size()-1);
//        debug(res.ff)
        print(0,s.size()-1);
        cout<<ans<<endl;
    }




    return 0;
}


