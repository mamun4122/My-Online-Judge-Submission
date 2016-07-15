#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
   //freopen("file.txt","r",stdin);
    char a[100][100];
    int len[100],mx=0;
    int i=0;
    while(gets(a[i]))
    {
        //getchar();
        //puts(a[i]);
        len[i]=strlen(a[i]);
        if(mx<len[i])
            mx=len[i];
        i++;
    }
    /*int len[i],mx=0;
    for(int j=0; j<i; j++)
    {
        len[j]=strlen(a[j]);
    }*/

    for(int k=0; k<mx; k++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(k<len[j])
                cout<<a[j][k];
            else
                cout<<" ";
        }
        cout<<endl;
    }
   return 0;
}
