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

#define ALL(p) p.begin(),p.end()
#define mem(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    scanf("%d",&t);
    long long a,x,y,c,d,n;
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&a);
        c=ceil(sqrt(a));
        //cout<<c<<endl;
        x=y=c;
        d=(c*c)-c+1;
        //cout<<d<<endl;
        n=max(a,d)-min(a,d);
        if(a>d)
        {
            x=c-n;
        }
        else
            y=c-n;
        if(c%2==0)swap(x,y);
        printf("Case %d: %lld %lld\n",i,x,y);
    }

    return 0;
}
