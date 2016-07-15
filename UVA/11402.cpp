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


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define iseq(a,b) (fabs(a-b)<EPS)

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}



//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
#define mx 1024001
struct info
{
    int val;//,change;
} tree[mx*4];
int toggle[mx*4];//allval[mx*3];
//string s;

//char a[2*mx];
//char s[100000];
int P[mx];
string s;

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].val=P[b];//-48;
        toggle[node]=0;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].val=tree[Left].val+tree[Right].val;
    toggle[node]=0;
}
void Propagate(int at, int L, int R)
{
    int mid = (L + R)/2;
    int left_at = at *2, left_L = L, left_R = mid;
    int right_at = at * 2 + 1, right_L = mid + 1,right_R = R;
    if(toggle[at]==1)
    {
        toggle[left_at]=toggle[right_at]=1;
        //if(L==R)tree[at].val
        tree[at].val=R-L+1;
        toggle[at]=0;
        return;
    }
    if(toggle[at]==2)
    {
        toggle[left_at]=toggle[right_at]=2;
        tree[at].val=0;
        toggle[at]=0;
        return;
    }
    if(toggle[at]==3)
    {
        tree[at].val=R-L+1-tree[at].val;
        if(toggle[left_at]==1)toggle[left_at]=2;
        else if(toggle[left_at]==2)toggle[left_at]=1;
        else if(toggle[left_at]==3)toggle[left_at]=0;
        else toggle[left_at]=3;
        if(toggle[right_at]==1)toggle[right_at]=2;
        else if(toggle[right_at]==2)toggle[right_at]=1;
        else if(toggle[right_at]==3)toggle[right_at]=0;
        else toggle[right_at]=3;
        toggle[at]=0;
        return;
    }


//    tree[left_at].val = left_R-left_L + 1 - tree[left_at].val;
//    tree[right_at].val = right_R - right_L + 1 - tree[right_at].val;
}

void updateinv(int at, int L, int R, int l, int r,int type)
{
    if(toggle[at])Propagate(at,L,R);
    if(r < L || R < l) return;
    if(l <= L && R <= r)
    {
        toggle[at]=type;
        Propagate(at,L,R);
        //debug(tree[at].val,L,R)
        return;
    }

    //if(toggle[at]) Propagate(at, L, R);

    int mid = (L + R)/2;
    updateinv(at * 2, L, mid, l, r,type);
    updateinv(at * 2 + 1, mid + 1, R, l, r,type);
    tree[at].val = tree[at * 2].val + tree[at * 2 + 1].val;
}

int query(int at, int L, int R, int l, int r)
{
    // debug("at",at,toggle[at],L,R)
    if(toggle[at])Propagate(at,L,R);
    if(r < L || R < l) return 0;
    if(l <= L && R <= r)
    {
        return tree[at].val;
    }


    //if(toggle[at]) Propagate(at, L, R);

    int mid = (L + R)/2;
    int x = query(at * 2, L, mid, l, r);
    int y = query(at * 2 + 1, mid + 1,R, l, r);
    // debug(at,L,R,x,y,toggle[at]);
    return x + y;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int cases;
    cin >> cases;

    for(int tt=1; tt<=cases; tt++)
    {
        cout << "Case " << tt << ":" << endl;

        int m;
        cin >> m;
        int n = 0;
        for(int i=0; i<m; i++)
        {
            int t;
            cin >> t >> s;
            for(int j=0; j<t; j++)
            {
                for(int k=0; k<s.size(); k++)
                {
                    P[++n] = s[k]-'0';
                }
            }
        }
        CLR(toggle);
        CLR(tree);
        init(1,1,n);
        //T.clear(n, P);

        int q;
        cin >> q;
        int qry = 0;
        while(q--)
        {
            char cmd;
            int a, b;
            cin >> cmd >> a >> b;
            a++;
            b++;
            if (cmd == 'F')
            {
                updateinv(1,1,n,a, b, 1);
            }
            else if (cmd == 'E')
            {
                updateinv(1,1,n,a, b, 2);
            }
            else if (cmd == 'I')
            {
                updateinv(1,1,n,a, b, 3);
            }
            else
            {
                int node = query(1,1,n,a, b);
                cout << "Q" << ++qry << ": " << node << endl;
            }
        }
    }
}
