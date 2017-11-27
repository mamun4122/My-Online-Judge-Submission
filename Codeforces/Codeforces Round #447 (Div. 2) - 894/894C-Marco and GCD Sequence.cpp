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

int arr[1005];
int mark[1000005];

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
        memset(mark,0,sizeof mark);
        int ok = 1;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            if(arr[i] % arr[1] != 0)
                ok = 0;
        }
        if(ok)
        {
            cout << 2*n << endl;
            for(int i = 1; i <= n; i++)
                cout << arr[1] << " " << arr[i] << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;

    }

    return 0;
}