#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

#define mx 10000000
#define ip freopen("in.txt","r",stdin)
#define op freopen("out.txt","w",stdout)

#define sint1(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sint3(a,b,c) scanf("%d %d %d",&a,&b,&c)



#define sch1(a) scanf("%c",&a)
#define sch2(a,b) scanf("%c %c",&a,&b)
#define sch3(a,b,c) scanf("%c %c %c",&a,&b,&c)



#define ll long long int

#define lpi0(a,b) for(int a=0;a<b;a++)
#define lpd0(a,b) for(int a=b-1;a>=0;a--)

#define lpi1(a,b) for(int a=1;a<=b;a++)
#define lpd1(a,b) for(int a=b;a>0;a--)

#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair

#define mm(a,b) memset(a,b,sizeof(a))



int main()
{
//    ip;
//    op;

    int a[300000];
    mm(a,0);
    a[0]=0;
    int k=1;
    for(int i=1;i<=10;i++)
    {
        if(k>25000)
            break;
        int u=k;
        for(int j=0;j<=u;j++)
        a[k++]=i;

//        cout<<k<<" "<<a[k]<<" "<<u<<endl;
        for(int l=u-1;l>=0;l--)
        {
            a[k++]=a[l];
        }

    }
//    cout<<k<<endl;
//    for(int i=0;i<100;i++)
//        cout<<a[i];

    int n;
    while(sint1(n)!=EOF)
    {
//        if(n>=21504)
//        {
//            for(int i=0;i<n;i++)
//            {
//                printf("0");
//            }
//            printf("\n");
//            continue;
//        }

        for(int i=0;i<n;i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }





}