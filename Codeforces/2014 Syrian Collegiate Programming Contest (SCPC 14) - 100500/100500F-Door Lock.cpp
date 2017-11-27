#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 100002
#define MOD 1000000007
#define BASE 100003
const double EPS = 1e-9;
#define eq(a,b) (fabs(a-b)<EPS)

//#define FastRead ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

template < class T > inline T gcd(T a, T b) {while(b) {a %= b; swap(a, b);} return a;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a, b)*b;}
inline int nxt() {int wow; scanf("%d", &wow); return wow;}
inline ll lxt() {ll wow; scanf("%lld", &wow); return wow;}
inline double dxt() {double wow; scanf("%lf", &wow); return wow;}

/***************** Fighters Launched *******************/

ll xlook(ll n, ll k){
    ll low = 1, high = n, ans = high;
    while (low <= high){
        ll mid = (low+high)/2;
        ll now;
        if (mid & 1) now = (mid+1)/2*mid;
        else now = mid/2*(mid+1);
        if (now >= k){
            high = mid-1;
            ans = mid;
        }
        else low = mid+1;
    }
    return ans-1;
}

int main()
{
    int t = nxt(), cse = 0;
    while (t--){
        ll n = lxt(), k = lxt();
        ll x = xlook(n, k);
        ll q;
        if (x&1) q = (x+1)/2*x;
        else q = x/2*(x+1);
        ll y = k-q-1;
        printf("Case %d: %lld %lld\n", ++cse, x, y);
    }
    return 0;
}