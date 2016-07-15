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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    scanf("%d\n",&t);
    char a[210],b[210];
    for(int i=1; i<=t; i++)
    {
        gets(a);
        printf("Case %d: ",i);
        int l=strlen(a);
        char c;
        int d=0,k=0;
        for(int j=0; j<=l; j++)
        {
            if(a[j]>=48&&a[j]<=57)
            {
                d=d*10+(a[j]-48);
            }
            else
            {
                for(int m=1; m<=d; m++)
                {
                    b[k++]=c;
                }
                c=a[j];
                d=0;
            }
        }
        /*for(int m=1; m<=d; m++)
        {
            b[k++]=c;
        }*/
        b[k]='\0';
        puts(b);

    }



    return 0;
}

