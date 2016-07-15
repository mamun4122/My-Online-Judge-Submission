/*
ID: mamun4122
LANG: C++
TASK: milk2
*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);

    int n;
    scanf("%d",&n);
    int a,b,res1=0,res2=0,x1=0,y1=0,f=0;
    multimap<int,int> m;
    multimap<int,int>::iterator it;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a,&b);
        m.insert(pair<int,int>(a,b));
    }
    //int k=0;
    for(it=m.begin(); it!=m.end(); it++)
    {
        //k++;
        //cout<<it->first<<" "<<it->second<<endl;
        if(f!=0)
        {
            if(it->first>y1)
            {
                res1=max(res1,it->first-y1);
                res2=max(res2,y1-x1);
                //cout<<"here"<<x1<<" "<<y1<<endl;
                x1=it->first;
                y1=it->second;
            }
            else
            {
                y1=max(y1,it->second);
                res2=max(res2,y1-x1);
            }
        }
        else
        {
            x1=it->first;
            y1=it->second;
            res2=max(res2,y1-x1);
            f=1;
        }

    }
    //res2=max(res2,y1-x1);
    cout<<res2<<" "<<res1<<endl;
    //cout<<k;
    m.clear();
    return 0;
}
