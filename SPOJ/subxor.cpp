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
    int lft,rgt;
    node *next[2];
    node()
    {
        lft=rgt=0;
        for(int i=0; i<2; i++)
            next[i]=NULL;
    }
}*root;

void insert(int n)
{
    node *curr=root;
    for(int i=20; i>=0; i--)
    {
        int id=Check(n,i);

        if(id)curr->rgt++;
        else curr->lft++;
        //debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }

}
ll find_ans(int n,int k)
{
    node *curr=root;
    ll sum=0;
    for(int i=20; i>=0; i--)
    {
        int id_k=Check(k,i);
        int id_n=Check(n,i);
        if(id_k)
        {
            if(id_n)
            {
                sum+=curr->rgt;
                if(curr->next[0]==NULL)
                    return sum;
                curr=curr->next[0];
            }
            else
            {
                sum+=curr->lft;
                if(curr->next[1]==NULL)
                    return sum;
                curr=curr->next[1];
            }
        }
        else
        {
            if(id_n)
            {
                if(curr->next[1]==NULL)
                    return sum;
                curr=curr->next[1];
            }
            else
            {
                if(curr->next[0]==NULL)
                    return sum;
                curr=curr->next[0];
            }

        }
    }
    //debug(sum);
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
        int n,k;
        getII(n,k);
        ll res=0;
        int x,temp=0;
        insert(0);
        while(n--)
        {
            getI(x);
            temp^=x;
            res+=find_ans(temp,k);
            insert(temp);

        }
        printf("%lld\n",res);

        del(root);
    }
    return 0;
}
