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
int StringToNumber ( string Text )//Text not by const reference so that the function can be used with a
{
    //character array as argument
    stringstream ss(Text);
    int result;
    return ss >> result ? result : 0;
}
int tc;
int tot;
vector<int>lft,rght;
ll dp[20][2][2][2][10][2];
ll  call(int pos,int flag,int boro,int zero,int siz,int type)
{
//    debug(pos)
    if(pos==tot)return 1;
    ll &ret = dp[pos][flag][boro][zero][siz][type];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0&&pos<siz)
    {
//        debug("")
        for(int i=lft[pos]; i<=rght[pos]; i++)
        {
//            if(i<lft[pos])continue;
            ans|=call(pos+1,i==rght[pos],i>lft[pos],i!=0,siz,type);
            if(ans)return ret=ans;
        }
    }
    else if(pos<siz)
    {
        if(flag)
        {
            repI(i,rght[pos]+1)
            {
                if(boro)
                    ans|=call(pos+1,i==rght[pos],1,zero||(i!=0),siz,type);
                else if(i>=lft[pos])
                    ans|=call(pos+1,i==rght[pos],i>lft[pos],zero||(i!=0),siz,type);
                else continue;
                if(ans)return ret=ans;
            }

        }
        else
        {
            repI(i,10)
            {
                if(boro)
                    ans|=call(pos+1,0,1,zero||(i!=0),siz,type);
                else if(i>=lft[pos])
                    ans|=call(pos+1,0,i>lft[pos],zero||(i!=0),siz,type);
                else continue;
                if(ans)return ret=ans;
            }
        }
    }
    else if(pos==siz&&type==1)
    {
//        debug(pos)
        if(flag)
        {
            int i=5;
            if(boro&&i<=rght[pos])
                ans|=call(pos+1,i==rght[pos],1,zero||(i!=0),siz,type);
            else if(i>=lft[pos]&&i<=rght[pos])
                ans|=call(pos+1,i==rght[pos],i>lft[pos],zero||(i!=0),siz,type);
//            else continue;
            if(ans)return ret=ans;
            //            }

        }
        else
        {
            int i=5;
            if(boro&&i<=rght[pos])
                ans|=call(pos+1,0,1,zero||(i!=0),siz,type);
            else if(i>=lft[pos]&&i<=rght[pos])
                ans|=call(pos+1,0,i>lft[pos],zero||(i!=0),siz,type);
//            else continue;
            if(ans)return ret=ans;

        }

    }
    else
    {
//        debug(pos)
        if(flag)
        {
            int i=0;
            if(boro&&i<=rght[pos])
                ans|=call(pos+1,i==rght[pos],1,zero||(i!=0),siz,type);
            else if(i>=lft[pos]&&i<=rght[pos])
                ans|=call(pos+1,i==rght[pos],i>lft[pos],zero||(i!=0),siz,type);
//            else continue;
            if(ans)return ret=ans;
            //            }

        }
        else
        {
            int i=0;
            if(boro)
                ans|=call(pos+1,0,1,zero||(i!=0),siz,type);
            else if(i>=lft[pos])
                ans|=call(pos+1,0,i>lft[pos],zero||(i!=0),siz,type);
//            else continue;
            if(ans)return ret=ans;

        }

    }
    return ret=ans;

}
void calc(int n,int m)
{
    lft.clear();
    rght.clear();
    while(n)
    {
        lft.push_back(n%10);
        n/=10;
    }
    while(m)
    {
        rght.push_back(m%10);
        m/=10;
    }
    while(lft.size()<rght.size())lft.push_back(0);
    reverse(ALL(lft));
    reverse(ALL(rght));
    tot=lft.size();
//    debug(tot);
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        string st;
        cin>>st;
        int sz=st.size();
        int num=StringToNumber(st);
        ROF(i,sz-1,0)
        {
            if(st[i]!='0')break;
            sz--;
        }
        int c;
        if(st[sz-1]=='5')c=sz*2-1;
        else c=sz*2;
        bool absurd=false;
        int low=ceil((double)num*.95),high=floor((double)num*1.05);
        debug(low,high,c,sz)

        calc(low,high);
        if(c%2==0)
        {
            ///sz er cheye choto banabo
            SET(dp);
            int ans=call(0,0,0,0,sz-1,0);
            if(ans)
            {
                puts("absurd");
                continue;
            }
//            debug("1 fail")
            ///sz er soman banabo last e 5 rakbo
            SET(dp);
            ans=call(0,0,0,0,sz-1,1);
            if(ans)
            {
                puts("absurd");
                continue;
            }
//            debug("2 fail")
        }
        else
        {
            ///sz er cheya choto banabo
            SET(dp);
            int ans=call(0,0,0,0,sz-1,0);
            if(ans)
            {
                puts("absurd");
                continue;
            }
        }
        puts("not absurd");
    }



    return 0;
}

