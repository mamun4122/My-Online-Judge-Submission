#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <cstdio>
//#include <>
//#include <>
//#include <>
//#include <>
//#include <>
//#include <>
//#include <>
//#include<>

#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d %d",&a,&b)
#define getIII(a,b,c) scanf("%d",&a,&b,&c)



using namespace std;

int main()
{
    int n;
    while(1)
    {
        getI(n);
        if(n==0) break;
        int x,y;
        getII(x,y);
        for(int i=0;i<n;i++)
        {
            int u,v;
            getII(u,v);
            if(u==x || v==y) printf("divisa\n");
            else if(u>x)
            {
                if(v>y) printf("NE\n");
                else printf("SE\n");
            }
            else
            {
                if(v>y) printf("NO\n");
                else printf("SO\n");
            }
        }
    }


    return 0;
}
