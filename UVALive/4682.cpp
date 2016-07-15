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
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

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
#define mamu
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
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

struct node
{
    bool endmark;
    node *next[2];
    node()
    {
        endmark=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
    }
}*root;

void insert(int n)
{
    node *curr=root;
    for(int i=30; i>=0; i--)
    {
        int id=Check(n,i);
        //debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
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
        int id=Check(n,i);
        int inv=1-id;       //ja ache tar inverse ta khujtasi tai inverse nilam
        if(curr->next[inv]!=NULL)
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
    debug(sum);
    return sum;
}
int find_min(int n)
{
    node *curr=root;
    int sum=0;
    for(int i=30; i>=0; i--)
    {
        int id=Check(n,i);
        int inv=1-id;
        if(curr->next[id]!=NULL)
        {
            curr=curr->next[id];  //jdi inverse pai tahola result er oi position a 0 set hba
        }
        else
        {
            sum=sum | (1<<i); //na paila 1
            curr=curr->next[inv];
        }
    }
    return sum;
}

void del(node *cur)				// send root here
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;
    delete(cur) ;
}

int main()
{

    //READ("in.txt");
    //WRITE("out.txt");
    //node *root;
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        root=new node();
        int num_word;
        cin>>num_word;
        int n;
        int mx=0,mn=INF,tmp=0;
        insert(0);
        for(int i=1; i<=num_word; i++)
        {
            getI(n);
            tmp=tmp^n;
            mx=max(mx,find_max(tmp));
            mn=min(mn,find_min(tmp));
            insert(tmp);
        }
        printf("%d\n",mx);
        del(root);
    }
    return 0;
}

/*Suppose you have saved all consecutive XOR sum from index [0, 0], [0, 1], [0, 2], ..., [0, i-1],
now we want to calculate for result [0, i] and save it. And you also want to find a k such that[k, i]
is as large as possible. Usually [k, i] = [0, i] (XOR) [0, k - 1].Say, [0, i] = 11011, then you would
definitely want to find 00100 in your saved list. If you cannot find that you would want to find the
number closer to that
*/
