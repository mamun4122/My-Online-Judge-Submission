#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    //freopen("file.txt","r",stdin);
    long long int N,P,T,R,i,t_n,p_n,j,s,tm[500],k[100],mx,l,t,sub[401][13];
    char b[100];
    while(scanf("%lld %lld %lld %lld",&N,&P,&T,&R)!=EOF)
    {
        if(N==0&&P==0&&T==0&&R==0)break;
        for(i=1;i<=P;i++)scanf("%lld",&k[i]);
        //for(i=0;i<400;i++)tm[i]=0;
        memset(tm,0,sizeof(tm));
        memset(sub,0,sizeof(sub));
        t=0;
        for(i=0;i<R;i++)
        {
            scanf("%lld %lld %s %lld",&t_n,&p_n,b,&j);
            if(j==0&&!sub[t_n][p_n])
            {
                tm[t_n]+=k[p_n];
                sub[t_n][p_n]=1;
                if(t_n>t)t=t_n;
            }
        }
        mx=0;
        for(i=0;i<=t;i++)
        {
            if(tm[i]>mx)mx=tm[i];
        }
        printf("Contest %lld Winner: ",N);
        l=0;
        for(i=0;i<=t;i++)
        {
            if(tm[i]==mx&&l==0)
            {
                printf("Team %lld",i);
                l=1;
            }
            else if(tm[i]==mx&&l==01)printf(" and Team %lld",i);
        }
        printf("\n");
    }
    return 0;
}