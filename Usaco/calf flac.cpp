/*
ID:mamun4122
PROG:calfflac
LANG:C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[20001],d[20001];
int n,x=0,y=0,p[20001],s,e,l=0;
void pal(int left,int right)
{
    int f;
    while(d[left]==d[right]&&left>=0&&right<=y)
    {
        //f+=2;
        left--;right++;
    }
    f=right-left-1;
    if(l<f){
        l=f;
        s=p[left+1];
        e=p[right-1];
    }
}


int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    memset(p,-1,sizeof(p));
    char ch;
    while(scanf("%c",&ch)!=EOF)
    {
        c[x++]=ch;
        if(ch>='A'&&ch<='Z'){
            p[y]=x-1;
            d[y++]=ch+32;

        }
        else if(ch>='a'&&ch<='z'){
            p[y]=x-1;
            d[y++]=ch;
        }
    }
    c[x]='\0';
    d[y]='\0';
    //cout<<c<<endl<<d<<endl;
    for(int j=1;j<y;j++)
    {
        pal(j-1,j+1);
        pal(j,j+1);
    }
    cout<<l<<endl;
    for(int j=s;j<=e;j++)
    {
        cout<<c[j];
    }
    cout<<endl;

    return 0;
}
