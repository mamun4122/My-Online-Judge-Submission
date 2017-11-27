#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[2010];
bool b[2010];
struct data
{
    int x,y;
};
data z[2000];
bool cmp(const data &a,const data &b)
{
    if(a.x>b.x)return false;
    else if(a.x==b.x&&a.y>b.y)return false;
    else return true;
}

int main()
{
    int n,cnt=0,k,l,m,p;
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        z[i].x=a[i];
        z[i].y=i;
        if(b[a[i]]==0)
            b[a[i]]=1;
        else
        {
            cnt++;
            if(cnt==1)
                k=a[i];
            else if(cnt=2)
                l=a[i];
        }
    }
    sort(z,z+n,cmp);
    //cout<<k<<" "<<l<<endl;
    if(cnt>=2)
    {
        printf("YES\n");
        for(int i=0; i<n; i++)
        {
            if(z[i].x==k)m=i;
            cout<<z[i].y+1;
            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
        //cout<<m<<endl;
        for(int i=0; i<n; i++)
        {
            if(z[i].x==l)p=i;
            if(i!=m-1){
                cout<<z[i].y+1;
            }
            else
            {
                cout<<z[i+1].y+1<<" "<<z[i].y+1;
                i+=1;
            }

            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
        for(int i=0; i<n; i++)
        {
            //if(z[i].x==l)m=i;
            if(i!=p-1){
                cout<<z[i].y+1;
            }
            else
            {
                cout<<z[i+1].y+1<<" "<<z[i].y+1;
                i+=1;
            }

            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    else
        printf("NO\n");
    return 0;
}