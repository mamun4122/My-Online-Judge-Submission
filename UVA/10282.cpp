#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
using namespace std;


int main()
{
    //freopen("file.txt","r",stdin);
    char c[30];
    char a[30],b[30],d[30];
    map<string,string> m;
    map<string,string>::iterator it;
    while(gets(c))
    {
        int flag=0;
        if(sscanf(c,"%s%s",&a,&b)==2)
        {
            m[b]=a;
        }
        else
        {
            if(c[0]!=NULL)
            {
                sscanf(c,"%s",&d);
                it=m.find(d);
                if(it!=m.end())
                {
                    cout<<it->second<<endl;
                }
                else
                {
                    cout<<"eh"<<endl;
                }
            }
        }
    }
    return 0;
}

