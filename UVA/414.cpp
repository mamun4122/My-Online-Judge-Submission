#include<iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    char a[14][26];
    int d[14];
    char b[26],c[26];
    memset(d,0,sizeof(d));
    int x;
    cin>>x;
    getchar();
    while (x)
    {
        for(int i=0; i<x; i++)
        {
            gets(a[i]);
           // cout<<a[i]<<endl;
            //getchar();
            /*sscanf(a[i],"%s%s",&b,&c);
            //cout<<"1"<<b<<"2"<<c<<endl;
            d[i]=strlen(b)+strlen(c);
            cout<<"b:"<<strlen(b)<<"\tc:"<<strlen(c)<<endl;
            d[i]=25-d[i];
            cout<<i<<":"<<d[i]<<endl;*/
            for(int j=0;j<25;j++)
            {
                if(a[i][j]!=' ')
                {
                    d[i]++;
                }
            }
            d[i]=25-d[i];
        }
        int z=*min_element(d, d+x);
       // cout<<z<<endl;
        int k=0;
        for(int i=0; i<x; i++)
        {
            d[i]=d[i]-z;
            k=k+d[i];
        }
        cout<<k<<endl;
        memset(d, 0, sizeof(d));
        cin>>x;
        getchar();
    }
    return 0;
}
