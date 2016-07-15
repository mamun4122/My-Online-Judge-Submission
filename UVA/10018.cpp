#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
using namespace std;
char f[20];

char* rev(char a[])
{
    int j=strlen(a);
    for(int i=0,k=j-1; i<j/2; k--,i++)
    {
        char temp=a[k];
        a[k]=a[i];
        a[i]=temp;
    }
    return a;
}

void tostring(long long int x)
{
    memset(f,NULL,sizeof(f));
    int i=0;
    long long int a=x;
    while(a!=0)
    {
        f[i]=a%10+48;
        a=a/10;
        i++;
    }
    f[i]='\0';
    rev(f);
}

bool palindrome(char a[])
{
    int j=strlen(a);
    for(int i=0,k=j-1; i<j/2; i++,k--)
    {
        if(a[i]!=a[k])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    //freopen("file.txt","r",stdin);
    int n;
    cin>>n;
    for(int j=1; j<=n; j++)
    {
        char c[30],d[30];
        int i=0;
        long long int a,b,res;
        cin>>c;
        res=atoi(c);
        strcpy(d,c);
        rev(c);
x:
        if(!palindrome(c))
        {
            i++;
            a=atoi(c);
            b=atoi(d);
            res=a+b;
            tostring(res);
        }
        if(!palindrome(f))
        {
            strcpy(d,f);
            strcpy(c,rev(f));
            goto x;
        }
        else
        {
            cout<<i<<" "<<res<<endl;
        }
        memset(c,NULL,sizeof(c));
        memset(d,NULL,sizeof(d));
        memset(f,NULL,sizeof(f));
    }
    return 0;
}
