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
int arr[26];
int cum[26][1005],nxt[1005];
ll dp[1005];
const ll mod = 1e9+7;
string s;

int binary(int pos)
{
    int id=s[pos]-'a';
    int low=pos,high=n-1,ans=pos;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int flag=1;
        repI(k,26)
        {
            int val=cum[k][mid]-(pos-1<0?0:cum[k][pos-1]);
            if(val&&mid-pos+1>arr[k])flag=0;
        }
        if(flag)
        {
            low=mid+1;
            ans=mid;
        }
        else high=mid-1;
    }
    return ans+1;
}

ll call(int pos)
{
    if(pos>=n)return 1;
    ll &ret=dp[pos];
    if(ret!=-1)return ret;
    ret=0;
    int val=nxt[pos];
//    debug("d",pos,val)
    FOR(i,pos+1,val)
    {
//        debug(pos,i)
        ret+=call(i);
//        debug(pos,i,ret)
        ret%=mod;
    }
    return ret;
}
int ase[30];
ll call1(int pos)
{
    if(pos>=n)return 0;
    ll &ret=dp[pos];
    if(ret!=-1)return ret;
    ret=INF;
    int val=nxt[pos];
//    debug("d",pos,val)
    FOR(i,pos+1,val)
    {
//        debug(pos,i)
        ret=min(ret,call1(i)+1);
//        debug(pos,i,ret)
//        ret%=mod;
    }
    return ret;

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
        cin>>s;
        CLR(ase);
        repI(i,s.size())ase[s[i]-'a']=1;
        repI(i,26)cin>>arr[i];
        int flag=0;
        repI(i,26)
        {
            if(arr[i]==0&&ase[i])
            {
                flag=1;
            }
        }
        if(flag)
        {

            cout<<"0"<<endl;
            cout<<"0"<<endl;
            cout<<"0"<<endl;
            continue;
        }
        //SET(dp);
        CLR(cum);
        repI(i,s.size())
        {
            repI(j,26)cum[j][i]=(i==0?0:cum[j][i-1]);
            cum[s[i]-'a'][i]++;
        }
        repI(i,s.size())nxt[i]=binary(i);
//        repI(i,s.size())debug(nxt[i])
        SET(dp);
        ll ans=call(0);
        cout<<ans<<endl;
        int fuck=0;
        repI(i,n)fuck=max(fuck,nxt[i]-i);
        cout<<fuck<<endl;
        SET(dp);
        cout<<call1(0)<<endl;
    }

    return 0;
}