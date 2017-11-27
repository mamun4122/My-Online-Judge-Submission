#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;



int main(){
    int t;
    cin >> t;
    double x, n;
    while (t--){
        cin >> x >> n;
        double theta = n * (pi/180);
        double chap_area = ((pi * x * x)/360) * n;
        double tri_area = x * x * sin(theta) / 2;
        printf("%0.6lf\n", chap_area - tri_area);
    }
    return 0;
}