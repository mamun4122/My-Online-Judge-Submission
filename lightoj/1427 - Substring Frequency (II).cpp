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
#define repI(i,n) for( i = 0 ; i<(n) ; i++)
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


#define MX 510      //small string length

int m, n, res;
typedef pair<int, int> Point;

struct NODE
{
    int cnt;
    bool vis;
    NODE *next[27];
    vector <NODE *> out;
    NODE()
    {
        for(int i = 0; i < 27; i++)
        {
            next[i] = NULL;
        }
        out.clear();
        vis = false;
        cnt=0;
    }

    ~NODE()
    {
        for(int i = 1; i < 27; i++)
            if(next[i] != NULL && next[i] != this)
                delete next[i];
    }
}*root;

void buildtrie(char dictionary[][MX],int n)      // processing the dictionarytionary
{

    root = new NODE();

    /*usual trie part*/
    for(int i = 0; i < n; i++)
    {
        NODE *p = root;
        for(int j = 0; dictionary[i][j] ; j++)
        {
            char c = dictionary[i][j]- 'a' + 1;
            if(!p->next[c])
                p->next[c] = new NODE();
            p = p->next[c];
        }
    }

    /* Pushing the nodes adjacent to root into queue */
    queue <NODE *> q;
    for(int i = 0; i < 27; i++)
    {
        if(!root->next[i])
            root->next[i] = root;
        else
        {
            q.push(root->next[i]);
            root->next[i]->next[0] = root;  // ->next[0] = back Pointer

        }
    }

    /* Building Aho-Corasick tree */
    while(!q.empty())
    {
        NODE *u = q.front();    // parent node
        q.pop();

        for(int i = 1; i < 27; i++)
        {
            if(u->next[i])
            {
                NODE *v = u->next[i];   // child node
                NODE *w = u->next[0];   // back pointer of parent node
                while( !w->next[i] )    // Until the char(i+'a'-1) child is found
                    w = w->next[0];     // go up and up to back pointer.

                v->next[0] = w = w->next[i];  // back pointer of v will be found child above.
                w->out.push_back(v);    // out will be used in dfs step.
                // here w is the new found match node.
                q.push(v);              // Push v into queue.
            }
        }
    }
}

void aho_corasick(NODE *p, char *word)      // Third step, processing the text.
{
    for(int i = 0; word[i]; i++)
    {
        char c = word[i]-'a'+1 ;
        while(!p->next[c])
            p = p->next[0];
        p = p->next[c];
        p->cnt++;
    }
}

int dfs( NODE *p )      // DFS for counting.
{
    if(p->vis) return p->cnt;
    for(int i = 0; i < p->out.size(); i++)
        p->cnt += dfs(p->out[i]);
    p->vis = true;
    return p->cnt;
}

char query[1000100];
char dictionary[MX][MX];

int main()
{
    //READ("in.txt");
    int t, tc, y, z;
    int i, j, k, l, h;
    char ch;
    scanf ("%d", &tc);
    for (t = 1; t <= tc; t++)
    {
        int n;
        scanf("%d",&n);

        scanf("%s",query);

        for (int i=0; i<n; ++i)
        {
            scanf("%s",dictionary[i]);
        }

        buildtrie(dictionary, n);

        aho_corasick(root, query);

        printf("Case %d:\n",t);

        for(int i = 0; i < n; i++)
        {
            NODE *p = root;
            for(int j = 0; dictionary[i][j]; j++)
            {
                char c = dictionary[i][j] -'a' +1;
                p = p->next[c];
            }
            printf("%d\n", dfs(p));
        }
        delete root;
    }

    return 0;
}
