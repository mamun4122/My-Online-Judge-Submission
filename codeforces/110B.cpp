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
    int n;
    scanf("%d",&n);
    char a[1000000];
    for(int i=0;i<n;i++)
	{
	    a[i]=(i%4)+97;
	}
	a[n]='\0';
	cout<<a<<endl;
	return 0;
}
