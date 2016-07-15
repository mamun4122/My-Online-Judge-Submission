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

#define iseq(a,b) (fabs(a-b)<EPS)

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
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
map<char, string> ctm;

void populate(){
    ctm.insert(make_pair('A',".-"));
    ctm.insert(make_pair('B',"-..."));
    ctm.insert(make_pair('C',"-.-."));
    ctm.insert(make_pair('D',"-.."));
    ctm.insert(make_pair('E',"."));
    ctm.insert(make_pair('F',"..-."));
    ctm.insert(make_pair('G',"--."));
    ctm.insert(make_pair('H',"...."));
    ctm.insert(make_pair('I',".."));
    ctm.insert(make_pair('J',".---"));
    ctm.insert(make_pair('K',"-.-"));
    ctm.insert(make_pair('L',".-.."));
    ctm.insert(make_pair('M',"--"));
    ctm.insert(make_pair('N',"-."));
    ctm.insert(make_pair('O',"---"));
    ctm.insert(make_pair('P',".--."));
    ctm.insert(make_pair('Q',"--.-"));
    ctm.insert(make_pair('R',".-."));
    ctm.insert(make_pair('S',"..."));
    ctm.insert(make_pair('T',"-"));
    ctm.insert(make_pair('U',"..-"));
    ctm.insert(make_pair('V',"...-"));
    ctm.insert(make_pair('W',".--"));
    ctm.insert(make_pair('X',"-..-"));
    ctm.insert(make_pair('Y',"-.--"));
    ctm.insert(make_pair('Z',"--.."));
}
string decode(string s){
    int size = s.size();
    string ret = "";
    for (int i=0;i<size;i++){
        ret+=(ctm.find(s[i])->second);
    }
    //printf("INS: %s\n", ret.c_str());
    return ret;
}
#define mx 2
struct node
{
    int endmark;
    node *next[mx+1];
    node()
    {
        endmark=0;
        for(int i=0; i<mx; i++)
			next[i]=NULL;
    }
}*root;

string input;
void insert(string str,int len)
{
    node *curr=root;
    //debug(str,len);
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'-';
        //debug(id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        //debug("*");
    }
    curr->endmark++;

}
int search(string str,int pos,int len)
{
    node *curr=root;
    for(int i=pos; i<=len; i++)
    {
        int id=str[i]-'-';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->endmark;			// returns 1 or 0

}
ll dp[10010];
ll result(int pos)
{
    //debug(pos);
    if(dp[pos]!=-1)return dp[pos];
    ll ans=0,temp=0;
    int sz=input.size();
    if(pos==sz)return dp[pos]=1;
    for(int i=pos;i<sz&&i<pos+85;i++)
    {
        int tmp=search(input,pos,i);
        if(tmp)
            ans+=result(i+1)*tmp;

    }
    //debug(ans);
    return dp[pos]=ans;
}

void del(node *cur)				// send root here
{
    for(int i=0; i<mx; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");
    //printf("%d%d",'.','-');
    populate();
    int t;
    getI(t);
    while(t--)
    {
        SET(dp);
        root=new node();
        cin>>input;
        int n;
        getI(n);
        string x;
        while(n--)
        {
            cin>>x;
            x=decode(x);
           //debug(x);
            insert(x,x.size());
        }

        printf("%lld\n",result(0));

        del(root);
    }




    return 0;
}

//1496317952
