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

vector<int> prime;
bool mark[10001];
void func(int n)
{
    if(n>=2)
        prime.push_back(2);
    for(int i=4; i<=n; i+=2)mark[i]=0;
    for(int i=3; i<=n; i+=2)
    {
        if(mark[i])
        {
            prime.push_back(i);
            for(int j=i+i; j<=n; j+=i)
            {
                mark[j]=0;
            }
        }
    }
}

int main()
{
//    READ("file.txt");
//    WRITE("file2.txt");
    memset(mark,1,sizeof(mark));
    func(10000);
    vector<int>::iterator low;
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        x/=2;
        low=upper_bound(prime.begin(),prime.end(),x);
        int y=low-prime.begin();
        cout<<prime[y]<<endl;

    }
    return 0;
}
