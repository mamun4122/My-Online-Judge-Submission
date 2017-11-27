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

int sum(int x){
    int ret = 0;
    while(x){
        ret += (x % 10);
        x /= 10;
    }
    return ret;
}

int main()
{
    while (1){
        int n = nxt(), ans = 100;
        if (n == 0) break;
        for (int i=100; i>10; i--){
            if (sum(n) == sum(i*n))
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}