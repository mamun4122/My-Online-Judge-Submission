#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[]={0,1,0,-1,1,1,-1,-1};
int b[]={1,0,-1,0,-1,1,-1,1};

int main()
{
    //freopen("mam","r",stdin);
    //freopen("mamu","w",stdout);
    int m,n,t=1,i,j,k;
    int x[105][105];
    //char y[105][105];
    char c;
    while(scanf("%d%d ",&m,&n)&&(m||n))
    {
        if(t>1)printf("\n");
        memset(x,0,sizeof(x));
        printf("Field #%d:\n",t++);
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%c",&c);
                if(c=='*')
                {
                    x[i][j]=-1;
                    for(k=0;k<8;k++)
                    {
                        if(x[i+a[k]][j+b[k]]!=-1)
                        {
                            x[i+a[k]][j+b[k]]++;
                        }
                    }
                }
            }
            getchar();
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(x[i][j]==-1)
                {
                    printf("*");
                }
                else
                {
                    printf("%d",x[i][j]);
                }
            }
            printf("\n");
        }


    }
    return 0;
}
