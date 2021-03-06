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
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define    debug(a)     { cout << a <<endl; }

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)


#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld   long double


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

int a[105][105];
int b[105][105];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n,m;
    getII(n,m);
    CLR(b);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            getI(a[i][j]);
        }
    }
    bool flag=true,flag2,flag3,flag4=true,flag5=false;
    for(int i=1; i<=n; i++)
    {
        //flag2=true;flag3=true;
        for(int j=1; j<=m; j++)
        {
            flag2=true;
            flag3=true;
            if(a[i][j]==1)
            {
                flag5=true;
                for(int k=1; k<=max(n,m); k++)
                {
                    if(k<=m)
                        if(a[i][k]!=1)flag2=false;
                    if(k<=n)
                        if(a[k][j]!=1)flag3=false;
                }
                if((!flag2)&&(!flag3))flag=false;
                if(flag2&&flag3){b[i][j]=1;flag4=false;}
            }
        }
    }
    if(!flag||(flag4&&flag5))cout<<"NO"<<endl;
    else
    {
        /*for(int i=1; i<=n; i++)
        {
            //flag2=true;flag3=true;
            for(int j=1; j<=n; j++)
            {
                flag2=true;
                flag3=true;
                if(a[i][j]==1)
                {
                    for(int k=1; k<=n; k++)
                    {
                        if(a[i][k]!=1)flag2=false;
                        if(a[k][j]!=1)flag3=false;
                    }
                    if(flag2&&flag3)b[i][j]=1;
                }
            }
        }*/
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++)
        {
            //flag2=true;flag3=true;
            for(int j=1; j<=m; j++)
            {
                cout<<b[i][j];
                if(j!=m)cout<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}