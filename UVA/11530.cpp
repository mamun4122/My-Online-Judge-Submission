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

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t,sum,j;
    scanf("%d",&t);
    getchar();
    char a[110];
    map<char,int> m;
    m['a']=1;m['b']=2;m['c']=3;m['d']=1;m['e']=2;m['f']=3;m['g']=1;m['h']=2;m['i']=3;m['j']=1;
    m['k']=2;m['l']=3;m['m']=1;m['n']=2;m['o']=3;m['p']=1;m['q']=2;m['r']=3;m['s']=4;m['t']=1;m['u']=2;m['v']=3;
    m['w']=1;m['x']=2;m['y']=3;m['z']=4;m[' ']=1;
    for(int i=1;i<=t;i++)
    {
        sum=0;
        gets(a);
        //cout<<a<<endl;
        for(j=0;a[j]!='\0';j++)sum+=m[a[j]];
        printf("Case #%d: %d\n",i,sum);
    }
    return 0;
}

