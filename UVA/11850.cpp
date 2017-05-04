#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    int f;
    //int sum1=0,sum2;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        f=0;
        int a[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
//        for(int i=0; i<n-1; i++)
//        {
//            for(int j=n-1; j>i; j--)
//            {
//                if(a[i]>a[j])
//                {
//                    swap(a[j-1],a[j]);
//                }
//            }
//        }
        sort(a,a+n);
        /*for(int i=0; i<n; i++)
        {
            printf("%d",a[i]);
        }*/
        //printf("\n%d",1422-a[n-1]);
        if( 2*(1422-a[n-1]) > 200 )
        {
            f=1;
        }
       else
        {
            for(int i=0; i<n-1; i++)
            {
                //sum1=sum1+a[i];
                //sum2=sum2+200;
                if(a[i]+200<a[i+1])    //sum1>sum2
                {
                    f=1;
                    break;
                }
            }
        }

        if(f)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            printf("POSSIBLE\n");
        }
    }
    return 0;
}

