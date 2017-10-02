#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define MAX 1000002
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

int tree[MAX];

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int x, int n)
///n is the size of the array, x is the number to add
{
    while (idx <= n) {
        tree[idx] += x;
        idx += idx & (-idx);
    }
}

int a[N], b[N], c[N], hit[MAX];

struct data{
    int h, l, r;
}bc[N];

bool comp (data xx, data yy){
    return xx.r < yy.r;
}

int main()
{
    int t = nxt(), cse = 0;
    while (t--){
        memset(tree, 0, sizeof(tree));
        memset(hit, 0, sizeof(hit));
        int n = nxt(), ans = 0;
        for (int i=0; i<n; i++){
            a[i] = nxt();
            bc[i].h = a[i];
            if (hit[a[i]] == 0){
                hit[a[i]] = 1;
                update(a[i], 1, MAX);
                ans++;
            }
            bc[i].l = nxt();
            bc[i].r = nxt();
        }
        //cout << ans << endl;
        sort(bc, bc+n, comp);
        for (int i=0; i<n; i++){
            if (bc[i].r == bc[i].l){
                if (bc[i].r == bc[i].h){
                    if (hit[bc[i].r] < 2){
                        ans++;
                        hit[bc[i].r]++;
                        update(bc[i].r, 1, MAX);
                    }
                    continue;
                }
            }
            int x = query(bc[i].r) - query(bc[i].l-1);
            //printf("x = %d\n", x);
            if (x == 0){
                update(bc[i].r, 1, MAX);
                hit[bc[i].r]++;
                ans++;
                //printf("ans = %d\n", ans);
            }
            else{
                if (ans == 1){
                    update(bc[i].r, 1, MAX);
                    hit[bc[i].r]++;
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", ++cse, ans);
    }
    return 0;
}
