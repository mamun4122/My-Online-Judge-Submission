#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 1000002
#define MOD 1000000007
#define BASE 100003
//#define FastRead ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

template < class T > inline T gcd(T a, T b) {while(b) {a %= b; swap(a, b);} return a;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a, b)*b;}
inline int nxt() {int wow; scanf("%d", &wow); return wow;}
inline ll lxt() {ll wow; scanf("%lld", &wow); return wow;}
inline double dxt() {double wow; scanf("%lf", &wow); return wow;}

/***************** Fighters Launched *******************/

int prime[N], hit[N], total = 0;

void pg(int n)
{
    int z = sqrt(n)+1; prime[total++] = 2, hit[0] = hit[1] = 1;
    for(int i=3; i<=z; i++) for(int j=i*i; j<=n; j+= 2*i) hit[j] = 1;
    for(int i=3; i<=n; i+=2) if(!hit[i]) prime[total++] = i;
}

ll SOD(ll n)
{
    ll z = sqrt(n)+1;
    ll ans = 1;
    for(int i=0; prime[i] <= z && i < total; i++){
        if(n % prime[i] == 0){
            ll p = 1, temp = 1;        ///p needs to be initialized to 1
            while (n % prime[i] == 0){
                n /= prime[i];          ///raising prime and iterating power
                p *= prime[i];
                temp += p;
            }
            z = sqrt(n) + 1;
            ans *= temp;
        }
    }
    if (n != 1) ans *= (n + 1);    ///Need to multiply (p^0+p^1)
    return ans;
}

int main()
{
    pg(N-2);
    int t = nxt();
    while (t--){
        ll n = lxt(), sum = SOD(n) - n;
        if (sum < n) puts("deficient");
        else if (sum == n) puts("perfect");
        else if (sum > n) puts("abundant");
    }
    return 0;
}
