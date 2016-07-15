#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void rev(char a[])
{
    int j= strlen(a);
    for(int i=0,k=j-1;i<j/2;i++,k--)
    {
        char b=a[k];
        a[k]=a[i];
        a[i]=b;
    }
}

int main()
{
    //freopen("file.txt","r",stdin);
    int x;
    cin>>x;
    getchar();
    while(x)
    {
        char a[105];
        char b[10][105];
        gets(a);
        int i,k,l;
        int j=strlen(a);
        int f=j/x;
        for(i=0,k=0,l=0;i<j;i++,k++)
        {
            if(i%f==0)
            {
                b[l][k]='\0';
                l++;
                k=0;
            }
            b[l][k]=a[i];
        }
        b[l][k]='\0';
        char c[105];
        for(i=0;i<=l;i++)
        {
            rev(b[i]);
            strcat(c,b[i]);
        }
        cout<<c<<endl;
        memset(a,NULL,sizeof(a));
        memset(b,NULL,sizeof(b));
        memset(c,NULL,sizeof(c));
        cin>>x;
        getchar();
    }
    return 0;
}
