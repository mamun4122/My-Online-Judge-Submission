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
    long long int g,t,a,d;
	while(scanf("%lld%lld%lld%lld",&g,&t,&a,&d))
	{
		if(g==-1&&t==-1&&a==-1&&d==-1) break;
		long long int res1,team,res2=1;
		res1=((t*(t-1))/2)*g;
		team =a*g+d;
		while(res2<team)res2*=2;
		res1+=(res2-1);
		res2-=team;
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,res1,res2);
	}


    return 0;
}
