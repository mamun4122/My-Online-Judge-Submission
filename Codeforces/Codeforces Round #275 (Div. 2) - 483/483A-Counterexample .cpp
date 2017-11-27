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
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    long long a,b,k;
    cin>>a>>b;
    k=a;
    if(a==0)
        k=1;
    int flag=1;
    if(b-k<2)
        cout<<"-1"<<endl;
    else
    {
        while(k+2<=b)
        {
            if(gcd(k,k+1)==1&&gcd(k+1,k+2)==1&&gcd(k,k+2)!=1){
                cout<<k<<" "<<k+1<<" "<<k+2<<endl;
                flag=0;
                break;
            }
            else
                k++;
        }
        if(flag)
            cout<<"-1"<<endl;
    }
    /*else if(k%2==0)
        cout<<k<<" "<<k+1<<" "<<k+2<<endl;
    else if(b-k==2||k+3>b)
    {
        if(gcd(k,k+1)==1&&gcd(k+1,k+2)==1)
            cout<<k<<" "<<k+1<<" "<<k+2<<endl;
        else
            cout<<"-1"<<endl;
    }
    else
        cout<<k+1<<" "<<k+2<<" "<<k+3<<endl;*/
    return 0;
}