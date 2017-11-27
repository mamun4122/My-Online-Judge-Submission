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

bool mark[100001];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        mem(mark,0);
        int k=b;
        int z=1,cnt1=1;
        printf("1");
        if(cnt1<a)
            printf(" ");
        mark[1]=1;
        int flag=1;
        while(k)
        {
            if(flag)
            {
                z+=k;
                printf("%d",z);
                mark[z]=1;
                flag=0;
                cnt1++;
            }
            else
            {
                z-=k;
                printf("%d",z);
                //cout<<z<<endl;
                mark[z]=1;

                //mark[z-k]=1;
                flag=1;
                cnt1++;
            }
            if(cnt1<a)
                printf(" ");
            k--;
        }
        k=1;
        while(cnt1<a)
        {
            if(!mark[k])
            {
                printf("%d",k);
                cnt1++;
                if(cnt1!=a)
                printf(" ");
            }
            k++;
        }
        printf("\n");
    }


    return 0;
}