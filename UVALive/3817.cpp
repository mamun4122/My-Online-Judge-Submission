#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int sq[40]={0};
void pre()
{
     for(int i=1;i<=32;i++)
     sq[i]=i*i;


}
int main()
{
     //freopen("op.txt","r",stdin);
     //freopen("f.txt","w",stdout);
     pre();
     int i,j,k,t,l,rf,rl,cf,cl,p;
     string s,a[32][32],z;
     scanf("%d\n",&t);
     while(t--)
    {
         getline(cin,s);
         l=s.length();
         //cout<<l<<endl;
         i=0;
         while(sq[i]<l) i++;
         p=sq[i];
        for(i=l+1;i<=p;i++) s+='$';
         p=sqrt(p);
         rf=1; rl=p;
         cf=p; cl=1;
         l=0;

         while(rf<=rl)
         {
              i=rf;
              while(i<cf) {a[rf][i]=s[l++]; i++;}
              i=rf;

              while(i<rl) { a[i][cf]=s[l++]; i++;}
              i=cf;

              while(i>=cl) {a[rl][i]=s[l++]; i--; }
              i=rl-1;

              while(i>rf) {a[i][cl]=s[l++]; i--; }

              rf++; cf--;
              rl--; cl++;
         }

         for(i=1;i<=p;i++)
         {
              for(j=1;j<=p;j++)
                z+=a[i][j];
         }
        //cout<<z<<endl;
        int sz=z.size(),cnt=0;
        for(int k=sz-1;k>=0;k--)
        {
            if(z[k]==' ')
                cnt++;
            else
                break;
        }
        for(int k=0;k<sz-cnt;k++)
            cout<<z[k];
        cout<<endl;
        z.clear();
     }
     return 0;
}