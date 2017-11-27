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
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long


typedef long long int L;
inline int nxt()
{
    int a;
    scanf("%d",&a);
    return a;
}
inline L NXT()
{
    L a;
    scanf("%lld",&a);
    return a;
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
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
int powe(int num,int e)
{
    int ans=1;
    rep(i,e)ans*=num;
    return ans;
}
ll dp[30][30];
string  faltu;
ll call(int pos,int prev)
{
    ll &ret=dp[pos][prev];
    if(pos==faltu.size())
    {
        return ret=1;
    }
    if(ret!=-1)return ret;
    ret=0;
    repI(i,26)
    {
        ret+=call(pos+1,i);
    }
    return ret;
}
//string col;
int colval;
void print(int pos,int prev)
{
    if(pos==faltu.size())
    {
        colval++;
        return;
    }
    int val=faltu[pos]-'A';
    repI(i,val)colval+=dp[pos+1][i];
    print(pos+1,val);
}
int mark[30][30];
ll dp1[30][30];
int cc=1,tmplen;
ll call1(int pos,int prev)
{
    ll &ret=dp1[pos][prev];
    int &vis=mark[pos][prev];
    if(pos==tmplen)
    {
        return ret=1;
    }
    if(vis==cc)return ret;
    vis=cc;
    ret=0;
    repI(i,26)
    {
        ret+=call1(pos+1,i);
    }
    return ret;
}

string colans;
void print1(int pos,int prev)
{
    if(pos==tmplen)
    {
        return;
    }
    repI(i,26)
    {
        if(dp1[pos+1][i]>=colval)
        {
            colans+=(char)i+'A';
            print1(pos+1,i);
            break;
        }
        else colval-=dp1[pos+1][i];
    }
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
        string s;
        cin>>s;
        int type = 0;
        int len = s.length();
        if(s[0]!='R') type = 2;
        else
        {
            bool num= false;
            for(int i =0; i<len; i++)
            {
                if(s[i]>='0'&& s[i]<='9') num = true;
                else if(s[i]=='C' && num)
                {
                    type = 1;
                    break;
                }
            }
            if(type == 0) type = 2;
        }
        // cout<<c<<endl;
        if(type==2)
        {
            string r;
            string c;
            for(int i= 0; i<len; i++)
            {
                if(s[i]>='A'&& s[i]<='Z') c.PB(s[i]);
                else r.PB(s[i]);
            }
            colval=0;
            faltu=c;
            SET(dp);
            call(0,0);
            print(0,0);
            rep(i,faltu.size()-1)
            {
                colval+=powe(26,i);
            }
            printf("R%sC%d\n",r.c_str(),colval);
        }
        else
        {
            int row=0,coltmp=0,flag=1;
            repI(i,len)
            {
                if(flag&&isdigit(s[i]))
                {
                    row*=10;
                    row+=s[i]-'0';
                }
                else if(s[i]=='C')flag=0;
                if(isdigit(s[i])&&flag==0)
                {
                    coltmp*=10;
                    coltmp+=s[i]-'0';
                }
            }
            rep(i,100)
            {
                cc++;
                tmplen=i;
//                debug(tmplen,coltmp)
//                debug(call1())
                if(call1(0,0)>=coltmp)
                {
                    colval=coltmp;
                    colans="";
                    print1(0,0);
                    break;
                }
                else
                {
                    coltmp-=call1(0,0);
                }
            }
//            debug(tmplen)
            printf("%s%d\n",colans.c_str(),row);
//            debug(row,coltmp);
        }
    }
    return 0;
}