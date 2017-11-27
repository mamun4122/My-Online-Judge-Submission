#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    char p[20],q[20],c[20];
    long long int a,b,res,x,y,z,i,j,k;
     i=0;
    cin>>a>>b;
    res=a+b;
    x=a;
    while(x!=0)
    {
        if(x%10!=0)
        {
            p[i]=x%10+48;
            i++;
        }
        x=x/10;
    }
    p[i]='\0';
    strrev(p);
    i=0;x=b;
    while(x!=0)
    {
        if(x%10!=0)
        {
            q[i]=x%10+48;
            i++;
        }
        x=x/10;
    }
    q[i]='\0';
    strrev(q);
    x=res;
    i=0;
    while(x!=0)
    {
        if(x%10!=0)
        {
            c[i]=x%10+48;
            i++;
        }
        x=x/10;
    }
    c[i]='\0';
    strrev(c);
    y=atoi(p)+atoi(q);
    z=atoi(c);
    //cout<<y<<" "<<z<<endl;
    if(y==z)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}