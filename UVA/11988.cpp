#include<stdio.h>
#include<iostream>
using namespace std;
#include<stack>
#include<list>
#include<string.h>

int main()
{
    //freopen("file.txt","r",stdin);
    char a[100001],d;
    int c,flag;
    stack<char> st;
    list<char> lst;
    list<char>::iterator it;
    while(gets(a))
    {
        c=strlen(a);
        flag=0;
        for(int i=0; i<c; i++)
        {
            if(a[i]=='[')
            {
                flag=1;
                while(!st.empty())
                {
                    lst.push_front(st.top());
                    st.pop();
                }
            }
            else if(a[i]==']')
            {
                if(flag==1)
                {
                    while(!st.empty())
                    {
                        lst.push_front(st.top());
                        st.pop();
                    }
                }
                flag=0;
            }
            else if(flag==1)
            {
                st.push(a[i]);
            }

            else
            {
                lst.push_back(a[i]);
                flag=0;
            }
        }
        while(!st.empty())
        {
            lst.push_front(st.top());
            st.pop();
        }
        for(it=lst.begin();it!=lst.end();it++)
        {
            cout<<*it;
        }
        printf("\n");
        lst.clear();
        //st.clear();

    }
    return 0;
}

