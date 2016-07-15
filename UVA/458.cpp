#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    char a[1000];
    while(gets(a))
    {
        int j=strlen(a);
        for(int i=0;i<j;i++)
        {
            printf("%c",a[i]-7);
        }
        cout<<endl;
    }

    return 0;
}

