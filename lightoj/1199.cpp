#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
int dp[10010];
bool mark[10010];

void precal()
{

      int x,j,k=0,sz,flag;
      dp[0]=0;dp[1]=0;dp[2]=0;
      for(int i=3;i<=10000;i++)
      {
            memset(mark,0,sizeof(mark));
            j=1;
            x=i/2;
            while(j<=x)
            {
                  if(i-j!=j)
                  {
                        mark[dp[j]^dp[i-j]]=1;
                  }
                  j++;
            }
            k=0;
            while(k<10010)
            {
                  if(!mark[k])
                  {
                        break;
                  }
                  k++;
            }
            dp[i]=k;
            //cout<<i<<" "<<dp[i]<<endl;

      }
}

int main()
{

      //freopen("out.txt","w",stdout);
      precal();
      int t,x,sum,caseno=1;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
            {
                  scanf("%d",&x);
                  if(i==1)sum=x;
                  else if(i==2)sum=dp[sum]^dp[x];
                  else sum=sum^dp[x];
            }
            if(n==1||sum==0)
                  printf("Case %d: Bob\n",caseno++);
            else
                  printf("Case %d: Alice\n",caseno++);
      }

      return 0;
}