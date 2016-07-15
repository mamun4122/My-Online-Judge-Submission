#include<stdio.h>

int main()
{
    int j;
    scanf("%d",&j);
    char a[j+1][100];
    for(int i=1;i<=j;i++)
    {
        scanf("%s",&a[i]);
    }
    char b[16][10]={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"};
    int k=j/16;
    k=k+1;
    k=k*16;
    for(int i=0;i<k;i++)
    {
        printf("%s: %s\n",a[(i%j)+1],b[i%16]);
    }
    return 0;
}
