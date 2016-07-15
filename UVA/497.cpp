#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
#include<stack>
#include<string.h>


int main()
{
//    freopen("file.txt","r",stdin);
//    freopen("file1.txt","w",stdout);
    stack<int> st;

    vector<int> v,res;
    int n,g;
    scanf("%d",&n);
    char c[100];
    getchar();
    getchar();
    for(int i=1; i<=n; i++)
    {
        int mx=1,m,ind=0,cnt=0;
        while(gets(c) && strcmp(c,""))
        {
            cnt=1;
            sscanf(c,"%d",&g);
            v.push_back(g);
            res.push_back(1);
            //cout<<g<<endl;
            //getchar();
        }
        if(cnt==1)
        {
            for(int i=0; i<v.size(); i++)
            {
                for(int j=i-1; j>=0; j--)
                {
                    if(v[i]>v[j])
                    {
                        res[i]=max(res[i],res[j]+1);
                        if(mx<res[i])
                        {
                            mx=res[i];
                        }
                    }
                }
            }
            for(int i=0;i<res.size();i++)
            {
                if(res[i]==mx)
                {
                    ind=i;
                    break;
                }
            }
            //cout<<mx<<endl;
            st.push(v[ind]);
            printf("Max hits: %d\n",mx--);
            for(int i=ind-1; i>=0; i--)
            {
                if(res[i]==mx&&v[ind]>v[i])
                {
                    st.push(v[i]);
                    ind=i;
                    mx--;
                }
            }
            while(!st.empty())
            {
                cout<<st.top()<<endl;
                st.pop();
            }
        }
    else
        printf("Max hits: 0\n");
    v.clear();
    res.clear();
    if(i!=n)
        cout<<endl;
}

return 0;
}
