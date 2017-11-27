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
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double


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
     #define debug(args...) {dbg,args; cerr<<endl;}
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
int buy[100010],sell[100010];//,pos1[1010],pos2[1010];
struct info
{
    int price,quantity;ll val;
    info(int p,int q,ll v)
    {
        price=p;quantity=q;val=v;
    }
};
bool cmp1(const info &a,const info &b)
{
    return a.price>b.price;
//    if(a.val>b.val)return true;
//    else if(a.val==b.val)return a.price>b.price;
//    return false;
}
bool cmp2(const info &a,const info &b)
{
    return a.price<b.price;
//    if(a.val<b.val)return true;
//    else if(a.val==b.val)
//    {
//        return a.price>b.price;
//    }
//    return false;
}
bool cmp3(const info &a,const info &b)
{
    if(a.price>b.price)return true;
    return false;
}
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int n,st;
    getII(n,st);
    int i;
    char c;int p,q;
    set<int> by,sel;
    CLR(buy);CLR(sell);
    vector<info> b,s;
    rep(i,n)
    {
        cin>>c>>p>>q;
        if(c=='B')
        {
            buy[p]+=q;
            //if(by.count(p)==0)pos1[p]=i;
            by.insert(p);
        }
        else
        {

            sell[p]+=q;
            //if(sel.count(p)==0)pos2[p]=i;
            sel.insert(p);
        }
    }
    for(set<int>::iterator it=by.begin();it!=by.end();it++)
    {
        b.push_back(info(*it,buy[*it],(*it)*buy[*it]));
    }
    for(set<int>::iterator it=sel.begin();it!=sel.end();it++)
    {
        s.push_back(info(*it,sell[*it],(*it)*sell[*it]));
    }
    sort(ALL(b),cmp1);
    if(st<=b.size())
    sort(b.begin(),b.begin()+st,cmp3);
    else
        sort(ALL(b),cmp3);
    sort(ALL(s),cmp2);
    if(st<=s.size())
    sort(s.begin(),s.begin()+st,cmp3);
    else
        sort(ALL(s),cmp3);
    //reverse(ALL(s));
    rep(i,st)
    {
        if(i>s.size())break;
        printf("S %d %d\n",s[i-1].price,s[i-1].quantity);
    }
    rep(i,st)
    {
        if(i>b.size())break;
        printf("B %d %d\n",b[i-1].price,b[i-1].quantity);
    }

    return 0;
}