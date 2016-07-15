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
bool mark[33000];
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

int power(int N,int P)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		int ret=power(N,P/2);
		return (ret*ret);
	}
	else return (N*(power(N,P-1)));
}

bool perfect(unsigned long long int n)
{
    unsigned long long int cnt=1,x=sqrt(n);
    //cout<<x<<endl;
    for(long long int i=2;i<=x;i++)
    {
        if(n%i==0)
        {
            cnt+=i;
            if(n/i!=i)
                cnt+=(n/i);
        }
    }
    if(cnt==n)return true;
    else return false;
}


int main()
{
//    READ("file.txt");
//    WRITE("file2.txt");
    memset(mark,1,sizeof(mark));
    func(32);
    int n;
    unsigned long long x,y,z;
    while(scanf("%d",&n)&&n)
    {
        y=power(2,n-1);
        z=(power(2,n)-1);
        x=y*z;
        //cout<<x<<endl;
        if(n==31)printf("Perfect: 2305843008139952128!\n");
        else if(n==30||n==28)printf("Given number is NOT prime! NO perfect number is available.\n");
        else if(n==29)printf("Given number is prime. But, NO perfect number is available.\n");
        else if(perfect(x))
            printf("Perfect: %lld!\n",x);
        else if(mark[n])
            printf("Given number is prime. But, NO perfect number is available.\n");
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }

    return 0;
}
