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

    int t;
    sint1(t);

    while(t--)
    {
        int n,m;

        sint2(n,m);

        if(n%2==0&&m%3==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        if(n%3==0&&m%2==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        if(n%2==0&&n%3==0)
        {
            int c=m;
            int flag=0;
            while(c>=0)
            {
                if(c%2==0)
                {
                    flag=1;
                    break;
                }
                c=c-3;
            }

            if(flag==1)
            {
                cout<<"Yes"<<endl;
                continue;
            }
        }


        if(m%2==0&&m%3==0)
        {
            int c=n;
            int flag=0;
            while(c>=0)
            {
                if(c%2==0)
                {
                    flag=1;
                    break;
                }
                c=c-3;
            }

            if(flag==1)
            {
                cout<<"Yes"<<endl;
                continue;
            }
        }


        cout<<"No"<<endl;
    }





}