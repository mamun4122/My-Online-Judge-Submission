#include<cstdio>

int main()
{
    int a,b,res;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        res=a;
        while(a>=b)
        {
            res=res+(a/b);
            a=(a/b)+(a%b);
        }
        printf("%d\n",res);
    }

    return 0;
}
