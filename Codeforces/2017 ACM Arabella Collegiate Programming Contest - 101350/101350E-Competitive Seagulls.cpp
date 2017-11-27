#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;



int main(){
    int t;
    cin >> t;
    while (t--){
        int x;
        scanf("%d", &x);
        if (x==1 || x>3) puts("first");
        else puts("second");
    }
    return 0;
}