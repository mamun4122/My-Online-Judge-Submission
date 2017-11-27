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
long long base = 10007;
long long mod = 2078526727;
ll val[300005], pre[5][300005];
char vua[5][300005];
void get_hash(string str,int indx)
{
 long long hash_val =0;
 for(int i=0;str[i];i++)
 {
  hash_val = hash_val * base + str[i];
  hash_val %= mod;
  pre[indx][i] = hash_val;
  vua[indx][i] = str[i];
 }
// return hash_val;
}
void call()
{
    val[0] = 1;
    rep(i,300005)
    {
        val[i] = val[i-1]*base;
        val[i] %= mod;
    }
}
string a,b,c;
vector<int> v;
int len[10];
char getVal(int indx,int pos)
{
//    debug(pos)
    if(indx == 1)return a[pos];
    if(indx == 2)return b[pos];
    if(indx == 3)return c[pos];
}
int merge(int indx1, int len1, int indx2, int len2,int type)
{
    if(len1>=len2)
    {
        ll prev = 0,gun = val[len2+1];
        repI(i,len1+1)
        {
            if(i+len2>len1)break;
            ll hsh = pre[indx1][i+len2] - prev * gun;
            if(hsh < 0) hsh = ((hsh%mod)+mod)%mod;
            if(hsh == pre[indx2][len2])
            {
//                debug("sa",len1)
                return len1;
            }
            prev = pre[indx1][i];
        }
    }
    int low = 0, high = min(len1,len2);
//    debug(high)
    int ans = 0;
    int mid = 0;
    while(mid <= high)
    {
        ll hsh1 = pre[indx1][len1] - (len1-mid-1<0 ? 0 : pre[indx1][len1-mid-1]) * val[mid+1];
        if(hsh1 < 0) hsh1 = ((hsh1%mod)+mod)%mod;
        ll hsh2 = pre[indx2][mid];
        if(hsh1 == hsh2)
        {
            ans = mid+1;
        }
        mid++;
    }
//    debug(ans)
    int cnt = 1;
    FOR(i,ans,len2)
    {
        if(type == 1)
            vua[indx1][len1+cnt] =  getVal(indx2,i);
        pre[indx1][len1+cnt] = pre[indx1][len1+cnt-1] * base + vua[indx2][i];
        pre[indx1][len1+cnt] %= mod;
        cnt++;
    }
    return len1+cnt-1;
}
int call(int frst,int scnd,int thrd)
{
    int lenght = merge(scnd,len[scnd],thrd,len[thrd],1);
//    debug(scnd,thrd,lenght+1)
    return merge(frst,len[frst],scnd,lenght,2)+1;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    call();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    while(cin>>a)
    {
        cin>>b>>c;
        get_hash(a,1);
        get_hash(b,2);
        get_hash(c,3);
        len[1] = a.size()-1;
        len[2] = b.size()-1;
        len[3] = c.size()-1;
        debug("len", len[1],len[2],len[3])

        int ans = INF;
        sort(ALL(v));
        do
        {
            ans = min(ans,call(v[0],v[1],v[2]));
            rep(i,3)if(ans == len[i]+1)break;
        }while(next_permutation(ALL(v)));
        cout<< ans <<endl;
    }

    return 0;
}