/*
ID:mamun4122
PROG:crypt1
LANG:C++
*/
#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
bool m[10];
bool func(int x)
{
    int b=x;
    while(b!=0)
    {
        if(!m[b%10])
            return false;
        else
            b/=10;
    }
    return true;
}
int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int n,d[11];bool res[1000][100];
    //bool res[1000];
    //map<int,int> res;
    memset(m,0,sizeof(m));
    memset(res,0,sizeof(res));
    //memset(res,0,sizeof(res));
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&d[i]);
        m[d[i]]=true;
    }
    int x=0,y=0,z,p,q,r,s,cnt=0;
    for(int a=1; a<=n; a++)
    {
        x+=(d[a]*100);
        for(int b=1; b<=n; b++)
        {
            x+=(d[b]*10);
            for(int c=1; c<=n; c++)
            {
                x+=d[c];
                for(int k=1; k<=n; k++)
                {
                    y+=(d[k]*10);
                    for(int e=1; e<=n; e++)
                    {
                        int flag=0;
                        y+=d[e];
                        z=x*y;
                        p=x*d[e];
                        q=x*d[k];
                        //cout<<x<<" "<<y<<endl;
                        if(!res[x][y]&&z<10000&&z>999&&p>99&&p<1000&&q>99&&q<1000)
                        {
                            if(func(z)&&func(p)&&func(q))
                            {
                                //res[x]=y;
                                cnt++;
                            }
                        }
                        res[x][y]=true;
                        y-=d[e];
                    }
                    y-=(d[k]*10);
                }
                x-=d[c];
            }
            x-=(d[b]*10);
        }
        x-=(d[a]*100);
    }
    cout<<cnt<<endl;
    return 0;
}
