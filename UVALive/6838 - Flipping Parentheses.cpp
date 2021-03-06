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
#define mx 300001
int arr[mx];
int cum[mx];
struct info
{
    int sum;
    int prop;
}tree[mx*4];
info call(info a,info b)
{
    info tmp;
    ///merge two info
    tmp.sum = min(a.sum,b.sum);
    tmp.prop = 0;
    return tmp;
}
void init(int node,int b,int e)
{
	if(b==e)
	{
	    ///do something
	    tree[node].prop = 0;
	    tree[node].sum = cum[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}
void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop = 0;
        return;
    }
	int Left = node<<1;
	int Right = (node<<1)+1;
	int mid = (b+e)>>1;
	///update propagation
	tree[Left].prop += tree[node].prop;
	tree[Right].prop += tree[node].prop;
    ///update tree[left]
    tree[Left].sum += tree[node].prop;
    ///update tree[right]
    tree[Right].sum += tree[node].prop;
    tree[node].prop = 0;

}
int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)return INF;
	if(tree[node].prop != 0)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node].sum;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);
    return  min(p1,p2);

}

void update(int node,int b,int e,int i,int j,int val)
{
	if(tree[node].prop != 0)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        ///do something
        tree[node].prop += val;
        tree[node].sum += val;
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,val);
	update(Right,mid+1,e,i,j,val);
	tree[node] = call(tree[Left],tree[Right]);
}
set<int> st;
#define open 1
#define close -1
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin >> n >> m)
    {
        st.clear();
        CLR(arr);
        CLR(cum);
        cin >> s;
        rep(i,n)
            arr[i] = s[i-1] == '(' ? open : close;
        rep(i,n)
            cum[i] = cum[i-1] + arr[i];
        rep(i,n)
            if(arr[i] == close)
                st.insert(i);
        init(1,1,n);
        rep(i,m)
        {
            int x;
            cin >> x;
            if(arr[x] == open)
            {
                arr[x] = close;
                st.insert(x);
                update(1,1,n,x,n,-2);
                int val = *st.begin();
                st.erase(val);
                printf("%d\n",val);
                update(1,1,n,val,n,2);
                arr[val] = open;
            }
            else
            {
//                debug("")
                arr[x] = open;
                st.erase(x);
                update(1,1,n,x,n,2);
                int low = 1,high = n;
                int val;
                while(low <= high)
                {
                    int mid = (low+high)/2;
//                    debug()
                    if(query(1,1,n,mid,n) >= 2)
                        val = mid,high = mid-1;
                    else
                        low = mid+1;
                }
                printf("%d\n",val);
                st.insert(val);
                arr[val] = close;
                update(1,1,n,val,n,-2);

            }
        }
    }

    return 0;
}

