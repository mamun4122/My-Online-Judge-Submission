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

#define mx 300002

int temp[mx];
int dist[mx];

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int n,k=1;
    while(scanf("%d",&n)&&n)
    {
        int e=n*3;
        memset(dist,63,sizeof(dist));
        for(int i=1;i<=e;i++)
            scanf("%d",&temp[i]);
        dist[2]=temp[2];
        for(int i=2;i<=e-1;i++)
        {
            if(i%3==1||i%3==2)
            {
                dist[i+1]=min(dist[i+1],dist[i]+temp[i+1]);
                dist[i+3]=min(dist[i+3],dist[i]+temp[i+3]);
                dist[i+4]=min(dist[i+4],dist[i]+temp[i+4]);
            }
            if(i%3==2)
            {
                dist[i+2]=min(dist[i+2],dist[i]+temp[i+2]);
            }
            if(i%3==0)
            {
                dist[i+2]=min(dist[i+2],dist[i]+temp[i+2]);
                dist[i+3]=min(dist[i+3],dist[i]+temp[i+3]);
            }
        }
        printf("%d. %d\n",k++,dist[e-1]);
    }

    return 0;
}
