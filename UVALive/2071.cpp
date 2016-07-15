#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long int fib[100];
int n;
void fibo()
{
    long long int x=0,y=1,z=1;
    n=0;
    fib[n++]=0;
    while(z<=110000000)
    {
        fib[n++]=z;
        //cout<<fib[n-1]<<" ";
        z=x+y;
        x=y;
        y=z;
    }
    fib[n++]=z;
    //cout<<endl;
}
int main()
{
    //freopen("file.txt","r",stdin);
    fibo();
    long long int i,j,k,l,W,F,S,a[1500],b[1500];
    while(scanf("%lld %lld %lld",&W,&F,&S)&&W&&F&&S)
    {
        //if(W==0&&F==0&&S==0)break;
        for(i=0;i<W;i++)
        {
            scanf("%lld",&a[i]);
            for(j=0;j<n;j++)
            {
                if(fib[j]==a[i])
                {
                    b[i]=0;
                    //cout<<fib[j]<<endl;
                    break;
                }/*
                else if(fib[j]>S)
                {
                    b[i]=-1;
                    cout<<fib[j]<<endl;
                    break;
                }*/
                else if(fib[j]>a[i])
                {
                    b[i]=fib[j]-a[i];
                    //cout<<fib[j]<<endl;
                    break;
                }
            }
        }
        //for( i=0;i<W;i++)cout<<b[i]<<" ";
        //cout<<endl;
        sort(b,b+W);
        //for( i=0;i<W;i++)cout<<b[i]<<" ";
        //cout<<endl;
        long long int cnt=0;
        for(i=0;i<W;i++)
        {
                if(b[i]==0)cnt++;
                else if(b[i]>F)break;
                else if(b[i]<=F)
                {
                    cnt++;
                    F=F-b[i];
                }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}