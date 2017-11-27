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

struct data
{
    int x,y;
};
data a[5010];
bool cmp(const data &a,const data &b)
{
    if(a.x<b.x)return true;
    else if(a.x==b.x)
    {
        if(a.y<b.y)return true;
    }
    return false;
}
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a,a+n,cmp);
    int res=0,cnt;
    for(int i=0;i<n;i++)
    {
        if(res==0)res=min(a[i].x,a[i].y),cnt=res;
        if(a[i].x>a[i].y)
        {
            if(a[i].y>=res)res=a[i].y;
            else res=a[i].x;
        }
        else res=a[i].y;
    }
    cout<<res<<endl;
    return 0;
}