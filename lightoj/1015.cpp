#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        //printf("\n");
        int N;
        scanf("%d",&N);
        int sum=0;
        int ara[1000];
        for(int j=0; j<N; j++)
        {
            int ara[j];
            scanf("%d",&ara[j]);
            if(ara[j]>=0)
            {
                sum=sum+ara[j];
            }
        }
        printf("Case %d: %d\n",i,sum);

    }
    return 0;
}

