#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        long int n;
        int flag=0,j;
        scanf("%ld",&n);
        long int k=n;
        while(k!=0)
        {
            j=k%2;
            if(j==1)
            {
                flag++;
            }
            k=k/2;
        }
        if(flag%2==1)
        {
            printf("Case %d: odd\n",i);
        }
        else
        {
            printf("Case %d: even\n",i);
        }
    }
    return 0;
}

