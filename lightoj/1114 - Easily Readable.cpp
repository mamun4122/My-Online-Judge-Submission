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
#define mamun
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
/*
struct node
{
    bool endmark;
    node *next[52];
    int temp;
    node()
    {
        temp=0;
        endmark=0;
        for(int i=0; i<52; i++)
            next[i]=NULL;
    }
}*root;
int indx(char c)
{
    if(c>='A' && c<='Z')
        return c-'A';
    else return c-'a'+26;
}
void insert(char *str,int len)
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=indx(str[i]);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;
    curr->temp++;

}

int search(char *str,int len)
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=indx(str[i]);
        if(curr->next[id]==NULL) return 0;
        curr=curr->next[id];
    }
    if(curr->endmark)return curr->temp;
    else return 0;

}

void del(node *cur)				// send root here
{
    for(int i=0; i<52; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}*/

char sntnce[11111];
char tmp[11111];
char str[11111];

int main()
{

    //READ("in.txt");
    //WRITE("out.txt");
    //node *root;
    int t;
    getI(t);
    map<string,int> m;
    for(int cs=1; cs<=t; cs++)
    {
        int res=1;
        //root=new node();
        int num_word;
        getI(num_word);
        //string a;
        int len;
        for(int i=1; i<=num_word; i++)
        {
            //char str[101];
            scanf("%s",str);
            len=strlen(str);
            if(len>2)
            sort(str+1,str+len-1);
            m[str]++;
            //debug(str);
            //insert(str,len);
        }
        printf("Case %d:\n",cs);

        int n;
        getI(n);
        getchar();
        //debug(n);

        while(n--)
        {

            res=1;
            gets(sntnce);
           // debug(sntnce);
            char *p;
            p=strtok(sntnce," ");
            while(p!=NULL)
            {

                strcpy(tmp,p);
                len=strlen(tmp);
                if(len>2)
                sort(tmp+1,tmp+len-1);
                //debug(p);
                if(m.find(tmp)!=m.end())
                res*=m[tmp];
                else res=0;
                p=strtok(NULL," ");
            }
            printf("%d\n",res);
        }
        //del(root);
        m.clear();
    }
    return 0;
}


