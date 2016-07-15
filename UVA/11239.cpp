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
#include <ctime>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************
int t,n,m;

map<string,int> mp,stdnt;
map<string,string> stdntsbjct;
vector<pair<int,string> >v;
bool cmp(const pair<int, string> &p1, const pair<int, string> &p2)
{
    if(p1.ff!=p2.ff)
        return p1.ff < p2.ff;
    return p1.ss > p2.ss;
}
int main() {
//    READ("in.txt");
    //WRITE("out.txt");
    string s,sbjct;
    int flg=0;
    map<string,int>::iterator it;
//    map<string,string>
    while(getline(cin,s))
    {
        if(isdigit(s[0])&&s[0]=='0')break;
        else if(isdigit(s[0])&&s[0]=='1')
        {
//            debug("*")
            flg=0;
            for(it=stdnt.begin();it!=stdnt.end();it++)
            {
//                debug(it->ff)
                if(it->ss>1)
                {
                    mp[stdntsbjct[it->ff]]--;
                }
            }
            for(it=mp.begin();it!=mp.end();it++)
            {
                v.push_back(make_pair(it->ss,it->ff));
            }
            sort(ALL(v),cmp);
            reverse(ALL(v));

            mp.clear();
            stdnt.clear();
            stdntsbjct.clear();
            repI(i,v.size())
            {
                cout<<v[i].ss<<" "<<v[i].ff<<endl;
            }
            v.clear();
//            debug("*")

        }
        else if(s[0]>='A'&&s[0]<='Z')
        {
//            debug(s)
            mp[s]=0;
            sbjct=s;
        }
        else
        {
//            debug(s)
            if(stdnt[s]!=0)
            {
                if(stdntsbjct[s]!=sbjct)stdnt[s]++;
            }
            if(stdnt[s]==0)
            {
                stdnt[s]++;
                mp[sbjct]++;
                stdntsbjct[s]=sbjct;
            }
        }

    }




    return 0;
}



