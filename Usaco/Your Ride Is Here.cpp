/*
ID: mamun4122
LANG: C++
TASK: ride
*/
#include<stdio.h>
#include<string.h>

int main()
{
    freopen ("ride.in", "r",stdin);
    freopen ("ride.out", "w",stdout);
    char a[7],b[7];
    scanf("%s %s",&a,&b);
    int x=1,y=1,i;
    for(i=0;a[i]!='\0';i++)
    {
        x=x*(a[i]-64);
    }
    for(i=0;b[i]!='\0';i++)
    {
        y=y*(b[i]-64);
    }
    if(x%47==y%47)
    {
        printf("GO\n");
    }
    else
        printf("STAY\n");
    return 0;
}
