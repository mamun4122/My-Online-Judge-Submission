#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
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
#define mx 26
int dp[10005];
struct node
{
    bool endmark;
    node *next[mx+1];
    node()
    {
        endmark=0;
        for(int i=0; i<mx; i++)
   next[i]=NULL;
    }
}*root;

void insert(string str,int len)
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;

}
string fin;
int search(int pos,int len)
{
    int &ret=dp[pos];
    if(pos==len)return ret=true;
    if(ret!=-1)return ret;

    node *curr=root;
    for(int i=pos; i<len; i++)
    {
        int id=fin[i]-'a';
//        debug(fin[i])
        if(curr->next[id]==NULL) return ret=0;
        curr=curr->next[id];
        if(curr->endmark)
        {
            int tmp=search(i+1,len);
            if(tmp)return ret=tmp;
        }
    }
    return ret=curr->endmark;   // returns 1 or 0
}
map<string,string> mp;
vector<string> v;
void print(int pos,int len)
{
//    debug(fin,pos)
//    debug(pos,fin[pos])
    if(pos==len)return;
    node *curr=root;
    string ans="";
    for(int i=pos; i<len; i++)
    {
        int id=fin[i]-'a';
        ans+=fin[i];
        curr=curr->next[id];
        if(curr->endmark)
        {
            if(dp[i+1]==1)
            {
                v.push_back(mp[ans]);
                print(i+1,len);
                return;
            }
        }
    }
}

void del(node *cur)    // send root here
{
    for(int i=0; i<mx; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n)
    {
        SET(dp);
        mp.clear();v.clear();
        root=new node();
        string s,tmp;
        cin>>fin;
        reverse(ALL(fin));
        cin>>m;
        rep(i,m)
        {
            cin>>s;
            tmp=s;
            repI(i,tmp.size())tmp[i]=tolower(tmp[i]);
//            debug(tmp)
            mp[tmp]=s;
            insert(tmp,tmp.size());
        }
        search(0,fin.size());
        print(0,fin.size());
        reverse(ALL(v));
        repI(i,v.size())cout<<v[i]<<" ";
        cout<<endl;

        del(root);
    }


    return 0;
}