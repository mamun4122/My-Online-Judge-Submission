#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d: ",i);
        int a[3];
        int x1,x2,x3,x4;
        cin>>x1>>x2>>x3>>x4>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        float res=x1+x2+x3+x4+((float)(a[1]+a[2])/2);
        if(res>= 90)cout<<"A"<<endl;
        else if(res >= 80 && res< 90)cout<<"B"<<endl;
        else if(res >= 70 && res< 80)cout<<"C"<<endl;
        else if (res>= 60 && res< 70)cout<<"D"<<endl;
        else if  (res < 60)cout<<"F"<<endl;
    }
    return 0;
}
