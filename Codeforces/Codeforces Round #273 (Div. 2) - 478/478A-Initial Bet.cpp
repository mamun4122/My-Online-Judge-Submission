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
    int a[10],res=0;
    for(int i=1;i<=5;i++)
    {
        scanf("%d",&a[i]);
        res+=a[i];
    }
    if(res!=0&&res%5==0)
        printf("%d\n",res/5);
    else
        printf("-1\n");
    return 0;
}