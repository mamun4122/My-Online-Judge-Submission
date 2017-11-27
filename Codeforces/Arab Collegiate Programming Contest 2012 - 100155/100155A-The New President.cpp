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

int main()
{
    int t = nxt(), cse = 0;
    while (t--){
        int c = nxt(), v = nxt();
        int a[102][102], hit[102] = {0};
        for (int i=1; i<=v; i++){
            for (int j=1; j<=c; j++){
                a[i][j] = nxt();
            }
        }
        for (int i=1; i<=v; i++) hit[a[i][1]]++;
        int idx = 0, cur = 0;
        for (int i=1; i<=c; i++){
            if (hit[i] > cur){
                cur = hit[i];
                idx = i;
            }
        }
        //printf("Case %d: ", ++cse);
        if (cur > v/2){
            printf("%d %d\n", idx, 1);
            continue;
        }
        int two = 0, dit = -1;
        for (int i=1; i<=c; i++){
            if (hit[i] > dit && i!=idx){
                two = i;
                dit = hit[i];
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i=1; i<=v; i++){
            for (int j=1; j<=c; j++){
                if (a[i][j] == idx){
                    cnt1++;
                    break;
                }
                if (a[i][j] == two){
                    cnt2++;
                    break;
                }
            }
        }
        if (cnt1 > cnt2) printf("%d", idx);
        else printf("%d", two);
        printf(" 2\n");
    }
    return 0;
}