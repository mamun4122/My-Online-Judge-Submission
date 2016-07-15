#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>
const int inf=20000000;


struct data
{
    int l;
    int m;
    //bool operator<()
};
bool cmp(data a,data b)
{
     if(a.l<b.l)return true;
     else if(a.l==b.l)return (a.m<b.m);
     else return false;
}


int main()
{
    //freopen("file.txt","r",stdin);
    vector<int>res,x;
    vector<data> v;
    int n,a,b;
    data z;
    while(scanf("%d",&n)&&n)
    {
        x.push_back(-inf);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&z.l,&z.m);
            v.push_back(z);
            x.push_back(inf);
        }
        int length=0;
        sort(v.begin(),v.end(),cmp);
        //cout<<v[1].l<<endl;
        for(int i=0; i<v.size(); i++)
        {
            //cout<<v[i].l<<" "<<v[i].m<<endl;
            int low=0,high=length,mid;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(x[mid]==v[i].m)
                {
                    low=mid+1;
                }
                else if(x[mid]<v[i].m)
                    low=mid+1;
                else
                    high=mid-1;
            }
            x[low]=v[i].m;
            //cout<<low<<endl;
            if(length<low)
                length=low;
            res.push_back(low);
        }
        printf("%d\n",length);
        v.clear();
        x.clear();
        res.clear();
    }
    printf("*\n");
    return 0;
}
