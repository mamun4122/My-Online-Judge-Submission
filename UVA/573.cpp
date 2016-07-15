#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    //cin>>h;
    int h,u,d,f;
    while(scanf("%d%d%d%d",&h,&u,&d,&f)&&h)
    {
        //cin>>u>>d>>f;
        //scanf("%d%d%d",&u,&d,&f);
        float res=0.0,fact=(float)f/100;
        float k=(float)u;
        fact=fact*u;
        int i=0,flag=1;
        while(1)
        {
            i++;
            if(k>0)
            {
                res=res+k;
                if(res>h)
                {
                    flag=1;
                    break;
                }
            }
            res=res-d;
            if(res<0)
            {
                flag=0;
                break;
            }
            k=k-fact;
        }
        if(flag==1)
        {
            printf("success on day %d\n",i);
        }
        else
        {
            printf("failure on day %d\n",i);
        }
        //cin>>h;
        //scanf("%d",&h);
    }
    return 0;
}
