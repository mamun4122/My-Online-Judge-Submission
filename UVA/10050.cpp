#include <iostream>
#include <cstring>
#include <cstdio>
using namespace  std;
bool wk[3659];
bool fr[3659];
int main()
{
    int t,nmbr,n,day;
    int l=-1;
    while(l<=3651)
    {
        l=l+7;
        fr[l]=1;
    }
    scanf("%d",&t);
    for (int i=1; i<=t; i++)
    {
        int res=0;
        memset(wk,0,sizeof(wk));
        scanf("%d",&nmbr);
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            int x=0;
            scanf("%d",&day);
            while(1)
            {
                x=x+day;
                if(x>nmbr)break;
                if(wk[x]==0&&x%7!=0&&fr[x]==0)
                {
                    res++;
                    wk[x]=1;
                    //cout<<x<<endl;
                }
            }
            //cout<<res<<endl;
        }
        printf("%d\n",res);

    }
    return  0;
}