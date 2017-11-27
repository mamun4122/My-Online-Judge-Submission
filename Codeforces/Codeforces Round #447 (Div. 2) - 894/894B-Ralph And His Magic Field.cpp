#include <bits/stdc++.h>
using namespace std;

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)


#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << ": " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << ": " << arg1 << " | ";
        __f(comma+1, args...);
    }
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define trace(...)
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
typedef long long ll;
ll bigMod(ll b, ll p, ll m)
{
    ll res = 1 % m, x =b % m;
    while(p)
    {
        if(p & 1)res  = (res * x) % m;
        x = (x * x) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m,k;
    while(cin >> n >> m >> k)
    {
        if(k == -1 && n%2 != m%2)
            cout << "0" << endl;
        else
            cout << bigMod(bigMod(2,n-1,1e9+7),m-1,1e9+7) << endl;
    }
    return 0;
}