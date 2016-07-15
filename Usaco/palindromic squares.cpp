/*
ID: mamun4122
LANG: C++
TASK: palsquare
*/
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
int n,sz1,sz2;
map<int,char>m;
vector<char> v1;
vector<char> v2;
void str1(int x)
{
    while(x!=0)
    {
        v1.push_back(m[x%n]);
        x=x/n;
    }
    sz1=v1.size();
}
void str2(int x)
{
    while(x!=0)
    {
        v2.push_back(m[x%n]);
        x=x/n;
    }
    sz2=v2.size();
}
bool res( )
{
    if(sz2==1)
        return true;
    int f=0;
    for(int i=0,j=sz2-1;i<sz2/2;i++,j--)
    {
        if(v2[i]!=v2[j])
        {
            f=1;break;
        }
    }
    if(f==0)
        return true;
    return false;
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int d=0;
    m[d++]='0';m[d++]='1';m[d++]='2';m[d++]='3';m[d++]='4';m[d++]='5';m[d++]='6';m[d++]='7';m[d++]='8';m[d++]='9';
    m[d++]='A';m[d++]='B';m[d++]='C';m[d++]='D';m[d++]='E';m[d++]='F';m[d++]='G';m[d++]='H';m[d++]='I';m[d++]='J';
    scanf("%d",&n);
    int x,j;
    for(int i=1;i<=300;i++)
    {
        x=i*i;
        str2(x);
        if(res())
        {
            str1(i);
            for(j=sz1-1;j>=0;j--)
                cout<<v1[j];
            cout<<" ";
            for(j=sz2-1;j>=0;j--)
                cout<<v2[j];
            cout<<endl;
        }
        v1.clear();
        v2.clear();
    }

    return 0;
}
