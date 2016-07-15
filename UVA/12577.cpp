#include<stdio.h>
#include<string.h>

int main()
{
    char a[]={"Hajj-e-Akbar"};
    char b[]={"Hajj-e-Asghar"};
    char c[10];
    int i=1;
    scanf("%s",&c);
    while(1)
    {
        if(!strcmp(c,"*"))
        {
            break;
        }
        if(!strcmp(c,"Hajj"))
        {
            printf("Case %d: %s\n",i,a);
        }
        else{
            printf("Case %d: %s\n",i,b);
        }
        i++;
        scanf("%s",&c);
    }
}
