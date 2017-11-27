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

    int s;
    vector<int>B;
    vector<int>R;


    while(sint1(s)!=EOF)
    {
        R.clear();
        B.clear();

        for(int i=0;i<s;i++)
        {
            int x;
            char p;
            scanf("%d %c",&x,&p);
//            cout<<x<<p<<endl;
            if(p=='B')
            {
                B.push_back(x);
            }
            else
            {
                R.push_back(x);
            }
            getchar();
        }

        int ans=0;

        sort(B.begin(),B.end());
        sort(R.begin(),R.end());

        reverse(B.begin(),B.end());
        reverse(R.begin(),R.end());


        for(int i=0;i<B.size()&&i<R.size();i++)
        {
            ans=ans+B[i]+R[i]-2;
        }

        cout<<ans<<endl;

    }





}