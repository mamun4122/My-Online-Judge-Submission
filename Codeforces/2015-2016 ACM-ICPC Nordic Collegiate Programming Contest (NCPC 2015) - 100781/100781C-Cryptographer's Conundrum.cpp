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

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0; i<s.length(); i++){
        if (i % 3 == 0 && (s[i] == 'P' || s[i] == 'p')) ans++;
        else if (i % 3 == 1 && (s[i] == 'E' || s[i] == 'e')) ans++;
        else if (i % 3 == 2 && (s[i] == 'R' || s[i] == 'r')) ans++;
    }
    cout << s.length() - ans << endl;
    return 0;
}