#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);

#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);

#define PB(x) push_back(x)

#define FOREACH(i,t) for(typeof(t.begin()) i=t.begin(); i!=t.end();i++)
#define ALL(p) p.begin().p.end()
#define ALLR(p) p.rbegin(),p.rend()

#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p, 0,sizeof(p))

#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d %d",&a,&b)
#define getIII(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define getL(a) scanf("%lld",&a)
#define getLL(a,b) scanf("%lld %lld",&a,&b)
#define getLLL(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define getC(n) scanf("%c",&n)
#define getF(n) scanf("%lf",&n)
#define getS(n) scanf("%s",&n)

#define vi vector <int>
#define vii vector < vector <int> >
#define pii pair <int,int>
#define ff first
#define ss second
#define ll long long

template < class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template < class T > inline T gcd(T a,T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ); }
template < class T > inline T lcm(T a,T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }




int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    string st;
    int ci=1;
    while(getline(cin,st))
    {
        if(st.size()==1 && st[0]=='#') break;
        printf("Case %d: ",ci++);
        if(st.compare("HELLO")==0)
        {
            printf("ENGLISH\n");
        }
        else if(st.compare("HOLA")==0)
        {
            printf("SPANISH\n");
        }
        else if(st.compare("HALLO")==0)
        {
            printf("GERMAN\n");
        }
        else if(st.compare("BONJOUR")==0)
        {
            printf("FRENCH\n");
        }
        else if(st.compare("CIAO")==0)
        {
            printf("ITALIAN\n");
        }
        else if(st.compare("ZDRAVSTVUJTE")==0)
        {
            printf("RUSSIAN\n");
        }
        else
        {
            printf("UNKNOWN\n");
        }
    }

    return 0;
}
