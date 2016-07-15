#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#include <map>

int main()
{
    map<long long int,int> mymap;
    map<long long int,int>::iterator it;
    int n,a[5],x,maximum,flag;
    long long int sum,b=1000000000000,c=1000000000;
    while (scanf("%d",&n)&&n) {
        x=0;flag=0;
        maximum=0;
        for(int i=0;i<n;i++)
        {
            for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
            }
            
        sort(a, a+5);
            /*for(int i=0;i<5;i++){
                printf("%d ",a[i]);
            }
            cout<<endl;*/
            sum=a[0]*b+a[1]*c+a[2]*1000000+a[3]*1000+a[4];
        //cout<<sum<<endl;
        if(mymap.find(sum)==mymap.end())
        {
            mymap[sum]=1;
            x++;
        }
        else{
            mymap[sum]++;
            if(maximum<mymap[sum]){
                maximum=mymap[sum];
                flag=0;
            }
            else if(maximum==mymap[sum])
                flag++;
        }

        }
       // cout<<x<<endl;
        if(x==n)
        {
            printf("%d\n",n);
        }
        else if(flag!=0)
        {
            printf("%d\n",maximum*(flag+1));
        }
        else{
            printf("%d\n",maximum);
        }
        mymap.clear();
        memset(a,0,sizeof(a));
    }
    return  0;
}