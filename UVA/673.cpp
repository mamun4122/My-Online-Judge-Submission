#include<stdio.h>
#include<string.h>
#define sz 130
//#include<stack>
class stack
{
    char a[sz];
    int t;
public:
    stack()
    {
        t=0;
    }
    void push(char b)
    {
        a[t]=b;
        t++;
    }
    char pop()
    {
        return a[--t];
    }
    int top()
    {
        return t;
    }
    void del()
    {
        t=0;
        memset(a,NULL,sizeof(a));
    }
};

int main()
{
    //freopen("file.txt","r",stdin);
    int t;
    stack a;
    scanf("%d",&t);
    getchar();
    for(int k=1; k<=t; k++)
    {
        char d[130];
        memset(d,NULL,sizeof(d));
        gets(d);
        bool res=true;
        int j=strlen(d);
        if(j%2==0)
        {
            for(int i=0; i<j; i++)
            {
                if(d[i]=='('||d[i]=='[')
                {
                    a.push(d[i]);
                }
                else
                {
                    char f=a.pop();
                    if((d[i]==')'&&f!='(')||(d[i]==']'&&f!='['))
                    {
                        res=false;
                        break;
                    }
                }
            }
        }
        else
        {
            res=false;
        }
        if(a.top()!=0)
        {
            res=false;
        }
        if(res)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        a.del();
    }
    return 0;
}
