#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    int x,y,mx=0,cnt,flag,z,i,j;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        mx=0;
        i=min(x,y);
        z=i;
        j=max(x,y);
        for(; z<=j; z++)
        {
            i=z;
            flag=0;
            cnt=0;
            cnt++;
            while(i!=1)
            {
                flag=1;
                cnt++;
                if(i%2==1)
                {
                    i=3*i+1;
                }
                else
                {
                    i=i/2;
                }
            }
            //if(flag==1)cnt++;
            if(cnt>mx)mx=cnt;
        }
        printf("%d %d %d\n",x,y,mx);
    }
    return 0;
}
