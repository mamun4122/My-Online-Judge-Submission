#include <stdio.h>
int prime(int a)
{
    int i,mark=0;
    for (i=2; i<=a/2; i++)
    {
        if (a%i==0)
        {
            mark=1;
            break;
        }
    }
    return mark;
}
int main ()
{
    char a[20];
//gets (a);
    int i,sum;
    while (scanf ("%s",a) != EOF)
    {
        sum=0;
        for (i=0; a[i]!= '\0'; i++)
        {
            if (a[i]<= 'Z' && a[i]>='A')
            {
                sum=sum +a[i] -38;
            }
            if (a[i]<='z' && a[i]>= 'a')
            {
                sum=sum+a[i]-96;
            }
        }
        int p=prime(sum);
        if (p==0)
        {
            printf ("It is a prime word.\n");
        }
        if (p==1)
        {
            printf ("It is not a prime word.\n");
        }
    }
    return 0;
}

