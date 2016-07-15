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

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)


#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
char a[1000010],b[100],c[100];

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    //printf("%d",'Z');
    map<char,char> m;
    m['A']='V';m['B']='W';m['C']='X';m['D']='Y';m['E']='Z';m['F']='A';m['G']='B';m['H']='C';m['I']='D';m['J']='E';m['K']='F';m['L']='G';m['M']='H';m['N']='I';m['O']='J';
    m['P']='K';m['Q']='L';m['R']='M';m['S']='N';m['T']='O';m['U']='P';m['V']='Q';m['W']='R';m['X']='S';m['Y']='T';m['Z']='U';
    while(1)
    {
        gets(b);
        if(strcmp(b,"START")!=0)break;
        gets(a);
        for(int i=0;a[i]!='\0';i++)
        {

            if(a[i]>=65&&a[i]<91)
            {
                printf("%c",m[a[i]]);
            }
            else
                printf("%c",a[i]);
        }
        printf("\n");
        gets(c);


    }
    return 0;
}


