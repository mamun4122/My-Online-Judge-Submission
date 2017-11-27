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

    char s[100000];

    while(cin>>s)
    {
//        cout<<s<<endl;
        int dp[30];
        mm(dp,0);
        int l=strlen(s);
        if(l<26)
        {
            cout<<"-1"<<endl;
            continue;
        }

        int cnt=0;
        int faka=26;
        for(int i=0;i<26;i++)
        {
            if(s[i]=='?')
            {
                cnt++;
                faka--;
            }
            else if(dp[s[i]-65]>=1)
            {
                dp[s[i]-65]++;
            }
            else
            {
                dp[s[i]-65]++;
                faka--;
            }
//            cout<<cnt<<" "<<faka<<" "<<s[i]<<endl;
//            cout<<i<<" "<<faka<<endl;
        }
        int f=0;
         if(faka==0)
            f=26;
//        cout<<dp[2]<<endl;
        for(int i=26;i<l;i++)
        {
            if(faka==0)
            {
                f=i;
                break;
            }

            if(s[i]=='?')
            {
                cnt++;
                faka--;
            }
            else if(dp[s[i]-65]>=1)
            {
                dp[s[i]-65]++;
            }
            else
            {
                dp[s[i]-65]=1;
                faka--;
            }

            if(s[i-26]=='?')
            {
                cnt--;
                faka++;
            }
            else if(dp[s[i-26]-65]>1)
            {
                dp[s[i-26]-65]--;
            }
            else if(dp[s[i-26]-65])
            {
                dp[s[i-26]-65]=0;
                faka++;
            }
//            cout<<cnt<<" "<<faka<<" "<<s[i]<<endl;
//            cout<<i<<" "<<faka<<endl;
            if(faka==0)
            {
                f=i+1;
                break;
            }


        }
        if(f==0&&faka!=0)
        {
            cout<<"-1"<<endl;
            continue;
        }
//        cout<<f<<endl;

//        for(int i=0;i<26;i++)
//            printf("%c %d\n",i+65,dp[i]);
        for(int i=0;i<f-26;i++)
        {
            if(s[i]=='?')
                cout<<"A";
            else
                cout<<s[i];
        }

        for(int i=f-26;i<f;i++)
        {
            if(s[i]=='?')
            {
                for(int j=0;j<26;j++)
                {
                    if(dp[j]==0)
                    {
                        dp[j]=1;
                        printf("%c",j+65);
                        break;
                    }
                }
            }
            else
            {
                cout<<s[i];
            }
        }

        for(int i=f;i<l;i++)
        {
            if(s[i]=='?')
                cout<<"A";
            else
                cout<<s[i];
        }
        cout<<endl;



    }




}