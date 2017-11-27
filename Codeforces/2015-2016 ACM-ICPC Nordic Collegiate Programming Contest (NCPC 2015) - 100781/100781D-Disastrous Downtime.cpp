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

int tree[2*N+10];

int query (int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update (int idx, int x, int n){
    while(idx <= n){
        tree[idx] += x;
        idx += idx & (-idx);
    }
}



int main()
{
    int n = nxt(), k = nxt();
    for (int i=0; i<n; i++){
        int x = nxt();
        x++;
        update(x, 1, N-1);
        update(x+1000, -1, N-1);
    }
    int mx = 0;
    for (int i=1; i<200000; i++){
        mx = max(mx, query(i));
    }
    int ans = mx/k;
    if (mx%k) ans++;
    printf("%d\n", ans);
    return 0;
}