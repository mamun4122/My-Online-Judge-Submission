/*
ID: mamun4122
LANG: C++
TASK: dualpal
*/
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
int y,s,sz2;
map<int,char>m;

vector<char> v2;

void str2(int x,int n)
{
    while(x!=0)
    {
        v2.push_back(m[x%n]);
        x=x/n;
    }
    int f=0,i=0;
    /*while(!v2.empty()&&f==0)
    {
        if(v2[i]=='0')
        {
            v2.erase(v2.begin()+i);
            i++;
        }
        else
        {
            f=1;
        }
    }*/
    sz2=v2.size();
    /*i=sz2-1;
    while(!v2.empty()&&f==0)
    {
        if(v2[i]=='0')
        {
            v2.erase(v2.begin()+i);
            i--;
        }
        else
        {
            f=1;
        }
    }*/
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
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int d=0;
    m[d++]='0';m[d++]='1';m[d++]='2';m[d++]='3';m[d++]='4';m[d++]='5';m[d++]='6';m[d++]='7';m[d++]='8';m[d++]='9';
    m[d++]='A';m[d++]='B';m[d++]='C';m[d++]='D';m[d++]='E';m[d++]='F';m[d++]='G';m[d++]='H';m[d++]='I';m[d++]='J';
    scanf("%d%d",&y,&s);
    int cnt=0,x=s+1,f=0;
    while(cnt!=y)
    {
        f=0;
        for(int i=2;i<=10;i++)
        {
            str2(x,i);
            if(res()){
                f++;
            }
            if(f>=2)
            {
                cout<<x<<endl;
                cnt++;
                v2.clear();
                break;
            }
            v2.clear();
        }
        x++;
    }

    return 0;
}

