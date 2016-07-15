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
    char a[25];
    map<char,char> m;
    map<char,char>::iterator it;
    m['A']='A';
    m['M']='M';
    m['Y']='Y';
    m['Z']='5';
    m['O']='O';
    m['1']='1';
    m['2']='S';
    m['E']='3';
    m['3']='E';
    m['S']='2';
    m['5']='Z';
    m['H']='H';
    m['T']='T';
    m['I']='I';
    m['U']='U';
    m['J']='L';
    m['V']='V';
    m['8']='8';
    m['W']='9';
    m['L']='J';
    m['X']='X';
    while(cin>>a)
    {
        //cout<<a<<endl;
        int flag=2;
        int x=strlen(a);
        if(x==1)
        {
            it=m.find(a[0]);
            if(it!=m.end()&&m[a[0]]==a[0])flag=2;
            else flag=1;
        }
        for(int i=0,j=x-1; i<x/2; i++,j--)
        {
            if(a[i]!=a[j])
            {
                flag=3;
                break;
            }
            else
            {
                it=m.find(a[i]);
                if(it!=m.end()&&m[a[i]]!=a[i])
                {
                    flag=1;
                }
                else if(it==m.end())
                    flag=1;
            }
        }
        if(flag==3)
        {
            for(int i=0,j=x-1; i<x/2; i++,j--)
            {
                it=m.find(a[i]);
                if(it!=m.end()&&m[a[i]]!=a[j])
                {
                    flag=0;
                    break;
                }
                else if(it==m.end())
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)
            printf("%s -- is not a palindrome.\n",a);
        else if(flag==1)
            printf("%s -- is a regular palindrome.\n",a);
        else if(flag==2)
            printf("%s -- is a mirrored palindrome.\n",a);
        else
            printf("%s -- is a mirrored string.\n",a);
        printf("\n");

    }
    return 0;
}

