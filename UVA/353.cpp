#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

map<string,int> mp;


int palin(string s)
{
    int l=s.size()-1;
    for(int i=0;i<s.size()/2;i++)
    {
       if(s[i]!=s[l-i])
       return 0;
    }
    return 1;
}

int main()
{
    string s,str;
    int l,c,k;

    while(cin>>s)
    {
        l=s.size();
        mp.clear();
        c=0;
        for(int i=0;i<l;i++)
        {
            k=l-i;
           for(int j=1;j<=k;j++)
           {
               str=s.substr(i,j);
               //cout<<str<<endl;
               if(mp[str]>=1)
               continue;
               if(palin(str))
               {
                  mp[str]=1;
                  c++;
               }
           }
        }
        cout<<"The string "<<"\'"<<s<<"\'"<<" contains "<<c<<" palindromes.\n";

    }

    return 0;
}
