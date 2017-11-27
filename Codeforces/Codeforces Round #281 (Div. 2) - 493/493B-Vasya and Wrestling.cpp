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
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    getI(n);
    ll x;
    vector<ll> v1,v2;
    ll ans1=0,ans2=0;
    while(n--)
    {
        getL(x);
        if(x>0)
        {
            ans1+=x;
            v1.push_back(x);
        }
        else
        {
            ans2+=(abs(x));
            v2.push_back(abs(x));
        }
    }
    if(ans1>ans2)
        printf("first\n");
    else if(ans2>ans1)
        printf("second\n");
    else
    {
        int flag=0;
        //sort(ALL(v1));
        //sort(ALL(v2))
        int i;
        for(i=0; i<v1.size()&&i<v2.size(); i++)
        {
            if(v1[i]>v2[i])
            {
                printf("first\n");
                flag=1;
                break;
            }
            else if(v2[i]>v1[i])
            {
                printf("second\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(i<v2.size())
                printf("second\n");
            else if(i<v1.size())
                printf("first\n");
            else if(x>0)
                printf("first\n");
            else
            printf("second\n");

        }
    }
    return 0;
}