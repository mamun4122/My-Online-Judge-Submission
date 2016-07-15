#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int T,x,y;
    scanf("%d",&T);
    for(int z=1; z<=T; z++)
    {
        char a[1000000];
        scanf("%s",&a);
        int low=0,high=strlen(a)-1,flag=0;
        while(low<high)
        {
            if(a[low]!=a[high])
            {
                flag=1;
                break;
            }
            low++;
            high--;
        }
        if(flag==1)
        {
            printf("Case %d: No\n",z);
        }
        else
        {
            printf("Case %d: Yes\n",z);
        }

    }
    return 0;
}
