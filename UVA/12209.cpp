#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define SET(n) memset(n, -1, sizeof(n))
#define vi vector <int>
#define vii vector < vi >
#define ALL(p) p.begin(), p.end()
const int INF = INT_MAX;
int n,s,w;
vii v;

int up(int in, int val)
{
    int low = 0, high = v[in].size()-1;
    int res = -1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(v[in][mid] >= val)
        {
            high = mid-1;
            res = mid;
        }
        else low = mid + 1;
    }
    return res;
}
int down(int in, int val)
{
    int low = 0, high = v[in].size()-1;
    int res = -1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(v[in][mid] <= val)
        {
            low = mid+1;
            res = mid;
        }
        else high = mid - 1;
    }
    return res;
}

int dp[504];

int call(int line)
{
    if(line>=n) return 0;

    int &ret = dp[line];
    if(ret!=-1) return ret;

    int res = INF;
    FOR(i, line+1, n)
    {
        int cnt = 0;
        FOR(j,0,w-1)
        {
            int u = up(j, line+1);
            if(u==-1) continue;
            int d = down(j, i);
            if(d==-1) continue;
            if(d-u+1 > 0) cnt++;
//            cnt += (d-u+1);
        }

        if(cnt + (i-line) > s) break;
        res = min(res, cnt + call(i));
    }
    return ret = res;
}

int main()
{
//    freopen("in.txt","r", stdin);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        cin >> n >> s >> w;
        v.assign(w+4, vi());
        FOR(i,0,w-1)
        {
            int k;
            cin >> k;
//            v[i].clear();
            FOR(j,1,k)
            {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
            sort(ALL(v[i]));
        }

        SET(dp);
        int kk = call(0);
        if(kk >= 100000) kk = -1;
        printf("Case %d: %d\n",ci, kk);
    }
}
