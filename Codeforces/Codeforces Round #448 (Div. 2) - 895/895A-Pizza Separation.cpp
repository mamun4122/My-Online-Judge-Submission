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

int arr[505];

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n)
    {
        vector<int> v;
        int ans = 360;
        int tot = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            tot += arr[i];
            ans = min(ans, abs(360-2*tot));
        }
        for(int i = 0; i < n; i++)
        {
            int tot = 0;
            for(int j = i,cnt = 0; cnt < n; j++,cnt++)
            {
                tot += arr[j%n];
                ans = min(ans,abs(360 - 2*tot));
            }
        }
        cout << ans << endl;

    }

    return 0;
}