#include <bits/stdc++.h>
using namespace std;

char ok[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main(){
    int hit[200] = {0};
    for (int i=0; i<11; i++) hit[ok[i]] = 1;
    int t;
    cin >> t;
    while (t--){
        bool flag = false;
        string s;
        cin >> s;
        for (int i=0; i<s.length(); i++){
            char x = s[i];
            if (hit[x] == 0) flag = 1;
        }
        for (int i=0, j=s.length()-1; i<s.length(); i++, j--){
            if (s[i] != s[j]) flag = 1;
        }
        if (flag) puts("no");
        else puts("yes");
    }
    return 0;
}