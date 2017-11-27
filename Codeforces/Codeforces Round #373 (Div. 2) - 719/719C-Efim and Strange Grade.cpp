#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;

vector<int> age,pore;
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m)
    {
        string s;
        cin>>s;
        age.clear();
        pore.clear();
        int f=0;
        repI(i,s.size())
        {
            if(s[i]=='.')
            {
                f=1;
                continue;
            }
            if(!f)age.push_back(s[i]-'0');
            else pore.push_back(s[i]-'0');
        }
        int pos=-1;
        repI(i,pore.size())
        {
            if(pore[i]>=5)
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            cout<<s<<endl;
            continue;
        }
        int tmp=pos;
        int jog=0;
        for(int i=pore.size()-1; i>=0; i--)
        {
            if(m==0)break;
            if(i>tmp)pore.pop_back();
            else
            {
                if(pore[i]>=5)
                {
                    m--;
                    pore.pop_back();
                    if(pore.size()==0)
                    {
                        i=0;
                        if(age.size()==0)
                        {
                            jog=1;
                        }
                        else
                        {
                            jog=1;
                            for(int j=age.size()-1; j>=0; j--)
                            {
                                age[j]++;
                                if(age[j]==10)
                                {
                                    age[j]=0;
                                }
                                else
                                {
                                    jog=0;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        int biog=1;
                        for(int j=pore.size()-1; j>=0; j--)
                        {
                            pore[j]++;
                            if(pore[j]==10)
                            {
                                pore.pop_back();

                            }
                            else
                            {
                                biog=0;
                                i=j+1;
                                break;
                            }
                        }
                        if(biog)
                        {
                            i=0;
                            jog=1;
                            for(int j=age.size()-1; j>=0; j--)
                            {
                                age[j]++;
                                if(age[j]==10)
                                {
                                    age[j]=0;
                                }
                                else
                                {
                                    jog=0;
                                    break;
                                }
                            }
                        }
                    }
                }
//                else break;
            }
        }
        if(jog)printf("1");
        repI(i,age.size())printf("%d",age[i]);
        if(pore.size())printf(".");
        repI(i,pore.size())printf("%d",pore[i]);
        puts("");

    }


    return 0;
}