#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define scani(n) scanf("%d",&n)

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll ans;
        ll n,m,x;
        cin>>n>>m>>x;
        ll temp=n/2;
        ll rem=n-temp;
        if(temp>m)
        {
            temp=m;
            ans=m*(n-m)*x;
        }
        else ans=temp*rem*x;
        cout<<temp<<" "<<ans<<endl;
    }
    return 0;
}