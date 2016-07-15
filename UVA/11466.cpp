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



int main()
{
//    READ("file.txt");
//    WRITE("file2.txt");
    long long int n,lrge,x,i;
    int div=0,flag=0,f=0;
    while(scanf("%lld",&n)&&n)
    {
        div=0,flag=0,f=0;
        n=abs(n);
        x=n;
        for(i=2;i<=sqrt(n)&&n>1;)
        {
           if(n%i==0)
           {
               if(flag==0)
               {
                   flag=1;
                   div=i;
               }
               else if(div!=i)
               {
                   f=1;
               }
               n/=i;
               lrge=i;
           }
           else{
            i++;
           }
        }
        lrge=max(lrge,n);
        if(f==0&&div!=lrge)
            f=1;
        if(i==x||n==x||f==0)
            printf("-1\n");
        else
            printf("%lld\n",lrge);
    }

    return 0;
}

