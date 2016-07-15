#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return (a>b);
}

int main()
{
    int n,a,b;
    vector<int> v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(int j=1;j<=a;j++)
        {
            scanf("%d",&b);
            v.push_back(b);
        }
        sort(v.begin(),v.end(),cmp);
        int res=0;
        for(int j=2;j<a;j+=3)
        {
            res+=v[j];
            //cout<<v[j]<<" ";
        }
        //cout<<endl;
        printf("%d\n",res);
        v.clear();
    }

    return 0;
}
