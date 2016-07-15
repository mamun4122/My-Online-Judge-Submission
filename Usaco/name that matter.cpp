/*
ID: mamun4122
LANG: C++
TASK: namenum
*/
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<map>
#include<string.h>
using namespace std;


int main()
{
//    freopen("namenum.in","r",stdin);
//    freopen("namenum.out","w",stdout);
    map<char,char> m;
    m['A']=m['B']=m['C']='2';
    m['D']=m['E']=m['F']='3';
    m['G']=m['H']=m['I']='4';
    m['J']=m['K']=m['L']='5';
    m['M']=m['N']=m['O']='6';
    m['P']=m['R']=m['S']='7';
    m['T']=m['U']=m['V']='8';
    m['W']=m['X']=m['Y']='9';
    ifstream in1;
    ifstream in2;
    ofstream out;
    in1.open("namenum.in");
    char a[20],c[20];
    in1>>a;
    in1.close();
    int b=strlen(a),x,f=0,z=0;
    in2.open("dict.txt");
    out.open("namenum.out");
    for(int i=0,k;i<5000;i++)
    {
        in2>>c;
        x=strlen(c);
        if(x==b)
        {
            for(k=0;k<x;k++)
            {
                if(m[c[k]]==a[k])
                {
                    f=1;
                }
                else
                {
                    f=0;break;
                }
            }
            if(f==1){
                    z=1;
                out<<c<<endl;
            }
        }
    }
    in2.close();

    if(z==0)
        out<<"NONE"<<endl;
    out.close();
    return 0;
}
