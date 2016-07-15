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
int arr[5][5],ans;
int target[5][5]={{1,1,1,1,1},
                {0,1,1,1,1},
                {0,0,2,1,1},
                {0,0,0,0,1},
                {0,0,0,0,0},
                };
int dirx[] = { -1, -1, 1, 1, -2, -2, 2, 2 };
int diry[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
bool ok(int x,int y)
{
    if(x>=0&&x<5&&y>=0&&y<5)return true;
    return false;
}


bool correct()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(arr[i][j]!=target[i][j])return false;
    return true;
}

void solve(int curx,int cury,int sum,int prevx,int prevy)
{
    if(sum>10)return;
    if(curx==2&&cury==2&&correct())ans=min(ans,sum);
    for(int i=0;i<8;i++)
    {
        int tmpx=curx+dirx[i];
        int tmpy=cury+diry[i];
        if(ok(tmpx,tmpy)&&(tmpx!=prevx||tmpy!=prevy))
        {
            swap(arr[tmpx][tmpy],arr[curx][cury]);
            solve(tmpx,tmpy,sum+1,curx,cury);
            swap(arr[tmpx][tmpy],arr[curx][cury]);

        }
    }
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    getchar();
    while(t--)
    {
        ans=INF;
        int initx,inity;
        CLR(arr);
        for(int i=0;i<5;i++)
        {
            string s;
            getline(cin,s);
            //debug(s);
            for(int j=0;j<5;j++)
            {
                if(s[j]=='0')arr[i][j]=0;
                else if(s[j]=='1')arr[i][j]=1;
                else
                {
                    arr[i][j]=2;
                    initx=i;inity=j;
                }
            }
        }
        solve(initx,inity,0,-1,-1);
        //debug(initx,inity,ans);
        if(ans>10)
            printf("Unsolvable in less than 11 move(s).\n");
        else
            printf("Solvable in %d move(s).\n",ans);

    }


    return 0;
}


