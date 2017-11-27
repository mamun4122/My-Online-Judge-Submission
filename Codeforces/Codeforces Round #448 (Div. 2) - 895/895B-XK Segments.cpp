#include <bits/stdc++.h>
using namespace std;

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    ALL(p)           p.begin(),p.end()

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

#define MAX 200005
int arr[MAX];
vector<int> v;

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int k;
        scanf("%d",&k);
        v.clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&arr[i]);
            v.push_back(arr[i]);
        }
        sort(ALL(v));
        long long ans = 0;
        for(int i= 1; i <= n; i++)
        {
            if(k == 0 && arr[i] % m == 0)continue;
            long long cur = arr[i];
            long long curdiv = (cur-1)/m;
            long long lagbe = curdiv+k;
            long long minival = lagbe * m;
            if(k == 0)minival = arr[i];
            long long maxval = (lagbe+1) * m - 1;
//            debug(curdiv,arr[i],minival,maxval);
            int ret = 0;
            ret += upper_bound(ALL(v),maxval) - v.begin();
            ret -= lower_bound(ALL(v),minival) - v.begin();
            ans += ret;
        }
        printf("%lld\n",ans);
    }

    return 0;
}