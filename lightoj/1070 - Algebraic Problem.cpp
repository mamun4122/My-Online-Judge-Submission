#include <cassert>
#include <cctype>
#include <climits>
//#include <cmath>
#include <math.h>
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
struct matrix
{
    ull v[5][5];
    int row, col; // number of row and column
};
long long MOD = pow(2,64);

// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b)
{
    //assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ull sum = 0;
            for (int k = 0; k < 2;  k++)
            {
//                sum += ((a.v[i][k]%MOD) * (b.v[k][j]%MOD))%MOD;
//                sum %= MOD;
                sum+=a.v[i][k]*b.v[k][j];
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

// returns mat^p
matrix power(matrix mat, int p)
{
    assert(p >= 1);
    if (p == 1) return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));

    else
    {
        matrix ret = power(mat, p / 2);
        return multiply(ret, ret);
    }
    //return ret;
}

int main()
{
    //READ("in.txt");
    int tcase;
    int p, q, n;

    getI(tcase);
    for(int cs=1; cs<=tcase; cs++)
    {

        // input routine
        getIII(p,q,n);

        // preparing the matrix
        matrix mat;
        mat.row = mat.col = 2;
        mat.v[0][0] = p;
        mat.v[0][1] = -q;
        mat.v[1][0] = 1;
        mat.v[1][1] = 0;

        printf("Case %d: ",cs);

        if (n < 2)
        {
            if (n == 0) cout << "2" << endl;
            if (n == 1) cout << p << endl;
            //if (n == 2) cout << (a+b) % MOD << endl;
        }
        else
        {
            mat = power(mat, n - 1);
            //ull ans = ((p * mat.v[0][0])%MOD + (2 * mat.v[0][1])%MOD)%MOD;
            //ans %= MOD;
            ull ans=p*mat.v[0][0]+2*mat.v[0][1];
            cout << ans << endl;
        }
    }
    return 0;
}


