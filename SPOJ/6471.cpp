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

#define mx 100000000

bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int status[(mx/32)+2];
void sieve()
{
	 int i, j;
     for( i = 3; i*i <=mx; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= mx; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }
    int cnt=1,x=101;
	 puts("2");
	 for(i=3;i<=mx;i+=2)
		 if( Check(status[i>>5],i&31)==0)
         {
             cnt++;
            //cout<<cnt<<endl;
            if(cnt==x)printf("%d\n",i),x+=100;
         }
}




int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    sieve();
    return 0;
}

