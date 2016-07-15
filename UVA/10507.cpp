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
map<char,int> mp;
vector<int> edge[30];
int d[30],cnt[30],mark[30];
string z;
void bfs()
{
    SET(d);
    CLR(cnt);CLR(mark);
    mark[1]=mark[2]=mark[3]=1;
    d[1]=d[2]=d[3]=0;
    cnt[1]=cnt[2]=cnt[3]=3;
    queue<int> q;
    q.push(1);q.push(2);q.push(3);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            if(mark[edge[u][i]])continue;
            cnt[edge[u][i]]++;
            if(cnt[edge[u][i]]>=3){
                    mark[edge[u][i]]=1;
                    q.push(edge[u][i]);
            }
            if(d[edge[u][i]]<d[u]+1)
                d[edge[u][i]]=d[u]+1;
        }
    }
}



int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    while(getI(t)==1)
    {
        CLR(d);CLR(cnt);
        mp.clear();
        for(int i=0;i<30;i++)edge[i].clear();
        int n;
        getI(n);
        string x;
        cin>>z;
       // debug(z);
        int k=4;
        mp[z[0]]=1;mp[z[1]]=2;mp[z[2]]=3;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            //debug(x);
            if(!mp[x[0]])mp[x[0]]=k++;
            if(!mp[x[1]])mp[x[1]]=k++;
            edge[mp[x[0]]].push_back(mp[x[1]]);
            edge[mp[x[1]]].push_back(mp[x[0]]);
        }
        bfs();
        int mx=0,flag=0;
        for(int i=1;i<=t;i++)
        {
            if(mark[i]==0||d[i]==-1)
            {
                flag=1;
                break;
            }
            else
                mx=max(d[i],mx);
        }
        if(flag) printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n",mx);



    }
    return 0;
}


