#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int main()
{
	//freopen("file.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+1];
    int x=0;
    for(int i=1;i<=n;i++)
	{
	    scanf("%d",&a[i]);
	    if(i>1&&a[i]<=a[i-1])
	    {
//	        while(a[i]<=a[i-1])
//	        {
//	            a[i]+=m;
//	            x++;
//	        }
            int v=a[i-1]-a[i];
            x+=(v/m)+1;
            a[i]+=((v/m)+1)*m;

	    }
	}
	cout<<x<<endl;
	return 0;
}
