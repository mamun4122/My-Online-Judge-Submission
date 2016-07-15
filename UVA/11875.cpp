#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    //freopen("mam","r",stdin);
    int n,a,b;
    vector<int> v;
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&b);
        //a=new int(b+1);
        for(int i=0;i<b;i++)
        {
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.begin()+b);
        printf("Case %d: %d\n",j,v[b/2]);
        v.clear();
        //delete(a);
    }
    return 0;
}
