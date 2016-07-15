#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;


int main()
{
    //freopen("file.txt","r",stdin);
    int t,a[405],f=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int c,d,flag=0;
        printf("Case %d:\n",f++);
        while(scanf("%d%d",&c,&d)&&c&&d)
        {
            flag=0;
            int cnt1=0,cnt2=0;
            for(int i=1; i<=n; i++)
            {
                if(a[i]>=c)
                    cnt1++;
                else
                    cnt1=0;
                if(a[i]>=d)
                    cnt2++;
                else
                    cnt2=0;
                if(cnt1==d||cnt2==c)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                printf("Accept\n");
            else
                printf("Reject\n");
        }
    }

    return 0;
}
