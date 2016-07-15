#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    char a[1000];
    while(gets(a))
    {
        int k=0;
        int j=strlen(a);
        for(int i=0;i<j;i++)
        {
            if(((a[i]<'A'||a[i]>'z')||(a[i]<'a'&&a[i]>'Z'))&&((a[i-1]>='A'&&a[i-1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z')))
                //cout<<a[i-1]<<endl;
                k++;
        }
        cout<<k<<endl;
    }
    return 0;
}

