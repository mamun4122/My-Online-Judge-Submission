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
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
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
struct node
{
    bool endmark;
    int cnt;
    node *next[2];
    node()
    {
        endmark=0;
        cnt=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
    }
}*root;

void insert(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
//        debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr->next[id]->cnt++;
        curr=curr->next[id];
    }
    curr->endmark=1;

}
void del(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        curr->next[id]->cnt--;
        curr=curr->next[id];
    }
    curr->endmark=1;

}
int find_max(int n)
{
    node *curr=root;
    int sum=0;
    for(int i=30; i>=0; i--)
    {
        int id=bitCheck(n,i);
        int inv=1-id;       //ja ache tar inverse ta khujtasi tai inverse nilam
        if(curr->next[inv]!=NULL&&curr->next[inv]->cnt)
        {
            sum=sum | (1<<i);   //jdi inverse pai tahola result er oi position a 1 set hba
            curr=curr->next[inv];
        }
        else
        {
            //na paila 0 set hba
            curr=curr->next[id];
        }
    }
//    debug(sum);
    return sum;
}
//int find_min(int n)
//{
//    node *curr=root;
//    int sum=0;
//    for(int i=30; i>=0; i--)
//    {
//        int id=Check(n,i);
//        int inv=1-id;
//        if(curr->next[id]!=NULL)
//        {
//            curr=curr->next[id];  //jdi inverse pai tahola result er oi position a 0 set hba
//        }
//        else
//        {
//            sum=sum | (1<<i); //na paila 1
//            curr=curr->next[inv];
//        }
//    }
//    return sum;
//}

void del(node *cur)    // send root here
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun

    int num_word;
    while(~getI(num_word))
    {
        root=new node();
        insert(0);
        rep(i,num_word)
        {
        getchar();
            char type;
            scanf("%c %d",&type,&m);
//            debug(type,m)
            if(type=='+')
            {
                insert(m);
            }
            else if(type=='-')
            {
                del(m);
            }
            else
            {
                int mx=find_max(m);
//                debug(mx)
                printf("%d\n",mx);
           }

        }
        del(root);
    }

        return 0;
}