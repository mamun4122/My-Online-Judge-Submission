/*
ID: mamun4122
LANG: C++
TASK: beads
*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;


int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    char *a,x;
    int n;
    cin>>n;
    a=new char(n+1);
    cin>>a;
    //cout<<a<<endl;
    int flag1=0,flag2=0,res=0,temp=0,l,j;
    for(int i=0;i<n;i++)
    {
        //cout<<i<<endl;
        for(int k=i;k<(n+i);k++)
        {
            //cout<<a[k];
            j=k%n;
            //cout<<a[k]<<endl;
            l=k-1;
            if(l<0)
                l=0;
            if(flag1==0&&a[j]!='w')
             {
                 //cout<<a[k];
                 temp++;
                flag1=1;
                 x=a[j];
             }
            else if(a[j]=='w'){
                temp++;//cout<<a[k];
            }
            else if((a[l%n]=='w'||a[l%n]==x)&&(a[j]==x||a[j]=='w')){
                temp++;//cout<<a[k];
            }
            else if(flag2==0)
            {
                flag2=1;x=a[j];
                temp++;//cout<<a[k];
            }
            else
                break;

        }
        //cout<<endl;
        if(temp>res)
            res=temp;
        flag1=0;flag2=0;temp=0;
    }
    cout<<res<<endl;
    return 0;
}
