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
#define mam
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


int main()
{
     //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        int ans=0;
        string a,b;
        cin>>a>>b;
        //debug(a,b);
        if(a.size()!=b.size())ans=-1;
        if(ans==-1)
        {
            printf("Case %d: %d\n",cs,ans);
            continue;
        }
        int len1,len2;
        len1=a.size();
        len2=b.size();
        int zero1=0,one1=0,zero2=0,one2=0,ques=0;
        /*for(int i=0;i<len1;i++)
        {
            if(b[i]=='0')zero2++;
            else one2++;
            if(a[i]=='0')zero1++;
            else if(a[i]=='1')one1++;
            else ques++;
        }
        if(zero1<zero2)
        {
            int dif=zero2-zero1;
            if(dif>ques)ans=-1;
            else ques-=dif;
        }
        if(ans==-1)
        {
             printf("Case %d: %d\n",cs,ans);
             continue;
        }
        //debug("mam");
        int dif1=zero1-zero2;
        dif1+=ques;
        if(dif1+one1==one2)ans=-1;
        if(ans==-1)
        {
             printf("Case %d: %d\n",cs,ans);
             continue;
        }
        */
        for(int i=0; i<len1; i++)
        {
            if(a[i]=='1')one1++;
            if(b[i]=='1')one2++;

        }
        if(one1>one2)ans=-1;
        if(ans!=-1)
        {
            for(int i=0; i<len1; i++)
            {
                if(a[i]=='?')
                {
                    if(b[i]=='0')
                        a[i]=b[i];
                    else if(b[i]=='1'&&one1+1<=one2)
                     {
                         a[i]=b[i];one1++;
                     }
                    else
                        a[i]='0';
                    ans++;
                }
            }
        }
        for(int i=0; i<len1; i++)
        {
            if(ans==-1)break;
            if(a[i]!=b[i]&&a[i]=='0')
            {
                bool ok=false;
                for(int j=i+1; j<len1; j++)
                {
                    if(a[j]!=b[j]&&a[j]=='1')
                    {
                        ok=true;
                        swap(a[i],a[j]);
                        ans++;
                        break;
                    }
                }
                if(!ok)
                {
                    ans++;
                    a[i]=b[i];
                }
            }
            if(a[i]!=b[i]&&a[i]=='1')
            {
                bool ok=false;
                for(int j=i+1; j<len1; j++)
                {
                    if(a[j]!=b[j]&&a[j]=='0')
                    {
                        ok=true;
                        swap(a[i],a[j]);
                        ans++;
                        break;
                    }
                }
                if(!ok)ans=-1;
            }
        }
        if(a.compare(b)!=0)ans=-1;
        printf("Case %d: %d\n",cs,ans);
    }


    return 0;
}


