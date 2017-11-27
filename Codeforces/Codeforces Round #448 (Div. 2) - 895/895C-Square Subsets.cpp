#include <bits/stdc++.h>
using namespace std;

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
#define MAX 72
int dp[MAX][(1<<19)+4];
int freq[MAX];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int masks[MAX];
const int MOD = 1e9+7;
long long bigMod(long long b, long long p)
{
    long long res = (1%MOD),x = b%MOD;
    while(p)
    {
        if(p&1)res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1;
    }
    return res;
}
int combi[100005][2];
int calc(int pos, int val)
{
//    debug(pos,val)
    if(pos == 0)return val == 0;
    int &vis = combi[pos][val];
    if(vis != -1)return vis;
    long long ret = 0;
    ret += calc(pos-1,val);ret %= MOD;
    ret += calc(pos-1,1-val);ret %= MOD;
    return vis = ret;
}

int call(int num, int mask)
{
    if(num > 70)
        return mask == 0;
    int &vis = dp[num][mask];
    if(vis != -1)return vis;
    long long ret = 0;
    if(freq[num])
    {
        long long gun = bigMod(2, freq[num]-1);
//        long long gun = combi[freq[num]][0];
        ret += gun * call(num+1,mask);ret %= MOD;
        ret += gun * call(num+1,mask ^ masks[num]);ret %= MOD;
    }
    else
        ret += call(num+1, mask);
    ret %= MOD;
    return vis = ret;

}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(combi, -1, sizeof combi);
    calc(100000,0);
//    debug("")
    for(int i = 1; i <= 70; i++)
    {
        int mask = 0;
        int num = i;
        for(int j = 0; j < 19; j++)
        {
            while(num % prime[j] == 0)
            {
                num /= prime[j];
                mask ^= (1<<j);
            }
        }
        masks[i] = mask;
    }
    while(scanf("%d",&n)!=EOF)
    {
        memset(freq, 0, sizeof freq);
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&m);
            freq[m]++;
        }
        long long ans = call(1,0);
        ans--;
        ans = (ans % MOD) + MOD;
        ans %= MOD;
        printf("%lld\n",ans);
    }

    return 0;
}