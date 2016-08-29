#include <bits/stdc++.h>
using namespace std;
#define    ll	 long long
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
int t,n,m;
#define MAX 50005
int arr[MAX];
struct info
{
    int pre,suf,sum,tot;
} tree[MAX*3],demo;
info call(info a,info b)
{
    info tmp;
    tmp.sum=max(a.sum,b.sum);
    tmp.sum=max(tmp.sum,a.suf+b.pre);
    tmp.sum=max(tmp.sum,a.tot+b.pre);
    tmp.sum=max(tmp.sum,a.suf+b.tot);
    tmp.sum=max(tmp.sum,a.tot+b.tot);
    tmp.tot=a.tot+b.tot;
    tmp.pre=a.pre;tmp.suf=b.suf;
    tmp.pre=max(tmp.pre,a.tot+b.pre);
    tmp.pre=max(tmp.pre,a.tot+b.tot);
    tmp.suf=max(tmp.suf,a.suf+b.tot);
    tmp.suf=max(tmp.suf,a.tot+b.tot);
    return tmp;
}
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=tree[node].suf=tree[node].pre=arr[b];
        tree[node].tot=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=call(tree[Left],tree[Right]);
}
info query(int node,int b,int e,int i,int j)
{
    if (b >= i && e <= j) return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    if(j<=mid)return query(Left,b,mid,i,j);
    else if(i>mid)return query(Right,mid+1,e,i,j);
    info p1=query(Left,b,mid,i,j);
    info p2=query(Right,mid+1,e,i,j);
    return call(p1,p2);
}
void update(int node,int b,int e,int i,int newvalue)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
        tree[node].sum=tree[node].suf=tree[node].pre=(ll)newvalue;
        tree[node].tot=(ll)newvalue;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,newvalue);
	update(Right,mid+1,e,i,newvalue);
	tree[node]=call(tree[Left],tree[Right]);
}
int main()
{
    while(~getI(n))
    {
        for(int i=1;i<=n;i++)getI(arr[i]);
        init(1,1,n);
        getI(m);
        for(int i=1;i<=m;i++)
        {
            int z,x,y;
            getIII(z,x,y);
            if(z)printf("%d\n",query(1,1,n,x,y).sum);
            else update(1,1,n,x,y);
        }
    }
   return 0;
}
