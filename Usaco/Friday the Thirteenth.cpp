/*
ID: mamun4122
LANG: C++
TASK: friday
*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;

bool leapyear(int n)
{
    if(n%2!=0)
        return false;
    if(n%400==0)
        return true;
    if(n%100==0)
        return false;
    if(n%4==0)
        return true;
    return false;
}

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int n;
    cin>>n;
    int d[7];
    memset(d,0,sizeof(d));
    int j=-3;
    for(int k=0; k<n; k++)
    {
        for(int i=1; i<=12; i++)
        {
            if(i==1||i==2||i==4||i==6||i==8||i==9||i==11){
                j=j+3;
                j=j%7;
                d[j]++;
            }
            else if(i==5||i==7||i==10||i==12)
            {
                j=j+2;
                j=j%7;
                d[j]++;
            }
            else if(leapyear(1900+k))
            {
                j++;
                j=j%7;
                d[j]++;
            }
            else
            {
                d[j]++;
            }
        }
    }
    for(int i=0;i<7;i++)
    {
        cout<<d[i];
        if(i!=6)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
