#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;

int main()
{
    //freopen("file.txt","r",stdin);
    int n;
    cin>>n;
    char a[75],b[75];
    set<string> s1;
    map<string,int> s2;
    map<string,int>:: iterator it2;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a);
        gets(b);
        s1.insert(a);
        it2=s2.begin();
        it2=s2.find(a);
        if(it2!=s2.end())
        {
            it2->second++;
        }
        else
        {
            //s1.insert(a,0);
            s2[a]=1;
        }
    }
    set<string>::iterator it1;
    for(it1=s1.begin();it1!=s1.end();it1++ )
    {
        it2=s2.find(*it1);
        cout<<it2->first<<" "<<it2->second<<endl;
    }
    s1.clear();
    s2.clear();
    return 0;
}
