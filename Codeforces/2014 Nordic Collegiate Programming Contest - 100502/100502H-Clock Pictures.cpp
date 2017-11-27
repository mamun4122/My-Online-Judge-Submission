#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 400002
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

int a[N], b[N], e[N], f[N];

int basepower[N], n;
ll prehash[N];

void hashes (ll base, ll modulo){
    ll hash_val = 0, r_val = 0;

    for (int i=0; i<n+n; i++){
        hash_val = hash_val * base + e[i];
        hash_val %= modulo;
        prehash[i+1] = hash_val;
    }
}

ll hsh (ll base, ll modulo){
    ll hash_val = 0;
    ll ret = 0;
    for (int i=0; i<n; i++){
        hash_val = hash_val * base + f[i];
        hash_val %= modulo;
        ret = hash_val;
    }
    return ret;
}

ll get_fhash(int x, int y){
    ll cur_hash = prehash[y] - (prehash[x-1]*basepower[y-x+1]) % MOD;
    if (cur_hash < 0) cur_hash += MOD;
    return cur_hash;
}

void generate_base_power(){
    basepower[0] = 1;
    for (int i=1; i<N; i++) basepower[i] = ((ll)basepower[i-1] * (ll)BASE)%MOD;
}



int main()
{
    generate_base_power();
    n = nxt();
    for (int i=0; i<n; i++) a[i] = nxt();
    for (int i=0; i<n; i++) b[i] = nxt();

    sort(a, a+n);
    sort(b, b+n);

    int x = a[0], y = b[0];
    for (int i=0; i<n; i++) a[i] = a[i] - x;
    for (int i=0; i<n; i++) b[i] = b[i] - y;

    vector < int > c, d;
    for (int i=1; i<n; i++) c.pb(a[i]-a[i-1]); c.pb(360000-a[n-1]);
    for (int i=1; i<n; i++) d.pb(b[i]-b[i-1]); d.pb(360000-b[n-1]);

    for (int i=0; i<n; i++){
        e[i] = c[i];
        f[i] = d[i];
    }
    for (int i=n; i<n+n; i++){
        e[i] = e[i-n];
    }

    hashes((ll)BASE, (ll)MOD);
    ll h = hsh((ll)BASE, (ll)MOD);

    bool flag = false;
    for (int i=1; i<=n; i++){
        ll now = get_fhash(i, i+n-1);
        if (now == h) flag = true;
    }

    if (flag) puts("possible");
    else puts("impossible");

    return 0;
}