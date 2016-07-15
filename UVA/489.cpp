#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
//#include <>
//#include <>
//#include <>
//#include <>
//#include <>
//#include <>
//#include<>

#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d %d",&a,&b)
#define getIII(a,b,c) scanf("%d",&a,&b,&c)



using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        getchar();
        string a,b;
        getline(cin,a);
        getline(cin,b);
        int lena=a.size();
        int lenb=b.size();

        printf("Round %d\n",n);
        int let[26],error[26];
        memset(let,0,sizeof(let));
        memset(error,0,sizeof(error));
        int uni=0,mflg=1;
        for(int i=0;i<lena;i++)
        {
            int k=a[i]-'a';
            if(let[k]==0) uni++;
            let[k]=1;
        }
        int err=0;
        for(int i=0;i<lenb;i++)
        {
            int k=b[i]-'a';
            if(let[k]==0 && error[k]==0)
            {
                err++;
                error[k]=1;
            }
            else if(let[k]==1)
            {
                uni--;
                let[k]=-1;
            }
            if(err>=7 && uni>0)
            {
                mflg=0;
            }
        }

        if(uni==0 && mflg)
        {
            printf("You win.\n");
        }
        else if(uni!=0 && err<7)
        {
            printf("You chickened out.\n");
        }
        else
        {
            printf("You lose.\n");
        }
    }


    return 0;
}


