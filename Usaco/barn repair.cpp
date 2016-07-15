/*
ID: mamun4122
LANG: C++
TASK: barn1
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int a,b,c,d[205],e[205],res=0,ans=0,n;
    cin>>a>>b>>c;
    for(int i=0; i<c; i++)
    {
        cin>>d[i];
    }
    if(c<=a)
        res=c;
    else
    {
        sort(d,d+c);
        int k=0;
        for(int i=1; i<c; i++)
        {
            e[k]=d[i]-d[i-1];
            k++;
        }
        sort(e,e+k);
        for(int i=1; i<a; i++)
        {
            res+=e[--k];
            res--;
        }
        res+=(d[0]-1)+(b-d[c-1]);
        res=b-res;
    }
    cout<<res<<endl;
    return 0;
}
