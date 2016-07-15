#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>

int main()
{
    //freopen("file.txt","r",stdin);
    //freopen("file1.txt","w",stdout);
    vector<int> v;
    int n,x,y;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {

        scanf("%d",&x);
        for(int j=1; j<=x; j++)
        {
            scanf("%d",&y);
            v.push_back(y);
        }
        printf("Case %d: ",i);
        if(x<11)
        {
            printf("go home!");
        }
        else
        {
            int cnt=11,k=0,l=x-10;
            while(cnt!=0)
            {
                int mx=k;
                for(;k<l; k++)
                {
                    if(v[k]>v[mx])
                    {
                        mx=k;
                    }
                }
                printf("%d",v[mx]);
                k=mx+1;
                cnt--;
                if(cnt!=0)
                    printf(" ");
                l++;
            }
        }
        printf("\n");
        v .clear();
    }

    return 0;
}
