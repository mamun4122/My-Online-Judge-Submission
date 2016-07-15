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

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }

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
bool flag;

struct node
{
    //READ("in.txt");
    //WRITE("out.txt");
    bool endmark;
    node *next[10];
    node()
    {
        endmark=0;
        for(int i=0; i<10; i++)
            next[i]=NULL;
    }
}*root;

void insert(char *str,int len)			// parameter = word & length of word
{
    bool flag2=true;
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL){
            flag2=false;
            curr->next[id]=new node();
        }
        curr=curr->next[id];
        if(curr->endmark==1)flag=true;
    }
    curr->endmark=1;
    if(flag2)flag=true;

}



void del(node *cur)						// parameter hisebe root pathate hbe
{
    for(int i=0; i<10; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        flag=false;

        //node *root;
        root=new node();
        int num_word;
        getI(num_word);
        for(int i=1; i<=num_word; i++)		// String nea + Insert starts HERE
        {
            char str[12];
            scanf("%s\n",str);
            //cout<<str<<endl;
            if(!flag)
                insert(str,strlen(str));
        }
        //printf("Case %d: ",cs);
        printf(flag? "NO\n":"YES\n");

        del(root);						// Delete the TRIE starts HERE
    }
    return 0;
}



