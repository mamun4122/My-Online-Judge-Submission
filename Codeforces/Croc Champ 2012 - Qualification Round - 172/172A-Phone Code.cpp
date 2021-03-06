#include <bits/stdc++.h>
#define ll long long int
#define pii pair <int,int>
#define ff first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define INF (ll)1e17
#define N 30002
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

int main()
{
    FastRead;
    int n;
    cin >> n;
    string s[N];
    for (int i=0; i<n; i++){
        cin >> s[i];
    }
    string x = s[0];
    int ans = 0;
    for (int i=0; i<x.length(); i++){
        char cur = x[i];
        int flag = 0;
        for (int j=0; j<n; j++){
            if (s[j][i] != cur){
                flag = 1;
                break;
            }
        }
        if (flag) break;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}