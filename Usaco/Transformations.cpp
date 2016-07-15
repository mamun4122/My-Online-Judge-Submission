/*
ID: mamun4122
LANG: C++
TASK: transform
*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;
int n;
char a[11][11];
char b[11][11];
char c[11][11];
//int d=1;

bool check1()
{
    //cout<<d++<<endl;
    int j,k;
    for(int i=0;i<n;i++)
    {
        for(j=n-1,k=0;j>=0;j--,k++)
        {
            if(a[j][i]!=b[i][k])
            {
                return false;
            }
        }
    }
    return true;
}
bool check2()
{
    //cout<<d++<<endl;
    int j,k;
    for(int i=0,l=n-1;i<n;i++,l--)
    {
        for(j=n-1,k=0;j>=0;j--,k++)
        {
            if(a[l][j]!=b[i][k])
            {
                return false;
            }
        }
    }
    return true;
}
bool check3()
{
    //cout<<d++<<endl;
    int j,k;
    for(int i=0,l=n-1;i<n;l--,i++)
    {
        for(k=0;k<n;k++)
        {
            if(a[k][l]!=b[i][k])
            {
                return false;
            }
        }
    }
    return true;
}
bool check4()
{
    //cout<<d++<<endl;
    int j,k,l;
    for(int i=0;i<n;i++)
    {
        for(k=0,l=n-1;l>=0;l--,k++)
        {
            if(a[i][l]!=b[i][k])
            {
                return false;
            }
        }
    }
    return true;
}
bool check5()
{

    int j,k,l;
    for(int i=0;i<n;i++)
    {
        for(k=0,l=n-1;l>=0;l--,k++)
        {
            c[i][k]=a[i][l];
        }
        c[i][k]='\0';
        //cout<<c[i]<<endl;
    }
    for(k=0;k<n;k++)
        strcpy(a[k],c[k]);
    //cout<<d++<<endl;
    if(check1())
        return true;
    else if(check2())
        return true;
    else if(check3())
        return true;
    else
        return false;
}


int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d",&n);
    int f=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s\n",a[i]);
       // cout<<a[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s\n",b[i]);
       // cout<<b[i]<<endl;
        if(strcmp(a[i],b[i])!=0)
            f=1;
    }
    if(check1())
        cout<<"1"<<endl;
    else if(check2())
        cout<<"2"<<endl;
    else if(check3())
        cout<<"3"<<endl;
    else if(check4())
        cout<<"4"<<endl;
    else if(check5())
        cout<<"5"<<endl;
    else if(f==0)
        cout<<"6"<<endl;
    else
        cout<<"7"<<endl;
    return 0;
}
