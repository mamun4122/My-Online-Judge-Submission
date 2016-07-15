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
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}

int mark[20010];
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    int res=0;

    for(int cs=1; cs<=t; cs++)
    {
        res=0;
        set<int> st;
        vector<int> v[20010];
        CLR(mark);
        int x;
        getI(x);
        int a,b;
        for(int i=1; i<=x; i++)
        {
            getII(a,b);
            st.insert(a);
            st.insert(b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        set<int>::iterator it;
        int n=st.size();
        int cnt=0;
        queue<int> q;
        int u,ans1=0,ans2=0;
        //q.push(st[0]);
        while(1)
        {
            res+=max(ans1,ans2);
            ans1=0;ans2=0;
            for(it=st.begin();it!=st.end();it++)
            {
                //cout<<mark[*it]<<endl;
                if(mark[*it]==0){
                    q.push(*it);
                mark[*it]=1;
                ans1++;
                break;
                }
            }
            if(q.empty())break;
            //mark[u]=1;
            while(!q.empty())
            {
                u=q.front();
                //cnt++;
                //cout<<u<<endl;
                q.pop();
                for(int i=0;i<v[u].size();i++)
                {
                    if(mark[v[u][i]]==0)
                    {
                        if(mark[u]==1){
                            mark[v[u][i]]=2;ans2++;}
                        else{
                            mark[v[u][i]]=1;ans1++;}
                        q.push(v[u][i]);
                    }
                }

            }
        }
        printf("Case %d: %d\n",cs,res);
    }

    return 0;
}


