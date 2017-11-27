#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 102
#define MOD 1000000007
#define BASE 100003
const double EPS = 1e-9;
#define eq(a,b) (fabs(a-b)<EPS)

#define FastRead ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

template < class T > inline T gcd(T a, T b) {while(b) {a %= b; swap(a, b);} return a;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a, b)*b;}
inline int nxt() {int wow; scanf("%d", &wow); return wow;}
inline ll lxt() {ll wow; scanf("%lld", &wow); return wow;}
inline double dxt() {double wow; scanf("%lf", &wow); return wow;}

/***************** Fighters Launched *******************/

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

int main()
{
    FastRead;
    int t;
    //cin >> t;
    //while (t--)
    {
        int n, m, a[N][N] = {0}, uni[N] = {0};
        cin >> n >> m;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cin >> a[i][j];
            }
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (a[i][j] == -1) continue;
                for (int k=0; k<8; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if (a[i][j] == a[x][y]) uni[a[i][j]] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i=1; i<=100; i++) if (uni[i]) cnt++;
        cout << cnt << '\n';
    }
    return 0;
}