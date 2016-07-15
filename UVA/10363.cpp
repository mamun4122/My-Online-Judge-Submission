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
int arr[3][3];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    getI(n);
    string s;
    while(n--)
    {
        int zero=0,one=0;
        for(int i=0; i<3; i++)
        {
            cin>>s;
            //debug(s);
            for(int j=0; j<3; j++)
            {
                if(s[j]=='O')
                {
                    arr[i][j]=0;
                    zero++;
                }
                else if(s[j]=='X')
                {
                    arr[i][j]=1;
                    one++;
                }
                else arr[i][j]=-1;
            }

        }
        if(zero>one||one-zero>1)
        {
            printf("no\n");
            continue;
        }
        int cntz=0,cnto=0;
        for(int i=0; i<3; i++)
        {
            int flgz=1,flgo=1;
            for(int j=0; j<3; j++)
            {
                if(arr[i][j]==-1)
                {
                    flgz=0;
                    flgo=0;
                }
                else if(arr[i][j])
                    flgz=0;
                else
                    flgo=0;
            }
            if(flgz)cntz++;
            if(flgo)cnto++;
        }
        for(int j=0; j<3; j++)
        {
            int flgz=1,flgo=1;
            for(int i=0; i<3; i++)
            {
                if(arr[i][j]==-1)
                {
                    flgz=0;
                    flgo=0;
                }
                else if(arr[i][j])
                    flgz=0;
                else
                    flgo=0;
            }
            if(flgz)cntz++;
            if(flgo)cnto++;
        }
        //debug(cntz,cnto,zero,one);

        int flgz=1,flgo=1;
        for(int i=0,j=0; i<3; i++,j++)
        {
            if(arr[i][j]==-1)
            {
                flgz=0;
                flgo=0;
            }
            else if(arr[i][j])
                flgz=0;
            else
                flgo=0;
        }

        if(flgz)cntz++;
        if(flgo)cnto++;
        flgz=1,flgo=1;
        for(int i=0,j=2; i<3; i++,j--)
        {
            if(arr[i][j]==-1)
            {
                flgz=0;
                flgo=0;
            }
            else if(arr[i][j])
                flgz=0;
            else
                flgo=0;
        }
        if(flgz)cntz++;
        if(flgo)cnto++;
        if(cntz&&cnto)
        {
            printf("no\n");
            continue;
        }
        if(cntz&&(one>zero))
        {
            printf("no\n");
            continue;
        }
        if(cnto&&(one==zero))
        {
            printf("no\n");
            continue;
        }
        printf("yes\n");
    }


    return 0;
}


