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

#define    debug(a)     { cout << a <<endl; }

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)


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


int main()
{
   // READ("in.txt");
    //WRITE("out.txt");
    string arr[4]= {"pushLeft","pushRight","popLeft","popRight"};
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        deque<int> q;
        int n,m;
        printf("Case %d:\n",cs);
        getII(n,m);
        string a;
        int x,qry;
        for(int i=1; i<=m; i++)
        {
            cin>>a;
            //debug(a);
            for(int j=0; j<4; j++)
            {
                if(a.compare(arr[j])==0)
                {
                    qry=j+1;
                    break;
                }
            }
            //debug(qry);
            if(qry==1)
            {
                cin>>x;
                getchar();
                if(q.size()==n)
                {
                    printf("The queue is full\n");
                }
                else
                {
                    q.push_front(x);
                    printf("Pushed in left: %d\n",x);
                }
            }
            else if(qry==2)
            {
                cin>>x;
                getchar();
                if(q.size()==n)
                {
                    printf("The queue is full\n");
                }
                else
                {
                    q.push_back(x);
                    printf("Pushed in right: %d\n",x);
                }

            }
            else if(qry==3)
            {
                //printf("#\n");
                getchar();
                if(q.empty())
                    printf("The queue is empty\n");
                else
                {
                    x=q.front();
                    q.pop_front();
                    printf("Popped from left: %d\n",x);
                }
            }
            else
            {
                getchar();
                if(q.empty())
                    printf("The queue is empty\n");
                else
                {
                    x=q.back();
                    q.pop_back();
                    printf("Popped from right: %d\n",x);
                }
            }
        }

    }

    return 0;
}



