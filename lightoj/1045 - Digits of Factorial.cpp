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
#define ll long long

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
double p[1000010];
void pre()
{
    p[0]=0.00;
    for(int i=1;i<=1000000;i++)
        p[i]=log10(i)+p[i-1];
}
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    pre();
    int t,n,b;
    double res;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        res=0;
        scanf("%d%d",&n,&b);
        res=floor(p[n]/log10(b));
        res+=1;
        printf("Case %d: %.0lf\n",j,res);
    }


    return 0;
}
