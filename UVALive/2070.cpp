#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;



int main()
{
    //freopen("file.txt","r",stdin);
    char a[201];
    bool b[201];
    //char c[201][201];
    int n,len;
    while(scanf("%d",&n)&&n)
    {
        getchar();
        memset(b,0,sizeof(b));
        gets(a);
        //cout<<a<<endl;
        len=strlen(a);
        int row=len/n,k,l,m,flag=0;
        for(int j=0;j<len;j++)
        {
            if(!b[j]){
                b[j]=1;
                flag=0;
                printf("%c",a[j]);
                l=j+n-1;
                while(j>0&&!b[l]&&l<len)
                {
                    if(l%n==0){
                        flag=1;
                    }
                    printf("%c",a[l]);
                    b[l]=1;
                    if(flag)
                        break;

                    l=l+n-1;

                }
            }
        }
        printf("\n");

    }


    return 0;
}