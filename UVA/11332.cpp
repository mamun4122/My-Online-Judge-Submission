#include<stdio.h>
#include<cstring>

int main()
{
    char a[15];
    int k,sum,x,j;
    while(gets(a))
    {
        if(a[0]=='0')break;
        k=strlen(a);
        while(k!=1)
        {
            sum=0;
            j=0;
            for(int i=0;i<k;i++)
            {
                sum+=a[i]-48;
            }
            memset(a,NULL,sizeof(a));
            x=sum;
            while(x!=0)
            {
                a[j]=x%10+48;
                x=x/10;
                j++;
            }
            a[j]='\0';
            k=strlen(a);
        }
        printf("%s\n",a);
        memset(a,NULL,sizeof(a));
    }
    return 0;
}
