#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
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
string a,b;
string findans(string s)
{
    int lowa=0,lowb=0;
    string ans="";
    int frst=0,scnd=0,thrd=0;
    repI(i,s.size())
    {
        if(lowa<a.size()&&lowb<b.size()&&s[i]==a[lowa]&&s[i]==b[lowb])
        {
            if(scnd)
            {
                scnd=0;
                ans+="}";
            }
            if(thrd)
            {
                thrd=0;
                ans+="]";
            }
            if(frst)ans+=s[i];
            else
            {
                frst=1;
                ans+="(";
                ans+=s[i];
            }
            lowa++;
            lowb++;
        }
        else if(lowa<a.size()&&s[i]==a[lowa])
        {
            lowa++;
            if(frst)
            {
                ans+=")";
                frst=0;
            }
            if(thrd)
            {
                ans+="]";
                thrd=0;
            }
            if(scnd)ans+=s[i];
            else
            {
                scnd=1;
                ans+="{";
                ans+=s[i];
            }
        }
        else
        {
            lowb++;
            if(frst)
            {
                ans+=")";
                frst=0;
            }
            if(scnd)
            {
                ans+="}";
                scnd=0;
            }
            if(thrd)ans+=s[i];
            else
            {
                thrd=1;
                ans+="[";
                ans+=s[i];
            }
        }
    }
    if(frst)ans+=")";
    if(scnd)ans+="}";
    if(thrd)ans+="]";
    return ans;

}

int dp[105][105];
int call(int bam,int dan)
{
    int &ret = dp[bam][dan];
    if(bam==a.size()&&dan == b.size())return ret=0;
    if(ret!=-1)return ret;
    ret=INF;
    if(bam==a.size())ret=min(ret,call(bam,dan+1)+1);
    else if(dan==b.size())ret=min(ret,call(bam+1,dan)+1);
    else if(a[bam]==b[dan])ret=min(ret,call(bam+1,dan+1)+1);
    else
    {
        ret=min(ret,call(bam,dan+1)+1);
        ret=min(ret,call(bam+1,dan)+1);
    }
    return ret;
}
string pat;
void pri(int bam,int dan,int len)
{
    if(bam==a.size()&&dan == b.size())return;
    if(bam==a.size())
    {
        pat+=b[dan];
        pri(bam,dan+1,len-1);
    }
    else if(dan==b.size())
    {
        pat+=a[bam];
        pri(bam+1,dan,len-1);
    }
    else if(a[bam]==b[dan])
    {
        pat+=a[bam];
        pri(bam+1,dan+1,len-1);
    }
    else
    {
        if(dp[bam+1][dan]<dp[bam][dan+1])
        {
            pat+=a[bam];
            pri(bam+1,dan,len-1);
        }
        else if(dp[bam+1][dan]>dp[bam][dan+1])
        {
            pat+=b[dan];
            pri(bam,dan+1,len-1);
        }
        else
        {
            if(a[bam]<b[dan])
            {
                pat+=a[bam];
                pri(bam+1,dan,len-1);
            }
            else
            {
                pat+=b[dan];
                pri(bam,dan+1,len-1);
            }
        }
    }
//    return ret;

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
//    cin>>t;
//    rep(cs,t)
    while(cin>>a>>b)
    {
//        cout<<"Case "<<cs<<":"<<endl;
        SET(dp);
//        cout<<call(0,0)<<endl;
        pat = "";
        pri(0,0,call(0,0));
        string ans = pat;
        cout<<ans<<endl;
    }

    return 0;
}



