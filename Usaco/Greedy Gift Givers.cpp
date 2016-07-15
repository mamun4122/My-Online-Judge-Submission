/*
ID: mamun4122
LANG: C++
TASK: gift1
*/
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    int n;
    scanf("%d",&n);
    map<string,int> m1;
    //map<string,int>::iterator it;
    int i;
    char a[20];
    char b[1000][20];
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
        //cout<<b[i]<<endl;
        m1.insert(pair<string,int>(b[i],0));
        //m1[a]=0;
    }
    int x,y,z,j;
    for(i=1;i<=n;i++)
    {
        scanf("%s",&a);
        //cout<<a<<endl;
        scanf("%d%d",&x,&y);
        //cout<<x<<" "<<y<<endl;
        if(y!=0)
        {
            m1[a]=m1[a]-(x-(x%y));
            z=x/y;
            for(j=1;j<=y;j++)
            {
                scanf("%s",&a);
                //cout<<a<<endl;
                m1[a]=m1[a]+z;
                //cout<<m1[a]<<endl;
            }
        }
        else
        {
            m1[a]=m1[a]-x;
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<b[i]<<" "<<m1[b[i]]<<endl;
    }
    m1.clear();
    return 0;
}
