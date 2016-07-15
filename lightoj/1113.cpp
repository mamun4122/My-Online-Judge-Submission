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
#define    debugI()     { cout << "*" <<endl; }

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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    string arr[4]={"VISIT","BACK","FORWARD","QUIT"};
    string a,b;
    stack<string> st1,st2;
    int t;
    cin>>t;
    int qry;
    for(int cs=1;cs<=t;cs++)
    {
        string cur("http://www.lightoj.com/");
        printf("Case %d:\n",cs);
        while(1){
        cin>>a;
        //debug(a);
        for(int i=0;i<4;i++)
        {
            if(a.compare(arr[i])==0)
            {
                qry=i;break;
            }
        }
        if(qry==0)
        {
            cin>>b;
            st1.push(cur);
            cur=b;
            cout<<cur<<endl;
            while(!st2.empty())st2.pop();
           // debug(b);
        }
        else if(qry==1)
        {
            if(st1.empty())
                cout<<"Ignored\n";
            else
            {
                st2.push(cur);
                cur=st1.top();st1.pop();
                debug(cur);
            }
        }
        else if(qry==2)
        {
            if(st2.empty())
                cout<<"Ignored\n";
            else
            {
                st1.push(cur);
                cur=st2.top();st2.pop();
                debug(cur);
            }
        }
       // cout<<endl;
        else if(qry==3)break;
        }
        while(!st1.empty())st1.pop();
        while(!st2.empty())st2.pop();

    }

    return 0;
}


