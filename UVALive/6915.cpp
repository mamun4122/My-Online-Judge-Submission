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
string s;
set<pii> st;
#define SIZE 1000005
int sparse[30][SIZE], height;
int sparsemx[30][SIZE];
int lvl[SIZE];
int cost[SIZE];
int b[SIZE];
int r[SIZE];


int buildTable ( int n ) {

    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparse[0][i] = lvl[i];
        sparsemx[0][i] = lvl[i];
    }

    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for ( int j = 0; j < n; j++ ) {
            int k = j + prev;
            if ( k >= n ) k = n - 1;
            sparse[i][j] = min ( sparse[i-1][j], sparse[i-1][k]);
            sparsemx[i][j] = max ( sparsemx[i-1][j], sparsemx[i-1][k]);
        }

        cur *= 2;
        prev *= 2;
    }
}

/// call once before all test cases
void preCalculate(int n)
{
    int xx = 1,rr=0;
    FOR(i,1,n)
    {
        if(i!=1 && !(i&(i-1)))
        {
            xx *= 2;
            rr ++;
        }
        b[i]=xx;
        r[i]=rr;
    }
}

/// 0 indexed
pii rmq ( int i, int j ) {
    int len = j - i + 1;
    int two = b[len];
    int row = r[len];
    int res = min ( sparse[row][i], sparse[row][j-two+1] );
    int res1 = max ( sparsemx[row][i], sparsemx[row][j-two+1] );
    return pii(res,res1);
}



int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    preCalculate(1000000);
    rep(cs,t)
    {
        st.clear();
        cin >> n >> m;
        cin >> s;
        int now = 0;
        repI(i,s.size()){
            if(s[i] == '/')lvl[i] = now,now++,cost[i] = 1;
            else if(s[i] == '\\')now--,lvl[i] = now,cost[i] = 1;
            else lvl[i] = now,cost[i] = 0;
        }
//        preCalculate(n);
        buildTable(n);
        ll sum = 0;
//        repI(i,s.size())
//        {
//            if(i == m)break;
//            st.insert(pii(lvl[i],i));
//        }
        int low = 0,high = 0;
        ll ans = LLONG_MAX;
        while(high < s.size())
        {
            auto it = rmq(low,high<m?m-1:high-1);
            if(high >= m){
//                st.erase(pii(lvl[low],low));
                int prev = it.ff;
                sum -= cost[low];
                sum -= (lvl[low]-prev)*2;
//                st.insert(pii(lvl[high],high));
                low++;
                it = rmq(low,high);

                int cur = it.ff;
                if(cur < prev)sum += (prev-cur)*2*(m-1);
                else if(cur > prev)sum -= (cur-prev)*2*(m-1);
                sum += cost[high] + (lvl[high]-cur)*2;
            }
            else
            {
                sum += cost[high];
                sum += (lvl[high]-it.ff)*2;
            }
            if(high >= m-1)ans = min(ans,sum);
            high++;
        }
        double res = (double)ans/2;
        cout << "Case #" << cs << ": ";
        cout << setprecision(1) << fixed << res << endl;
    }
    return 0;
}

