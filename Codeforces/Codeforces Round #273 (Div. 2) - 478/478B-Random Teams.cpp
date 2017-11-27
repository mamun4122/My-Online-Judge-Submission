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

long long C(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}




int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    //cout<<C(2,2)<<endl;
    int n,r;
    scanf("%d%d",&n,&r);
    int ans1,ans2,k;
    ans2=n-(r-1);
    if(n==r)cout<<"0 0"<<endl;
    else{
    if(r==1)
        cout<<C(n,2)<<" ";
    else
    {
        ans1=n/r;
        k=n%r;
        //cout<<ans1<<" "<<k<<endl;
        if(ans1<2)
            cout<<k*C(ans1+1,2)<<" ";
        else
            cout<<k*C(ans1+1,2)+(r-k)*C(ans1,2)<<" ";

    }
    cout<<C(ans2,2)<<endl;}
    return 0;
}