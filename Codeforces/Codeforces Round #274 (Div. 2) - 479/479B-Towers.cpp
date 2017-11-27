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
    data(int a,int b)
    {
        x=a;
        y=b;
    }
};
stack<data> st;
int a[101];
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int mn,mx,i;
    for(i=1; i<=k; i++)
    {
        mx=0;
        mn=0;
        for(int j=0; j<n; j++)
        {
            if(a[j]>a[mx])mx=j;
            if(a[j]<a[mn])mn=j;
        }
        if(a[mx]-a[mn]<=1)
            break;
        else
        {
            st.push(data(mx+1,mn+1));
            a[mx]--;
            a[mn]++;
        }

    }
    for(int j=0; j<n; j++)
    {
        if(a[j]>a[mx])mx=j;
        if(a[j]<a[mn])mn=j;
    }
    cout<<a[mx]-a[mn]<<" "<<st.size()<<endl;
    while(!st.empty())
    {
        data x=st.top();st.pop();
        cout<<x.x<<" "<<x.y<<endl;
    }
    return 0;
}