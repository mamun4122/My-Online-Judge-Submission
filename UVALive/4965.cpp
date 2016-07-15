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
    //READ("in.txt");
    //WRITE("out.txt");
    int a[2000],b[2000];
    int c,d,e,f,i,sum=0;
    while(scanf("%d%d",&c,&d)&&c&&d)
    {
        int res=0;
        mem(a,0);
        mem(b,0);
        i=1;
        e=c;
        f=d;
        if(e>1000)
        {
            sum=0;
            while(e!=0)
            {
                sum+=(e%10)*(e%10);
                e/=10;
            }
            e=sum;
            i=2;
        }
        while(a[e]==0)
        {
            a[e]=i++;
            //printf("%d %d %d\n",e,i,a[e]);
            sum=0;
            while(e!=0)
            {
                sum+=(e%10)*(e%10);
                e/=10;
            }
            e=sum;

        }
        sum=0;
        i=1;
        if(c==d)res=2;
        if(f>1000)
        {
            while(f!=0)
            {
                sum+=(f%10)*(f%10);
                f/=10;
            }
            f=sum;
            i=2;
        }
        while(b[f]==0)
        {
            b[f]=i++;
            //printf("mam%d %d %d\n",f,i,b[f]);
            if(a[f]!=0)
            {
                if(res==0){
                    res=a[f]+b[f];
                    //printf("\nres%d %d\n",f,res);
                }
                else{
                    res=min(res,a[f]+b[f]);
                    //printf("\nres%d %d\n",f,res);
                }
            }
            sum=0;
            while(f!=0)
            {
                sum+=(f%10)*(f%10);
                f/=10;
            }
            f=sum;
        }
        printf("%d %d %d\n",c,d,res);
    }


    return 0;
}


