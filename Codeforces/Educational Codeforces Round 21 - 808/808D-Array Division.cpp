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
ll arr[100005];
ll suf[100005];
ll pre[100005];
typedef pair<pair<ll,ll>,int> ps;
ps make(ll i,ll j,int k)
{
    if(j > i) swap(i,j);
    return MP(MP(i,j),k);
}
int bfs(ll tar)
{
    priority_queue<ps> pq;
    pq.push(make(0,0,1));
    while(!pq.empty())
    {
        ps tmp = pq.top();
        pq.pop();
        ll val1 = tmp.ff.ff;
        ll val2 = tmp.ff.ss;
        int pos = tmp.ss;
        if(val1 == tar || val2 == tar)return true;
        if(val1 > tar || val2 > tar)continue;
        if(val2 > val1)swap(val1,val2);
        if(val1+suf[pos]<tar || pos > n)continue;
        /// jog korbo
        pq.push(make(val1+arr[pos],val2,pos+1));
        /// na
        pq.push(make(val1,val2+arr[pos],pos+1));
    }
    return false;
}


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        CLR(suf);
        CLR(pre);
        ll tot = 0;
        rep(i,n)
        {
            getL(arr[i]);
            tot += arr[i];
        }
        if(tot%2 == 1)
        {
            puts("NO");
            continue;
        }
//        sort(arr+1,arr+1+n);
        ROF(i,n,1)
            suf[i] = suf[i+1]+arr[i];
        rep(i,n)
            pre[i] = pre[i-1]+arr[i];
        ll each = tot/2;
        int flag = 0;
        rep(i,n)
        {
            if(pre[i] == each)
            {
                flag = 1;
                break;
            }
            else
            {
                ll sorabo = arr[i];
                ll khujbo = each+sorabo;
                debug(pre[i],sorabo,khujbo);
                if(i == n)continue;
                if(binary_search(pre+i+1,pre+1+n,khujbo))
                {
                    flag = 1;
                    break;
                }
            }
        }
        reverse(arr+1,arr+1+n);
        reverse(suf+1,suf+1+n);
        ROF(i,n,1)
        {
            if(suf[i] == each)
            {
                flag = 1;
                break;
            }
            else
            {
                ll sorabo = arr[i];
                ll khujbo = each+sorabo;
//                debug(pre[i],sorabo,khujbo);
                if(i == n)continue;
                if(binary_search(suf+i+1,suf+1+n,khujbo))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }

    return 0;
}