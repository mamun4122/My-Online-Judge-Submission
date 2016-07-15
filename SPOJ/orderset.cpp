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

// jodi proti ber 1 ta value update korte hoi dn eita use kora better

#define mx 200001
map<int,int> mp;
struct info
{
    int val,actv;
} tree[mx*3];;


int query(int node,int b,int e,int i)
{
    //debug(b,e,i)
    // if (i > e || j < b)	return 0;
    if (b ==e) return tree[node].val;
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int res;
    debug("mid",tree[Left].actv,tree[mid].actv,tree[Right].actv,i);
    if(i<=tree[Left].actv)
        res=query(Left,b,mid,i);
    else
        res=query(Right,mid+1,e,i-tree[Left].actv);
    return res;
}
int count_nm(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)	return 0;
    if (b >= i && e <= j) return tree[node].actv;
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=count_nm(Left,b,mid,i,j);
    int p2=count_nm(Right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue,int org)
{
    if (i > e || i < b)	return;
    if (b >= i && e <= i)
    {
        if(newvalue==-1&&tree[node].actv)
        {
            tree[node].actv=0;
        }
        else if(newvalue==1)
            tree[node].actv=newvalue;
        tree[node].val=org;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue,org);
    update(Right,mid+1,e,i,newvalue,org);
   // debug("l",tree[Left].actv,tree[Right].actv);
    tree[node].actv=tree[Left].actv+tree[Right].actv;
}
struct data
{
    int val;
    char x;


}in[mx];
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    getI(n);
    CLR(tree);
    getchar();
    char y;
    int x;
    //vector<data> in;
    //set<int> s;
    int num[n];
    for(int i=0; i<=n; i++)
    {
        scanf("%c %d\n",&in[i].x,&in[i].val);
        //in.push_back(data(x,y));
        //s.insert(x);
        num[i]=in[i].val;
    }
    int cnt=1;
    sort(num,num+n);
//    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
//    {
//
//        mp[*it]=cnt++;
//        //inv[cnt-1]=*it;
//        //debug(*it,mp[*it]);
//    }
    for(int i=0;i<n;i++)
        mp[num[i]]=i+1;
    cnt=n+1;
    debug("\n\n");
    //int len=in.size();
    for(int i=0; i<n; i++)
    {
        //debug(in[i].x,in[i].val);
        if(in[i].x=='I')
        {
            update(1,1,cnt-1,mp[in[i].val],1,in[i].val);
            // debug(tree[1]);
        }
        else if(in[i].x=='D')
        {
            //debug(tree[1].actv);
            update(1,1,cnt-1,mp[in[i].val],-1,in[i].val);
            debug(tree[1].actv);
        }
        else if(in[i].x=='K')
        {
            //debug(tree[1].actv);
            if(in[i].val>tree[1].actv)
                puts("invalid");
            else
            {
                int res=query(1,1,cnt-1,in[i].val);
                //debug(res)
                printf("%d\n",res);
            }
        }
        else
        {
            //debug()
            int res=count_nm(1,1,cnt-1,1,mp[in[i].val]-1);
            printf("%d\n",res);

        }
    }

    return 0;
}


