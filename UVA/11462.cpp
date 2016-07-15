#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,x;
    scanf("%d",&n);
    vector<int>v;
    //vector<int>c;
    //vector<int>d;
    while(n)
    {

        /*for(int i=0; i<n; i++)
        {
            c.push_back(0);
            v.push_back(0);
        }*/
        for(int i=0; i<n; i++)
        {
            //scanf("%d",&v[i]);
            cin>>x;
            v.push_back(x);
            //c[v[i]]++;
        }
        sort(v.begin(),v.end());
        /*for(int i=0; i<n; i++)
        {
            c[v[i]]++;
        }
        for(int i=1; i<n; i++)
        {
            c[i]=c[i]+c[i-1];
        }
        for(int i=n-1; i>=0; i--)
        {
            d[c[v[i]]]=v[i];
            c[v[i]]--;
        }*/
        for(int i=0; i<v.size(); i++)
        {
            printf("%d",v[i]);
            if(i!=n-1)
            {
                printf(" ");
            }
        }
        cout<<endl;
        v.clear();
        scanf("%d",&n);
    }
    return 0;
}
