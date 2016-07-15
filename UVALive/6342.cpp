#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

#define ALL(p) p.begin(),p.end()
#define mem(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PB(x) push_back(x)

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

char a[100];
bool palindrome(int n)
{
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        if(a[i]!=a[j])return false;
    }
    return true;
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        if(palindrome(strlen(a)))
            printf("YES\n");
        else
            printf("NO\n");
    }



    return 0;
}