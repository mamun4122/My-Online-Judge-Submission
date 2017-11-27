#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;



int main()
{
    string s;
    while(cin>>s)
    {
        int a,b;
        cin>>a>>b;
        int first[s.size()],second[s.size()];
        memset(first,0,sizeof(first));
        memset(second,0,sizeof(second));
        int t=0;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            t=t*10+(s[i]-'0');
            t%=a;
            //cout<<t<<" "<<s[i]-'0'<<endl;
            first[i]=t;
        }
        t=0;
        int p=1;
        for(int i=len-1;i>=0;i--)
        {
            t=(t+(s[i]-'0')*p)%b;
            //cout<<t<<" ";
            second[i]=t;
            p=(p*10)%b;
        }
        int flag=0;
        for(int i=0;i<len-1;i++)
        {
            if(first[i]==0&&second[i+1]==0&&s[i+1]!='0')
            {
                puts("YES");
                string x=s.substr(0,i+1);
                string y=s.substr(i+1);
                cout<<x<<endl<<y<<endl;
                flag=1;
                break;
            }

        }
        if(!flag)puts("NO");

    }


    return 0;
}