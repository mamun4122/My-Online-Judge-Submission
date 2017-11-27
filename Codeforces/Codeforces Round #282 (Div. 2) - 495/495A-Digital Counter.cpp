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
#define    getII(a,b)        scanf("%d%d", &a, &b)
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

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
//int a[10];
vector<int> a[10];

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int x;
    getI(x);
    int c=x%10;
    int d=x/10;
    set<int> st;
    //a[0]=1;
    a[0].push_back(0);
   a[0].push_back(8);
   a[1].push_back(1);
    a[1].push_back(0);
    a[1].push_back(3);
    a[1].push_back(4);
    a[1].push_back(7);
    a[1].push_back(8);
    a[1].push_back(9);
    //a[1]=6;
    //a[2]=1;
    a[2].push_back(2);
    a[2].push_back(8);
    //a[3]=2;
    a[3].push_back(3);
    a[3].push_back(8);
    a[3].push_back(9);
    a[4].push_back(9);
    a[4].push_back(8);
    a[4].push_back(4);
    //a[5]=3;
    a[5].push_back(5);
    a[5].push_back(6);
    a[5].push_back(8);
    a[5].push_back(9);
    //a[6]=1;
    a[6].push_back(8);
    a[6].push_back(6);
    //a[7]=4;
    a[7].push_back(8);
    a[7].push_back(7);
    a[7].push_back(9);
    a[7].push_back(0);
    a[7].push_back(3);
    //a[8]=0;
    a[8].push_back(8);
    //a[9]=1;
    a[9].push_back(8);
    a[9].push_back(9);
    //printf("%d\n",(a[c]+1)*(a[d]+1));
    for(int i=0;i<a[d].size();i++)
    {
        for(int j=0;j<a[c].size();j++)
        {
            int f=(a[d][i]*10)+a[c][j];
            st.insert(f);
        }
    }
    printf("%d\n",st.size());

    return 0;
}