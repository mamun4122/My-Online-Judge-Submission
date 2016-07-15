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

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

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
char arr[1000005];
string st;

bool palindrome(string st)
{
    int len=st.size();
    for(int i=0,j=len-1; i<=j; i++,j--)if(st[i]!=st[j])return false;
    return true;
}
bool check(string st)
{
    int len=st.size();
    repI(i,len)if(st[i]>arr[i])return true;
    else if(st[i]<arr[i])return false;
    return false;
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    getchar();
    rep(cs,t)
    {
        gets(arr);
        int len = strlen(arr);
        string tmp,mid;
        st="";
        repI(i,len/2)st+=arr[i];
        tmp="";
        repI(i,len/2)tmp+=arr[i];
        reverse(ALL(tmp));
        mid="";
        if(len%2!=0)mid=arr[len/2];
        if(check(st+mid+tmp))
        {
            string ans=st+mid+tmp;
            printf("%s\n",ans.c_str());
//            debug("")
        }
        else
        {
            string ans=st+mid+tmp;
//            debug(ans)
            int flag=0;
            int suru=len/2;
            if(len%2==0)suru--;
//            debug(suru)
            for(int i=suru; i>=0; i--)
            {
                if(ans[i]<'9')
                {
                    ans[i]++;
                    ans[len-1-i]=ans[i];
                    for(int j=i+1;j<=suru;j++)
                    {
                        ans[j]='0';
                        ans[len-1-j]='0';
                    }
//                    debug(i,len-1-i)
                    flag=1;
//                    debug("")
                    break;
                }
            }
            if(flag)
            {
                printf("%s\n",ans.c_str());
                continue;
            }
//            int len=ans.size();
            len++;
            st="";
            repI(i,len/2)if(i==0)st+="1";else st+="0";
            tmp="";
            repI(i,len/2)if(i==0)tmp+="1";else tmp+="0";
            reverse(ALL(tmp));
            mid="";
            if(len%2!=0)mid+="0";
            ans=st+mid+tmp;
            printf("%s\n",ans.c_str());


        }

    }


    return 0;
}

