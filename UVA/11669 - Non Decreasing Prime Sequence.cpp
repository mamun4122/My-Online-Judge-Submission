#include <bits/stdc++.h>
using namespace std;


#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
///***** finding all divisor
#define M 1000005
bool marked[M];
vector<int> divisor[M];
#define tot 1000000

void sieve(int n)
{
    for(int i=2; i<=tot; i++)
    {
        if(marked[i]==0)
        {
            for(int j=i; j<=tot; j+=i)
            {
                int a=j;
                while(a%i==0)
                {
                    divisor[j].PB(i);
                    a/=i;
                }
                marked[j]=1;
            }
//            debug(i)
        }
    }
}
///********* compare func
bool cmp(int a,int b)
{
    if(divisor[a].size()==divisor[b].size())
    {
        repI(i,divisor[a].size())
        {
            if(divisor[a][i]==divisor[b][i])continue;
            if(divisor[a][i]<divisor[b][i])return true;
            else return false;
        }
    }
    if(divisor[a].size()<divisor[b].size())return true;
    else return false;
}
///********** segment tree
#define MAX 1000005
int arr[MAX];
int tmp[MAX];

struct info
{
    vector<int> v;
} tree[MAX*4];
info call(info a,info b)
{
    info tmp;
    tmp.v.resize(a.v.size()+b.v.size());
    merge(ALL(a.v),ALL(b.v),tmp.v.begin());
//    sort(ALL(tmp.v),cmp);
    return tmp;
}

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].v.resize(1);
        ///aitar jonno numbering korsilam suppose b=2 akhn jdi arr[2]=10 hoi that
        /// means aitar orginally 10 e thakar ktha ja merge korar por oidike jabe ga
        tree[node].v[0]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=call(tree[Left],tree[Right]);
}

pii add(pii a,pii b)
{
    return MP(a.ff+b.ff,a.ss+b.ss);
}
int query(int node,int b,int e,int i,int j,int val)
{
    if (i > e || j < b)return 0;
    if (b >= i && e <= j)
    {
        int pos=upper_bound(ALL(tree[node].v),val)-tree[node].v.begin();
//        debug(val)
        return pos;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j,val);
    int p2=query(Right,mid+1,e,i,j,val);
    return p1+p2;
}
/// idea from nfssdq solution

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve(M-1);
    /// sort korar jonno numbering korsi
    rep(i,tot)tmp[i]=i;
    /// sort korlam number gula k
    sort(tmp+1,tmp+tot+1,cmp);
    /// renumbering korlam jno merge korar por agerta age thake
    rep(i,tot)arr[tmp[i]]=i;
//    debug("")
//    rep(i,10)debug(i,arr[i])
    init(1,1,tot);
//    debug(query(1,1,tot,2,6,arr[2]))
//    rep(i,tot)
    cin>>m;
    rep(i,m)
    {
        int x,y,z;
        cin>>x>>y>>z;
//        debug(x,y,z);
        int ans;
        int low=2,high=tot;
        while(low<=high)
        {
            int mid=(low+high)/2;
            /// mid = dhore nisi oto number pos er val ta
            /// tmp[mid] = org val
            /// arr[tmp[mid]] = duplicate val for tree
            int val=query(1,1,tot,x,y,arr[tmp[mid]]);
//                debug(arr[mid],val.ff,val.ss)
//            debug(val,mid,tmp[mid],arr[tmp[mid]])
            if(val==z&&tmp[mid]>=x&&tmp[mid]<=y)
            {
                ans=mid;
                break;
            }
            if(val>=z)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        ans=tmp[ans];
        cout<<"Case "<<i<<":";
        repI(j,divisor[ans].size())
        {
            cout<<" "<<divisor[ans][j];
        }
        cout<<endl;
    }



    return 0;
}

