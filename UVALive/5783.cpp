#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	vector<int> v;
	int sum=1,i=2;
	while(sum<=1000000000)
	{
		v.push_back(sum);
		sum+=i;
		i++;
	}
	int a,b,c,j=1;
	while(scanf("%d%d",&a,&b)&&(a||b))
	{
		int cnt=0,flag=0;
		for(i=a+1;i<b;i++)
		{
			if(flag==0)
				c=sqrt(i);
			if(c*c==i)
			{
				flag=1;
				if(binary_search(v.begin(),v.end(),i-1))
					cnt++;
				i=(c+1)*(c+1);
				c++;
				i-=1;
			}


		}
		printf("Case %d: %d\n",j++,cnt);
	}


	return 0;
}
