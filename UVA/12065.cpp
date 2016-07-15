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
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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
#define M 1111111
bool marked[M+1];
vector <int> primes;

void sieve(int n) {
	primes.push_back(2*9);
	CLR(marked);
	for (int i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			//primes.push_back(i);
			for (int j = i * i; j <= n; j += i + i) {
				marked[j] = 1;
		}
    }
  }
  for(int i=3;i<=M;i+=2)
  {
      if(!marked[i])
        primes.push_back(i*9);
  }

}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    sieve(M);
    sort(ALL(primes));
    int i,j,t,cs,n,m;
    int p,q,x,y;
    getI(t);
    rep(cs,t)
    {
        getII(x,y);
        p=min(x,y);
        q=max(x,y);
        vector<int> v;
        int ans=0;
        for(int i=p;i<=q;i++)
        {
            int tmp=i;
            //debug(tmp)
            while(tmp!=0)
            {
                v.push_back(tmp%10);
                tmp/=10;
            }
            sort(ALL(v));
          //  debug("sz",v.size())
            do
            {
                int temp=0;
                for(int j=0;j<v.size();j++)
                    temp=temp*10+v[j];
                //debug(temp);
                if(binary_search(ALL(primes),abs(temp-i)))
                {
                    ans++;
                    break;
                }

            }while(next_permutation(v.begin(),v.end()));
            v.clear();
        }
        printf("Case %d: %d\n",cs,ans);
    }




    return 0;
}


