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

vector<int> v;
struct node
{
    int endmark;
    node *next[10];
    node()
    {
        endmark=0;
        for(int i=0; i<10; i++)
            next[i]=NULL;
    }
}*root;

void insert(string num)
{
//    debug(num)
    node *curr=root;
    repI(i,19)
    {
        int id = num[i] - '0';
//        debug(id);
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr=curr->next[id];
        curr->endmark++;
    }

}
void deletenow(string num)
{
    node *curr=root;
    repI(i,19)
    {
        int id = num[i] - '0';
        curr=curr->next[id];
        curr->endmark--;
    }

}

void del(node *cur)    // send root here
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}
string arr[1000005];
void process(string &num)
{
    reverse(ALL(num));
    while(num.size() < 19)num += "0";
    reverse(ALL(num));
//    debug(num)
    insert(num);
}
ll find_min(string num)
{
//    debug(num)
    node *cur = root;
    ll ans = 0;
    repI(i,19)
    {
        int id = num[i] - '0';
//        debug(id)
        int mn = 15;
        int pos;
        repI(j,10)
        {
            if(cur->next[j] != NULL && cur->next[j]->endmark>0 && ((id+j)%10) < mn)
                mn = (id+j)%10,pos = j;
        }
        ans *= (ll)10;
        ans += mn;
        cur = cur->next[pos];
    }
    return ans;
}

ll find_max(string num)
{
    node *cur = root;
    ll ans = 0;
    repI(i,19)
    {
        int id = num[i] - '0';
//        debug(id)
        int mn = -1;
        int pos;
        repI(j,10)
        {
            if(cur->next[j] != NULL && cur->next[j]->endmark>0 && ((id+j)%10) > mn)
                mn = (id+j)%10,pos = j;
        }
        ans *= (ll)10;
        ans += mn;
        cur = cur->next[pos];
    }
    return ans;
}


/// min max
pair<ll,ll> processthis(string num)
{
//    debug(num)
    deletenow(num);
    ll mini = find_min(num);
    ll maxi = find_max(num);
//    debug(num,mini)
//    debug("")
    insert(num);
    return MP(mini,maxi);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n)
    {
        root = new node();
        rep(i,n)cin >> arr[i];
        rep(i,n)process(arr[i]);
//        rep(i,n)debug(arr[i])
//        debug("")
        ll ansmx = 0, ansmn = LONG_LONG_MAX;
//        debug(ansmn)
        rep(i,n)
        {
            auto res =  processthis(arr[i]);
            ansmn = min(ansmn, res.ff);
            ansmx = max(ansmx, res.ss);
        }
        cout << ansmn << " " << ansmx << "\n";
        del(root);
    }

    return 0;
}