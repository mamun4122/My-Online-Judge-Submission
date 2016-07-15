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
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)&&(a||b||c))
    {
        int flag1=0,flag2=0,dif1,dif2;
        if((b-a)!=0&&(b-a)==(c-b))
        {
            printf("AP %d\n",c+(b-a));
        }
        else
        {
            printf("GP %d\n",c*(b/a));
        }
    }



    return 0;
}
