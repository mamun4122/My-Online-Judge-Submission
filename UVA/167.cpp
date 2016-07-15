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
int mark[66][66],arr[66][66];
int maxi;
bool issafe(int row,int col)
{
    for(int i=1; i<=8; i++)
        if(i!=col&&mark[row][i])return false;
    for(int j=1; j<=8; j++)
        if(j!=row&&mark[j][col])return false;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
        {
            if(abs(row-i)==abs(col-j)&&!(i==row&&j==col)&&mark[i][j])
                return false;

        }
    return true;
}

void backtrack(int row,int sum)
{
    if(row>8)
    {
        maxi=max(maxi,sum);
        return;
    }
    for(int i=1; i<=8; i++)
    {
        if(issafe(row,i))
        {
            mark[row][i]=1;
            backtrack(row+1,sum+arr[row][i]);
            mark[row][i]=0;
        }
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    getI(n);
    while(n--)
    {
        CLR(mark);
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
                getI(arr[i][j]);

        maxi=-1;
        backtrack(1,0);
        printf("%5d\n",maxi);

    }



    return 0;
}


