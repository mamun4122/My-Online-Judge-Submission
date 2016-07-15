#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int d,a,b,c,cnt,res=0;
    vector<int> v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        res=0;cnt=0;
        scanf("%d%d%d",&a,&b,&c);
        for(int j=1;j<=a;j++)
        {
            scanf("%d",&d);
            v.push_back(d);
        }
        sort(v.begin(),v.end());
        for(int l=0;l<v.size();l++)
        {
            if(cnt<b&&(res+v[l])<=c)
            {
                cnt++;
                res+=v[l];
            }
            else
            {
                break;
            }
        }
        printf("Case %d: %d\n",i,cnt);
        v.clear();
    }
    return 0;
}
