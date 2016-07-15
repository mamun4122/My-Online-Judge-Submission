#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct data
{
    int x,y;
};

bool cmp(const data &a,const data &b)
{
    if(a.y<b.y)return true;
    else if(a.y==b.y)
    {
        if(a.x>b.x)return true;
        else return false;
    }
    else return false;
}

int main()
{
    //freopen("out.txt","w",stdout);
    vector<data> v;
    data k;
    int cnt=0;
    k.x=1;
    k.y=1;
    v.push_back(k);
    for(int i=2;i<=1000;i++)
    {
        cnt=0;
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                if(i/j!=j)
                    cnt+=2;
                else
                    cnt++;
            }
        }
        k.x=i;
        k.y=cnt;
        v.push_back(k);
        //cout<<i<<" "<<cnt<<endl;
    }/*
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }*/
    sort(v.begin(),v.end(),cmp);
    /*for(int i=0;i<v.size();i++)
    {
        cout<<v[i].y<<" "<<v[i].x<<endl;
    }*/
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        printf("Case %d: %d\n",i,v[a-1].x);
    }
    return 0;
}
