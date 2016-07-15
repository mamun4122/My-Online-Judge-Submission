#include<cstdio>

int main()
{
//freopen("mam","r",stdin);
    int n,a,b,c,res;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        res=b+c;
        res=res%a;
        if(res<1)
            res+=a;

        printf("Case %d: %d\n",i,res);
    }

    return 0;
}
