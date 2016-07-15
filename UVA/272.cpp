#include<stdio.h>
#include<iostream>
using namespace std;
#include<cstring>

int main()
{
    //freopen("file.txt","r",stdin);
    char a[1000];
    int flag=0,k;
    while(gets(a))
    {
        k=strlen(a);
        for(int i=0;i<k;i++)
        {
            if(a[i]=='"'&&flag==0)
            {
                printf("``");
                flag=1;
            }
            else if(a[i]=='"'&&flag==1)
            {
                printf("''");
                flag=0;
            }
            else
            {
                printf("%c",a[i]);
            }
        }
        printf("\n");
    }
}
