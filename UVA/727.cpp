#include<iostream>
#include<stack>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    //freopen("f.txt","w",stdout);
    int n,j=0;
    scanf("%d",&n);
    getchar();
    getchar();
    map<char,int> m;
    m['+']=1;
    m['-']=1;
    m['*']=3;
    m['/']=3;
    stack<char> st;
    char x[100];
    char c,z;
    for(int i=1; i<=n; i++)
    {
        j=0;
        st.push('(');
        while((c=getchar())!=EOF&&c!='\n')
        {
            //cout<<c;
            if(c=='(')
                st.push(c);
            else if(c==')')
            {
                z=st.top();
                while(z!='(')
                {
                    //cout<<z;
                    x[j++]=z;
                    st.pop();
                    z=st.top();
                }
                st.pop();
            }
            else if(m.find(c)==m.end())
            {
                //cout<<c;
                x[j++]=c;
            }
            else
            {
                z=st.top();
                while(z!='('&&m[z]>=m[c])
                {
                    //cout<<z;
                    x[j++]=z;
                    st.pop();
                    z=st.top();
                }
                st.push(c);
            }
            getchar();
        }

        while(!st.empty())
        {
            z=st.top();
            if(z=='(')
            {
                st.pop();
            }
            else
            {
                //cout<<z;
                x[j++]=z;
                st.pop();
            }
        }
        x[j]='\0';
        cout<<x<<endl;
        if(i!=n)
            printf("\n");
    }
    return 0;
}
