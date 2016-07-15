#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
//#include <>
//#include <>
//#include <>
//#include <>
//#include <>
//#include<>

using namespace std;
#define mamun4122
#ifdef mamun4122
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)
#endif // mamun4122

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;

#define clr(a) memset(a,0,sizeof(a))

#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d %d",&a,&b)
#define getIII(a,b,c) scanf("%d",&a,&b,&c)

string s1;
int flg=0;

map <string,int> mp;

void call(string st,int cnt)
{
    //debug(st);
    if(mp[st]!=0) return;
    mp[st]=1;
    if(s1.compare(st)==0) flg=1;
    if(flg) return;
    if(cnt>4000) return;
    string tmp=st;
    tmp[0]=st[4];
    tmp[1]=st[0];
    tmp[2]=st[2];
    tmp[3]=st[3];
    tmp[4]=st[5];
    tmp[5]=st[1];
    call(tmp,cnt+1);
    tmp[0]=st[1];
    tmp[1]=st[5];
    tmp[2]=st[2];
    tmp[3]=st[3];
    tmp[4]=st[0];
    tmp[5]=st[4];
    call(tmp,cnt+1);
    tmp[0]=st[0];
    tmp[1]=st[3];
    tmp[2]=st[1];
    tmp[3]=st[4];
    tmp[4]=st[2];
    tmp[5]=st[5];
    call(tmp,cnt+1);
    tmp[0]=st[0];
    tmp[1]=st[2];
    tmp[2]=st[4];
    tmp[3]=st[1];
    tmp[4]=st[3];
    tmp[5]=st[5];
    call(tmp,cnt+1);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    string s;
    while(getline(cin,s)&&!s.empty())
    {
        mp.clear();
        flg=0;
        string s2="";
        s1="";
        for(int i=0;i<6;i++)
        {
            s1+=s[i];
        }
        for(int i=6;i<12;i++)
        {
            s2+=s[i];
        }
        call(s2,0);
        if(flg) printf("TRUE\n");
        else printf("FALSE\n");
    }
}

