#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 1002
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

int dp[N][N], a[N][N];

int main()
{
    int t = nxt(), cse = 0;
    while (t--){
        memset(dp, 0, sizeof(dp));
        int n = nxt(), m = nxt();
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                a[i][j] = nxt();
            }
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (i == 1) dp[i][j] = dp[i][j-1] + a[i][j];
                else if (j == 1) dp[i][j] = dp[i-1][j] + a[i][j];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
            }
        }
        printf("Case %d: %d\n", ++cse, dp[n][m]);
    }
    return 0;
}