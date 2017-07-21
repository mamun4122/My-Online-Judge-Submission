#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 500002
#define MOD 1000000007
#define BASE 100003
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

template < class T > inline T gcd(T a, T b) {while(b) {a %= b; swap(a, b);} return a;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a, b)*b;}
inline int nxt() {int wow; scanf("%d", &wow); return wow;}
inline ll lxt() {ll wow; scanf("%lld", &wow); return wow;}
inline double dxt() {double wow; scanf("%lf", &wow); return wow;}

/***************** Fighters Launched *******************/

int lft[N], rgt[N], hit[N];
char s[N];

int main()
{
    while (scanf("%s", s) != EOF){
        //for (int i=0; i<N; i++) lft[i] = rgt[i] = hit[i] = 0;
        int n = strlen(s), cur = 0, ans = 0;
//        for (int i=1; i<=n; i++){
//            lft[i] = cur;
//            if (s[i-1]=='X') cur = i;
//        }
        cur = n+1;
        for (int i=n; i>0; i--){
            rgt[i] = cur;
            if (s[i-1] == 'X') cur = i;
        }
//        for (int i=1; i<=n; i++) cout << lft[i] << " "; cout << endl;
//        for (int i=1; i<=n; i++) cout << rgt[i] << " "; cout << endl;
        cur = 0;
        for (int i=1; i<=n; i++){
            lft[i] = cur;
            if (s[i-1] == 'X'){
                cur = i;
                lft[i] = cur;
                continue;
            }
            lft[i] = cur;
            hit[i] = min(i-lft[i], rgt[i]-i)-1;
            if (i==1) hit[i] = rgt[i]-i-1;
            if (i==n) hit[i] = i-lft[i]-1;
            ans = max(ans, hit[i]);
        }
        //for (int i=1; i<=n; i++) cout << hit[i] << " "; cout << endl;
        printf("%d\n", ans);
    }
    return 0;
}
