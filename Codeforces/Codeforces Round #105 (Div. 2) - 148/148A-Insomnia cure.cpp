#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define ff first
#define ss second
#define pi acos(1.0)
#define pb push_back
#define INF (ll)1e17
#define N 100002
#define MOD 1000000007
#define BASE 100003
#define FastRead ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

inline int nxt(){
    int wow;
    scanf("%d", &wow);
    return wow;
}

inline ll lxt(){
    ll wow;
    scanf("%lld", &wow);
    return wow;
}

int hit[N];

int main()
{
    int k, l, m, n, d, ans = 0;
    cin >> k >> l >> m >> n >> d;
    for (int i=1; i<=d; i++){
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}