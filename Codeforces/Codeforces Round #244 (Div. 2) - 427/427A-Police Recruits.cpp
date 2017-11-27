#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>

int main()
{
    //freopen("file.txt","r",stdin);
    int n,k,p=0,res=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&k);
            if(k>0)
            {
                p+=k;
            }
            else
            {
                if(p>0)
                {
                    p--;
                }
                else
                {
                    res++;
                }
            }

        }
        printf("%d\n",res);
        p=0;res=0;
    }
    return 0;
}