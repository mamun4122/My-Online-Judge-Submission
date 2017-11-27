#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bit(n)            __builtin_popcount(n)
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

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
///pos curfloor uporer1 uporer2 uporer3
//int dp[5005][3][3][(1<<3)+1][(1<<3)+1][(1<<3)+1][(1<<3)+1];
#define mod 10007
//int call(int pos,int row,int col,int cur,int mask1,int mask2,int mask3)
//{
//    if(pos==0)
//    {
//        if(cur||mask1||mask2||mask3)return 0;
//        return 1;
//    }
//    if(col==3)
//    {
//        if(row==0)return call(pos,row+1,0,cur|mask2,mask1,0,mask3)%mod;
//        if(row==1)return call(pos,row+1,0,cur|mask3,mask1,mask2,0)%mod;
//        if(cur)return 0;
//        return call(pos-1,0,0,mask1,0,mask2,mask3)%mod;
//    }
//    int &ret=dp[pos][row][col][cur][mask1][mask2][mask3];
//    if(ret!=-1)return ret;
//
//    int ans=0;
////    repI(i,3)
////    {
//        int i=col;
//        ///niche jaitesi
//        if(bitCheck(cur,i)==0&&row<2)
//        {
//            int tmp;
//            if(row==0)
//            {
//                if(bitCheck(mask2,i)==0)
//                ans+=call(pos,row,col+1,bitOn(cur,i),mask1,mask2,mask3);
//            }
//            else
//            {
//                if(bitCheck(mask3,i)==0)
//                ans+=call(pos,row,col+1,bitOn(cur,i),mask1,mask2,mask3);
//            }
//        }
//        ans%=mod;
//        ///pashe jaitesi
//        if(col<2&&bitCheck(cur,i)==0&&bitCheck(cur,i+1)==0)
//        {
//            int tmp;
//            if(row==0)
//            {
//                ans+=call(pos,row,col+2,cur,mask1,mask2,mask3);
//            }
//            else if(row==1)
//            {
//                ans+=call(pos,row,col+2,cur,mask1,mask2,mask3);
//            }
//            else
//            {
//                ans+=call(pos,row,col+2,cur,mask1,mask2,mask3);
//
//            }
//        }
//        ans%=mod;
//        ///upore jabo
//        if(bitCheck(cur,i)==0)
//        {
//            if(row==0)
//                ans+=call(pos,row,col+1,cur,bitOn(mask1,i),mask2,mask3);
//            if(row==1)
//                ans+=call(pos,row,col+1,cur,mask1,bitOn(mask2,i),mask3);
//            if(row==2)
//                ans+=call(pos,row,col+1,cur,mask1,mask2,bitOn(mask3,i));
//        }
//        ans%=mod;
//        if(bitCheck(cur,i)==1)
//        {
//            if(row==0)
//                ans+=call(pos,row,col+1,bitOff(cur,i),bitOff(mask1,i),mask2,mask3);
//            if(row==1)
//                ans+=call(pos,row,col+1,bitOff(cur,i),mask1,bitOff(mask2,i),mask3);
//            if(row==2)
//                ans+=call(pos,row,col+1,bitOff(cur,i),mask1,mask2,bitOff(mask3,i));
//        }
//
//        ans%=mod;
//
////    }
//
//
//    return ret=ans%mod;
//}
int ans[]={
    1, 0, 229, 0, 7728, 0, 2069, 0, 4990, 0, 1182, 0, 8338, 0, 3409, 0, 2588, 0, 4676, 0, 5205, 0, 8420, 0, 6749, 0, 6107, 0, 1784, 0, 4701, 0, 3574, 0, 6252, 0, 4989, 0, 1032, 0, 8473, 0, 8155, 0, 2806, 0, 1722, 0, 5647, 0, 825, 0, 3146, 0, 6985, 0, 2399, 0, 8221, 0, 5498, 0, 6088, 0, 1456, 0, 2851, 0, 7552, 0, 467, 0, 5546, 0, 9620, 0, 6629, 0, 3179, 0, 2724, 0, 2089, 0, 5309, 0, 1925, 0, 9558, 0, 3599, 0, 617, 0, 5001, 0, 9233, 0, 8938, 0, 446, 0, 565, 0, 6238, 0, 1185, 0, 2788, 0, 3866, 0, 5933, 0, 7240, 0, 6051, 0, 4471, 0, 5570, 0, 7931, 0, 1561, 0, 7090, 0, 578, 0, 1168, 0, 2493, 0, 1881, 0, 387, 0, 7622, 0, 5509, 0, 5658, 0, 7396, 0, 3949, 0, 1826, 0, 8076, 0, 9188, 0, 6577, 0, 6525, 0, 9082, 0, 2077, 0, 2371, 0, 4217, 0, 4750, 0, 4761, 0, 8223, 0, 4895, 0, 8336, 0, 6271, 0, 9897, 0, 21, 0, 7744, 0, 3513, 0, 7609, 0, 1476, 0, 5080, 0, 475, 0, 6591, 0, 2605, 0, 8946, 0, 7751, 0, 3618, 0, 1949, 0, 6639, 0, 198, 0, 3992, 0, 8096, 0, 7459, 0, 261, 0, 5507, 0, 9909, 0, 3117, 0, 6304, 0, 6274, 0, 7935, 0, 6876, 0, 598, 0, 9705, 0, 1543, 0, 1175, 0, 4953, 0, 2941, 0, 4629, 0, 3460, 0, 4002, 0, 8448, 0, 8013, 0, 1526, 0, 9955, 0, 431, 0, 6857, 0, 1815, 0, 9394, 0, 7071, 0, 5813, 0, 1329, 0, 9306, 0, 9168, 0, 3197, 0, 210, 0, 1421, 0, 8023, 0, 6229, 0, 7986, 0, 9246, 0, 1392, 0, 8709, 0, 4832, 0, 2207, 0, 9401, 0, 6830, 0, 155, 0, 7385, 0, 9343, 0, 8238, 0, 6992, 0, 28, 0, 8313, 0, 8693, 0, 4380, 0, 4695, 0, 1366, 0, 8222, 0, 8315, 0, 2630, 0, 8127, 0, 4536, 0, 3661, 0, 8513, 0, 3607, 0, 9601, 0, 9063, 0, 2394, 0, 2699, 0, 6089, 0, 462, 0, 9806, 0, 236, 0, 5266, 0, 56, 0, 2364, 0, 6563, 0, 2828, 0, 1344, 0, 8645, 0, 9774, 0, 6409, 0, 5983, 0, 8538, 0, 980, 0, 6554, 0, 3231, 0, 1084, 0, 7896, 0, 757, 0, 684, 0, 8091, 0, 6310, 0, 3387, 0, 581, 0, 1738, 0, 8399, 0, 7513, 0, 9194, 0, 1186, 0, 5248, 0, 7882, 0, 3192, 0, 3155, 0, 8706, 0, 8637, 0, 1319, 0, 1047, 0, 4969, 0, 115, 0, 6150, 0, 8814, 0, 9693, 0, 2962, 0, 8474, 0, 1135, 0, 1552, 0, 9947, 0, 8556, 0, 7334, 0, 3386, 0, 7393, 0, 6952, 0, 502, 0, 5653, 0, 2974, 0, 3368, 0, 6459, 0, 809, 0, 1076, 0, 3368, 0, 5180, 0, 7383, 0, 6127, 0, 7509, 0, 3811, 0, 7719, 0, 1053, 0, 6868, 0, 6022, 0, 9115, 0, 6118, 0, 2164, 0, 2641, 0, 2882, 0, 4167, 0, 6684, 0, 1924, 0, 1681, 0, 6751, 0, 7539, 0, 6016, 0, 5979, 0, 1291, 0, 7477, 0, 4828, 0, 7882, 0, 6970, 0, 9718, 0, 9956, 0, 8920, 0, 7145, 0, 7168, 0, 4150, 0, 4565, 0, 7021, 0, 4466, 0, 6934, 0, 9325, 0, 3512, 0, 9705, 0, 8839, 0, 4680, 0, 9476, 0, 4261, 0, 8607, 0, 2690, 0, 4246, 0, 1977, 0, 4731, 0, 7466, 0, 8461, 0, 3016, 0, 74, 0, 7812, 0, 5385, 0, 5897, 0, 208, 0, 9526, 0, 6710, 0, 756, 0, 8231, 0, 7488, 0, 2018, 0, 2912, 0, 7474, 0, 5801, 0, 6898, 0, 3408, 0, 7471, 0, 6769, 0, 6934, 0, 1895, 0, 2164, 0, 3715, 0, 8924, 0, 9916, 0, 443, 0, 477, 0, 2214, 0, 9509, 0, 4013, 0, 1327, 0, 9630, 0, 6383, 0, 4007, 0, 5471, 0, 673, 0, 9814, 0, 259, 0, 6785, 0, 1714, 0, 9041, 0, 6386, 0, 9043, 0, 5792, 0, 33, 0, 1485, 0, 2775, 0, 9218, 0, 3531, 0, 6938, 0, 1990, 0, 1197, 0, 7010, 0, 7329, 0, 6642, 0, 8550, 0, 1170, 0, 9382, 0, 3788, 0, 8321, 0, 4090, 0, 3157, 0, 4728, 0, 5075, 0, 6109, 0, 8443, 0, 7659, 0, 8364, 0, 3294, 0, 5988, 0, 8594, 0, 314, 0, 1280, 0, 1072, 0, 9258, 0, 1797, 0, 7701, 0, 9544, 0, 808, 0, 9181, 0, 2553, 0, 4134, 0, 8991, 0, 3693, 0, 7941, 0, 6162, 0, 6837, 0, 1177, 0, 8223, 0, 1846, 0, 8798, 0, 4966, 0, 189, 0, 5553, 0, 5025, 0, 7135, 0, 305, 0, 6533, 0, 5272, 0, 7538, 0, 1377, 0, 4152, 0, 2607, 0, 5977, 0, 8143, 0, 5019, 0, 8696, 0, 2899, 0, 8727, 0, 1246, 0, 8573, 0, 262, 0, 6766, 0, 7141, 0, 477, 0, 3207, 0, 7082, 0, 5088, 0, 2042, 0, 7081, 0, 7967, 0, 6217, 0, 3214, 0, 5296, 0, 1420, 0, 3135, 0, 1918, 0, 9017, 0, 5212, 0, 8528, 0, 2573, 0, 655, 0, 7066, 0, 7975, 0, 9799, 0, 1513, 0, 4446, 0, 1607, 0, 5805, 0, 1007, 0, 7641, 0, 2442, 0, 6031, 0, 9541, 0, 4672, 0, 6579, 0, 9915, 0, 4553, 0, 2167, 0, 5988, 0, 4460, 0, 3177, 0, 3086, 0, 6859, 0, 2445, 0, 6659, 0, 5387, 0, 8503, 0, 604, 0, 5780, 0, 7166, 0, 8395, 0, 831, 0, 3383, 0, 6907, 0, 9058, 0, 5155, 0, 7918, 0, 9980, 0, 7956, 0, 731, 0, 3133, 0, 6688, 0, 7071, 0, 9706, 0, 8224, 0, 3232, 0, 4456, 0, 6718, 0, 7129, 0, 73, 0, 3615, 0, 5570, 0, 5441, 0, 825, 0, 359, 0, 2396, 0, 8481, 0, 2444, 0, 4860, 0, 4613, 0, 2470, 0, 8638, 0, 9731, 0, 3823, 0, 8241, 0, 3204, 0, 1677, 0, 9977, 0, 1350, 0, 4535, 0, 5747, 0, 3236, 0, 1542, 0, 353, 0, 1746, 0, 7644, 0, 9621, 0, 4835, 0, 362, 0, 8629, 0, 3907, 0, 2876, 0, 3216, 0, 2479, 0, 5952, 0, 9360, 0, 2159, 0, 7921, 0, 1376, 0, 9887, 0, 8367, 0, 8770, 0, 2860, 0, 4755, 0, 7529, 0, 2578, 0, 3354, 0, 6379, 0, 4595, 0, 7825, 0, 156, 0, 6121, 0, 8097, 0, 4807, 0, 6590, 0, 7496, 0, 7958, 0, 2553, 0, 894, 0, 2663, 0, 6343, 0, 5618, 0, 9675, 0, 6691, 0, 7840, 0, 8074, 0, 8645, 0, 4057, 0, 6303, 0, 496, 0, 1763, 0, 8690, 0, 9952, 0, 4306, 0, 8051, 0, 4988, 0, 6582, 0, 4102, 0, 3789, 0, 2405, 0, 1279, 0, 2573, 0, 9825, 0, 4927, 0, 2136, 0, 2683, 0, 5840, 0, 3637, 0, 9126, 0, 2890, 0, 5718, 0, 7752, 0, 5541, 0, 6858, 0, 4295, 0, 5210, 0, 5359, 0, 55, 0, 3249, 0, 2309, 0, 9335, 0, 6685, 0, 368, 0, 7508, 0, 2442, 0, 3136, 0, 9634, 0, 6151, 0, 2267, 0, 4365, 0, 4615, 0, 9482, 0, 7295, 0, 2870, 0, 5213, 0, 8358, 0, 5648, 0, 2176, 0, 6911, 0, 1319, 0, 1746, 0, 8504, 0, 4900, 0, 4905, 0, 1190, 0, 2351, 0, 3588, 0, 1955, 0, 9270, 0, 3566, 0, 3991, 0, 1755, 0, 3745, 0, 5839, 0, 7346, 0, 5308, 0, 8313, 0, 4979, 0, 5649, 0, 6841, 0, 6570, 0, 7739, 0, 1628, 0, 7159, 0, 8639, 0, 7503, 0, 8442, 0, 5078, 0, 3237, 0, 4575, 0, 5910, 0, 3666, 0, 10005, 0, 5928, 0, 9475, 0, 1145, 0, 205, 0, 7401, 0, 2612, 0, 5062, 0, 3654, 0, 1792, 0, 3023, 0, 6882, 0, 3409, 0, 3516, 0, 9102, 0, 3083, 0, 6929, 0, 11, 0, 6577, 0, 9801, 0, 2467, 0, 4210, 0, 8009, 0, 7855, 0, 7258, 0, 3271, 0, 6630, 0, 1339, 0, 692, 0, 5129, 0, 9805, 0, 3263, 0, 5256, 0, 2039, 0, 6678, 0, 264, 0, 739, 0, 9248, 0, 3000, 0, 848, 0, 8224, 0, 7071, 0, 3994, 0, 659, 0, 4409, 0, 3695, 0, 9142, 0, 3955, 0, 5662, 0, 6313, 0, 5429, 0, 6387, 0, 218, 0, 2796, 0, 7556, 0, 4680, 0, 4103, 0, 4690, 0, 6193, 0, 4762, 0, 6401, 0, 4128, 0, 4649, 0, 2297, 0, 3123, 0, 9076, 0, 9510, 0, 4206, 0, 1783, 0, 8357, 0, 6301, 0, 6728, 0, 7399, 0, 4447, 0, 9893, 0, 5441, 0, 7639, 0, 3588, 0, 7580, 0, 8237, 0, 7310, 0, 5261, 0, 3595, 0, 2429, 0, 6799, 0, 8563, 0, 6429, 0, 3401, 0, 7192, 0, 8098, 0, 3098, 0, 3013, 0, 4526, 0, 943, 0, 5770, 0, 8148, 0, 6097, 0, 20, 0, 824, 0, 9122, 0, 3147, 0, 4561, 0, 4668, 0, 4763, 0, 4036, 0, 786, 0, 4056, 0, 6360, 0, 5967, 0, 1454, 0, 5076, 0, 2391, 0, 8861, 0, 1858, 0, 3358, 0, 2202, 0, 2128, 0, 8706, 0, 2348, 0, 1980, 0, 4671, 0, 3548, 0, 524, 0, 947, 0, 9560, 0, 6376, 0, 2629, 0, 893, 0, 2679, 0, 5451, 0, 6379, 0, 2219, 0, 2442, 0, 5742, 0, 905, 0, 5891, 0, 8826, 0, 7717, 0, 2011, 0, 5940, 0, 9408, 0, 7699, 0, 3297, 0, 2291, 0, 3389, 0, 2043, 0, 2408, 0, 5713, 0, 3947, 0, 7707, 0, 9204, 0, 2822, 0, 3510, 0, 7960, 0, 1297, 0, 2960, 0, 4858, 0, 8683, 0, 1789, 0, 5442, 0, 5443, 0, 9817, 0, 444, 0, 1971, 0, 8849, 0, 3991, 0, 8312, 0, 929, 0, 229, 0, 3697, 0, 1764, 0, 2504, 0, 9340, 0, 6073, 0, 7856, 0, 2849, 0, 575, 0, 8046, 0, 3092, 0, 1963, 0, 4197, 0, 2306, 0, 3471, 0, 553, 0, 6370, 0, 8472, 0, 8097, 0, 9286, 0, 3500, 0, 9728, 0, 5378, 0, 7318, 0, 3205, 0, 4191, 0, 8131, 0, 645, 0, 4317, 0, 1353, 0, 337, 0, 3098, 0, 9451, 0, 8172, 0, 3552, 0, 7874, 0, 76, 0, 1378, 0, 4526, 0, 3605, 0, 167, 0, 1642, 0, 3858, 0, 9294, 0, 1252, 0, 7977, 0, 9957, 0, 5546, 0, 2612, 0, 4719, 0, 3500, 0, 4391, 0, 7468, 0, 9524, 0, 5148, 0, 5371, 0, 4367, 0, 4401, 0, 6627, 0, 5053, 0, 6184, 0, 9391, 0, 5826, 0, 4379, 0, 5824, 0, 8712, 0, 4261, 0, 5287, 0, 678, 0, 3150, 0, 2216, 0, 1485, 0, 8879, 0, 6592, 0, 5075, 0, 8990, 0, 9896, 0, 9034, 0, 7038, 0, 5447, 0, 4755, 0, 526, 0, 4665, 0, 8659, 0, 118, 0, 9214, 0, 7252, 0, 830, 0, 1311, 0, 3543, 0, 9609, 0, 4375, 0, 5733, 0, 613, 0, 4280, 0, 1089, 0, 8790, 0, 6130, 0, 6221, 0, 4247, 0, 1506, 0, 8719, 0, 6828, 0, 1248, 0, 2183, 0, 6433, 0, 7331, 0, 671, 0, 7678, 0, 3327, 0, 1750, 0, 4433, 0, 804, 0, 9405, 0, 1310, 0, 760, 0, 1821, 0, 3767, 0, 5855, 0, 9352, 0, 224, 0, 7600, 0, 3612, 0, 1812, 0, 4136, 0, 2659, 0, 9617, 0, 2136, 0, 7714, 0, 2064, 0, 3000, 0, 8444, 0, 7121, 0, 9531, 0, 8131, 0, 666, 0, 6597, 0, 9595, 0, 3846, 0, 8940, 0, 7955, 0, 5754, 0, 5881, 0, 4826, 0, 1478, 0, 4504, 0, 4825, 0, 2745, 0, 2032, 0, 7387, 0, 1742, 0, 559, 0, 6100, 0, 1435, 0, 7635, 0, 897, 0, 3441, 0, 5264, 0, 914, 0, 1451, 0, 3053, 0, 8506, 0, 2359, 0, 2347, 0, 7893, 0, 6747, 0, 9020, 0, 7274, 0, 7172, 0, 2007, 0, 7513, 0, 9535, 0, 8921, 0, 4628, 0, 1228, 0, 3385, 0, 961, 0, 527, 0, 8146, 0, 6873, 0, 4512, 0, 372, 0, 2836, 0, 9962, 0, 8064, 0, 1369, 0, 275, 0, 275, 0, 1588, 0, 4217, 0, 5546, 0, 629, 0, 1100, 0, 6133, 0, 3385, 0, 6944, 0, 3259, 0, 6418, 0, 350, 0, 2866, 0, 3553, 0, 5773, 0, 2872, 0, 1146, 0, 6251, 0, 3460, 0, 1408, 0, 531, 0, 982, 0, 1506, 0, 5542, 0, 1444, 0, 3562, 0, 4292, 0, 1918, 0, 6047, 0, 6775, 0, 5638, 0, 8781, 0, 9462, 0, 2341, 0, 7019, 0, 7121, 0, 7707, 0, 7489, 0, 7948, 0, 7774, 0, 4335, 0, 4754, 0, 6323, 0, 2643, 0, 8090, 0, 6220, 0, 5887, 0, 4675, 0, 6787, 0, 9007, 0, 7232, 0, 4089, 0, 8970, 0, 4982, 0, 2014, 0, 4882, 0, 2444, 0, 9619, 0, 2222, 0, 1580, 0, 4606, 0, 6125, 0, 9648, 0, 3198, 0, 4777, 0, 8219, 0, 3672, 0, 7847, 0, 1402, 0, 6828, 0, 6277, 0, 484, 0, 9792, 0, 2437, 0, 9191, 0, 4238, 0, 2552, 0, 2790, 0, 3345, 0, 5737, 0, 7043, 0, 8339, 0, 7007, 0, 4254, 0, 2948, 0, 8746, 0, 5238, 0, 6616, 0, 9501, 0, 8206, 0, 3612, 0, 2328, 0, 5606, 0, 1537, 0, 7061, 0, 7216, 0, 6044, 0, 925, 0, 6293, 0, 1523, 0, 9841, 0, 3323, 0, 8979, 0, 8746, 0, 1035, 0, 4600, 0, 7372, 0, 7162, 0, 9249, 0, 2547, 0, 9758, 0, 8813, 0, 387, 0, 7297, 0, 1334, 0, 6421, 0, 1920, 0, 7301, 0, 8244, 0, 2285, 0, 564, 0, 1440, 0, 873, 0, 6475, 0, 8244, 0, 7183, 0, 124, 0, 9656, 0, 3181, 0, 1385, 0, 5843, 0, 8395, 0, 2324, 0, 3368, 0, 9405, 0, 6302, 0, 4364, 0, 1731, 0, 8853, 0, 9536, 0, 3172, 0, 4668, 0, 27, 0, 6154, 0, 8634, 0, 772, 0, 7065, 0, 2164, 0, 3252, 0, 6331, 0, 6549, 0, 5148, 0, 6464, 0, 4514, 0, 39, 0, 8438, 0, 8829, 0, 8006, 0, 8876, 0, 7576, 0, 502, 0, 259, 0, 7097, 0, 3701, 0, 3354, 0, 4602, 0, 505, 0, 193, 0, 8243, 0, 3627, 0, 7454, 0, 8613, 0, 3814, 0, 2253, 0, 5376, 0, 2065, 0, 685, 0, 604, 0, 7024, 0, 9883, 0, 7828, 0, 1437, 0, 1431, 0, 9777, 0, 9131, 0, 6845, 0, 803, 0, 5109, 0, 1713, 0, 9178, 0, 5019, 0, 6867, 0, 5271, 0, 2235, 0, 4833, 0, 3372, 0, 7546, 0, 8674, 0, 8646, 0, 1633, 0, 8528, 0, 368, 0, 6501, 0, 5438, 0, 4549, 0, 8654, 0, 5637, 0, 4907, 0, 782, 0, 24, 0, 4320, 0, 5026, 0, 3348, 0, 2301, 0, 4659, 0, 155, 0, 9750, 0, 7388, 0, 5524, 0, 4660, 0, 2520, 0, 1082, 0, 4521, 0, 5196, 0, 840, 0, 6945, 0, 1343, 0, 6061, 0, 3375, 0, 4425, 0, 8478, 0, 6305, 0, 77, 0, 904, 0, 7758, 0, 9098, 0, 1439, 0, 8487, 0, 8422, 0, 7495, 0, 6183, 0, 5283, 0, 5888, 0, 842, 0, 5561, 0, 4142, 0, 1572, 0, 8664, 0, 5762, 0, 8841, 0, 1135, 0, 8542, 0, 747, 0, 3514, 0, 7221, 0, 9149, 0, 9370, 0, 2307, 0, 6575, 0, 9760, 0, 905, 0, 3073, 0, 8864, 0, 3081, 0, 4401, 0, 9369, 0, 8774, 0, 9407, 0, 8446, 0, 9506, 0, 8181, 0, 7994, 0, 297, 0, 2338, 0, 2790, 0, 9483, 0, 536, 0, 3973, 0, 9993, 0, 6321, 0, 4720, 0, 1572, 0, 999, 0, 9217, 0, 2766, 0, 5238, 0, 3820, 0, 333, 0, 4046, 0, 6752, 0, 4453, 0, 1504, 0, 4397, 0, 969, 0, 842, 0, 5841, 0, 8468, 0, 641, 0, 9172, 0, 4544, 0, 6772, 0, 5623, 0, 8632, 0, 1410, 0, 644, 0, 8922, 0, 3047, 0, 5833, 0, 9973, 0, 776, 0, 5251, 0, 4149, 0, 5661, 0, 4534, 0, 8411, 0, 9311, 0, 1374, 0, 7578, 0, 6793, 0, 381, 0, 6329, 0, 1971, 0, 1685, 0, 6067, 0, 7105, 0, 6143, 0, 1347, 0, 6713, 0, 6467, 0, 901, 0, 5328, 0, 6711, 0, 9716, 0, 6326, 0, 7123, 0, 7609, 0, 2062, 0, 4221, 0, 2085, 0, 7716, 0, 5719, 0, 1751, 0, 3127, 0, 2194, 0, 9997, 0, 9963, 0, 6593, 0, 7284, 0, 8388, 0, 1125, 0, 9695, 0, 6150, 0, 2484, 0, 328, 0, 9686, 0, 6238, 0, 6692, 0, 6043, 0, 5663, 0, 5748, 0, 4280, 0, 3971, 0, 5957, 0, 7348, 0, 4096, 0, 7728, 0, 5248, 0, 9143, 0, 9360, 0, 2420, 0, 4921, 0, 2885, 0, 2155, 0, 807, 0, 4677, 0, 968, 0, 2686, 0, 7607, 0, 7306, 0, 2529, 0, 8756, 0, 3311, 0, 4546, 0, 4302, 0, 895, 0, 1055, 0, 8351, 0, 7206, 0, 5177, 0, 49, 0, 2498, 0, 759, 0, 5426, 0, 6274, 0, 1789, 0, 9580, 0, 8941, 0, 3051, 0, 3511, 0, 5980, 0, 4242, 0, 1193, 0, 6246, 0, 54, 0, 7411, 0, 2605, 0, 1723, 0, 5078, 0, 1387, 0, 9425, 0, 4676, 0, 9788, 0, 8198, 0, 9567, 0, 5004, 0, 471, 0, 6996, 0, 1176, 0, 5802, 0, 7576, 0, 4100, 0, 5109, 0, 1603, 0, 5959, 0, 5377, 0, 7980, 0, 1910, 0, 3235, 0, 6257, 0, 5179, 0, 2278, 0, 7895, 0, 1325, 0, 796, 0, 611, 0, 5567, 0, 3443, 0, 2889, 0, 8273, 0, 7748, 0, 469, 0, 4843, 0, 3883, 0, 9544, 0, 9127, 0, 2985, 0, 9970, 0, 3478, 0, 6832, 0, 1952, 0, 7016, 0, 2014, 0, 3518, 0, 9183, 0, 4564, 0, 3553, 0, 8887, 0, 9892, 0, 7479, 0, 2342, 0, 2797, 0, 6919, 0, 8153, 0, 6784, 0, 5561, 0, 5644, 0, 8028, 0, 9789, 0, 116, 0, 561, 0, 6508, 0, 2525, 0, 6496, 0, 2901, 0, 2505, 0, 7635, 0, 8149, 0, 4406, 0, 4281, 0, 2378, 0, 159, 0, 6987, 0, 3863, 0, 6888, 0, 4367, 0, 5032, 0, 7904, 0, 2369, 0, 3882, 0, 9176, 0, 8034, 0, 1496, 0, 6011, 0, 8345, 0, 4386, 0, 8104, 0, 4232, 0, 8194, 0, 6055, 0, 7176, 0, 2652, 0, 7454, 0, 7021, 0, 4844, 0, 1399, 0, 4537, 0, 724, 0, 8504, 0, 6613, 0, 5279, 0, 987, 0, 1285, 0, 5273, 0, 1779, 0, 3763, 0, 4855, 0, 6396, 0, 6588, 0, 9011, 0, 4752, 0, 7767, 0, 7085, 0, 7443, 0, 7241, 0, 5090, 0, 764, 0, 806, 0, 9189, 0, 1686, 0, 5740, 0, 9774, 0, 9797, 0, 416, 0, 2593, 0, 7593, 0, 8425, 0, 5487, 0, 5114, 0, 5058, 0, 1111, 0, 7824, 0, 1455, 0, 9946, 0, 5638, 0, 6035, 0, 2780, 0, 835, 0, 7347, 0, 4808, 0, 5595, 0, 4781, 0, 5081, 0, 8131, 0, 297, 0, 8905, 0, 7887, 0, 9299, 0, 450, 0, 6696, 0, 3994, 0, 6617, 0, 6117, 0, 2938, 0, 2798, 0, 2097, 0, 506, 0, 5896, 0, 5928, 0, 7526, 0, 7344, 0, 9623, 0, 7481, 0, 7558, 0, 4599, 0, 7168, 0, 7051, 0, 1941, 0, 3457, 0, 683, 0, 4912, 0, 9698, 0, 4211, 0, 9167, 0, 4876, 0, 3911, 0, 8930, 0, 8158, 0, 609, 0, 3723, 0, 4893, 0, 8936, 0, 2190, 0, 7238, 0, 2974, 0, 4937, 0, 9097, 0, 4699, 0, 5215, 0, 3716, 0, 9398, 0, 4869, 0, 5946, 0, 6146, 0, 3548, 0, 7345, 0, 5215, 0, 8285, 0, 6233, 0, 1025, 0, 4360, 0, 4366, 0, 7428, 0, 1672, 0, 3897, 0, 1679, 0, 7034, 0, 1163, 0, 7863, 0, 590, 0, 2097, 0, 3476, 0, 6272, 0, 9872, 0, 302, 0, 8036, 0, 8275, 0, 7035, 0, 5716, 0, 4060, 0, 1254, 0, 2920, 0, 8833, 0, 9547, 0, 136, 0, 6244, 0, 7179, 0, 7285, 0, 3565, 0, 9150, 0, 9494, 0, 8486, 0, 2177, 0, 2094, 0, 363, 0, 4224, 0, 3934, 0, 1625, 0, 1014, 0, 6934, 0, 1221, 0, 7, 0, 4079, 0, 3011, 0, 9468, 0, 3432, 0, 6953, 0, 5481, 0, 943, 0, 2871, 0, 2687, 0, 1061, 0, 9641, 0, 191, 0, 1352, 0, 8457, 0, 785, 0, 8761, 0, 5071, 0, 2601, 0, 7768, 0, 908, 0, 2082, 0, 4259, 0, 1759, 0, 1659, 0, 254, 0, 6696, 0, 5762, 0, 8644, 0, 4226, 0, 2095, 0, 4491, 0, 7985, 0, 3732, 0, 8794, 0, 1680, 0, 5209, 0, 5831, 0, 9662, 0, 4680, 0, 3695, 0, 6848, 0, 3121, 0, 9641, 0, 2848, 0, 7296, 0, 8749, 0, 8459, 0, 9331, 0, 7169, 0, 7035, 0, 6336, 0, 1045, 0, 4273, 0, 9876, 0, 5399, 0, 8119, 0, 8607, 0, 3435, 0, 3327, 0, 5390, 0, 7055, 0, 3243, 0, 4870, 0, 7676, 0, 4648, 0, 3902, 0, 3471, 0, 6547, 0, 2700, 0, 6473, 0, 9168, 0, 2119, 0, 8633, 0, 629, 0, 4477, 0, 2621, 0, 2957, 0, 5571, 0, 6239, 0, 7067, 0, 564, 0, 8667, 0, 1365, 0, 5376, 0, 2263, 0, 959, 0, 176, 0, 7579, 0, 7059, 0, 944, 0, 4209, 0, 1927, 0, 9456, 0, 3002, 0, 340, 0, 4743, 0, 2503, 0, 153, 0, 9750, 0, 6874, 0, 2986, 0, 6641, 0, 1398, 0, 1117, 0, 1626, 0, 1044, 0, 5353, 0, 4294, 0, 5967, 0, 3423, 0, 4274, 0, 8103, 0, 10004, 0, 9069, 0, 4239, 0, 6153, 0, 7465, 0, 4068, 0, 9157, 0, 388, 0, 7866, 0, 8246, 0, 6551, 0, 931, 0, 1303, 0, 1207, 0, 2220, 0, 4198, 0, 6990, 0, 808, 0, 891, 0, 2902, 0, 7402, 0, 6800, 0, 2080, 0, 3880, 0, 7455, 0, 9692, 0, 1967, 0, 518, 0, 2443, 0, 5128, 0, 7250, 0, 1782, 0, 1129, 0, 3311, 0, 6849, 0, 4170, 0, 6671, 0, 3639, 0, 8628, 0, 1969, 0, 3989, 0, 5207, 0, 6656, 0, 5458, 0, 5740, 0, 4593, 0, 1328, 0, 6136, 0, 7566, 0, 1295, 0, 9243, 0, 208, 0, 2064, 0, 2163, 0, 4482, 0, 3845, 0, 2064, 0, 2139, 0, 3138, 0, 3482, 0, 1434, 0, 2453, 0, 9291, 0, 9397, 0, 7624, 0, 6695, 0, 4553, 0, 8884, 0, 7550, 0, 5697, 0, 4630, 0, 7083, 0, 6880, 0, 4210, 0, 4082, 0, 4809, 0, 8852, 0, 6604, 0, 4215, 0, 7790, 0, 9672, 0, 3375, 0, 8751, 0, 248, 0, 5702, 0, 2607, 0, 8970, 0, 4526, 0, 9106, 0, 8074, 0, 8844, 0, 2596, 0, 952, 0, 3944, 0, 5711, 0, 948, 0, 8158, 0, 1757, 0, 4865, 0, 1656, 0, 9195, 0, 320, 0, 3669, 0, 948, 0, 3811, 0, 430, 0, 5892, 0, 5234, 0, 3798, 0, 1535, 0, 8355, 0, 4034, 0, 9411, 0, 6605, 0, 8318, 0, 785, 0, 5645, 0, 706, 0, 387, 0, 9016, 0, 9872, 0, 9511, 0, 1169, 0, 4312, 0, 2947, 0, 8635, 0, 8039, 0, 6872, 0, 5998, 0, 6502, 0, 6350, 0, 8918, 0, 257, 0, 3151, 0, 1673, 0, 5175, 0, 8039, 0, 5262, 0, 905, 0, 765, 0, 8992, 0, 2156, 0, 5873, 0, 1761, 0, 2892, 0, 9277, 0, 9895, 0, 8916, 0, 9291, 0, 6031, 0, 6360, 0, 4269, 0, 909, 0, 10, 0, 2112, 0, 2246, 0, 3547, 0, 6660, 0, 5422, 0, 2098, 0, 6333, 0, 8751, 0, 8607, 0, 5303, 0, 4176, 0, 5077, 0, 8870, 0, 3511, 0, 8218, 0, 3958, 0, 7016, 0, 9130, 0, 3836, 0, 2464, 0, 9870, 0, 1441, 0, 9345, 0, 9289, 0, 8697, 0, 3835, 0, 9575, 0, 3829, 0, 8603, 0, 9950, 0, 9103, 0, 1954, 0, 9165, 0, 9093, 0, 3441, 0, 1299, 0, 3463, 0, 182, 0, 7176, 0, 5546, 0, 8033, 0, 8920, 0, 340, 0, 9639, 0, 2215, 0, 926, 0, 6838, 0, 4118, 0, 505, 0, 9051, 0, 6707, 0, 6281, 0, 5234, 0, 8314, 0, 4735, 0, 2572, 0, 1405, 0, 5033, 0, 1332, 0, 5515, 0, 6622, 0, 318, 0, 8659, 0, 6367, 0, 8003, 0, 3355, 0, 7802, 0, 1842, 0, 5500, 0, 2058, 0, 1125, 0, 2744, 0, 6257, 0, 7044, 0, 6456, 0, 9615, 0, 4654, 0, 6215, 0, 6953, 0, 8996, 0, 2276, 0, 756, 0, 147, 0, 8729, 0, 3748, 0, 236, 0, 43, 0, 2745, 0, 8696, 0, 9498, 0, 2357, 0, 6817, 0, 3335, 0, 8468, 0, 2001, 0, 6635, 0, 8117, 0, 4962, 0, 5253, 0, 9687, 0, 6857, 0, 7699, 0, 7066, 0, 3857, 0, 6294, 0, 3599, 0, 5995, 0, 1581, 0, 1859, 0, 6037, 0, 9999, 0, 484, 0, 4892, 0, 4069, 0, 4890, 0, 2214, 0, 6424, 0, 2380, 0, 6296, 0, 2441, 0, 5120, 0, 4142, 0, 8570, 0, 6792, 0, 8007, 0, 9869, 0, 5073, 0, 4650, 0, 6056, 0, 9912, 0, 7727, 0, 6276, 0, 9172, 0, 9303, 0, 8050, 0, 5713, 0, 1244, 0, 9195, 0, 2788, 0, 2241, 0, 5569, 0, 8867, 0, 9029, 0, 2623, 0, 9637, 0, 7633, 0, 2471, 0, 721, 0, 6684, 0, 8818, 0, 6652, 0, 4771, 0, 2960, 0, 2356, 0, 7349, 0, 7069, 0, 8807, 0, 3625, 0, 377, 0, 6252, 0, 6741, 0, 4487, 0, 6592, 0, 2621, 0, 7486, 0, 9835, 0, 7067, 0, 2686, 0, 2497, 0, 4456, 0, 9878, 0, 4319, 0, 3344, 0, 5444, 0, 9750, 0, 8081, 0, 1123, 0, 6134, 0, 7956, 0, 119, 0, 7881, 0, 9741, 0, 1890, 0, 9432, 0, 7842, 0, 8699, 0, 4711, 0, 1495, 0, 8707, 0, 1707, 0, 3368, 0, 3096, 0, 5522, 0, 5479, 0, 2757, 0, 7287, 0, 7028, 0, 653, 0, 3374, 0, 185, 0, 3384, 0, 610, 0, 3646, 0, 6673, 0, 3088, 0, 5701, 0, 1886, 0, 2790, 0, 3677, 0, 6571, 0, 40, 0, 1579, 0, 4394, 0, 4423, 0, 1859, 0, 6193, 0, 4823, 0, 1168, 0, 8617, 0, 6382, 0, 4013, 0, 3140, 0, 1740, 0, 2915, 0, 8878, 0, 15, 0, 1696, 0, 9236, 0, 8943, 0, 3957, 0, 6271, 0, 2182, 0, 1648, 0, 5653, 0, 5560, 0, 6400, 0, 2951, 0, 2861, 0, 8568, 0, 7134, 0, 1353, 0, 2399, 0, 8206, 0, 2701, 0, 434, 0, 179, 0, 8990, 0, 5159, 0, 890, 0, 7214, 0, 1526, 0, 2937, 0, 9054, 0, 529, 0, 86, 0, 3533, 0, 9631, 0, 2166, 0, 4911, 0, 891, 0, 1122, 0, 3536, 0, 2008, 0, 8049, 0, 4840, 0, 3050, 0, 6990, 0, 3236, 0, 371, 0, 7232, 0, 1163, 0, 4893, 0, 6256, 0, 57, 0, 4207, 0, 3805, 0, 4083, 0, 9135, 0, 6223, 0, 314, 0, 6272, 0, 5085, 0, 5122, 0, 9130, 0, 8585, 0, 7224, 0, 7970, 0, 6867, 0, 1882, 0, 4865, 0, 1552, 0, 9057, 0, 8677, 0, 5524, 0, 3677, 0, 694, 0, 8152, 0, 8164, 0, 7676, 0, 2414, 0, 9181, 0, 5459, 0, 8883, 0, 8287, 0, 8959, 0, 7788, 0, 1363, 0, 9760, 0, 5281, 0, 2657, 0, 4472, 0, 1997, 0, 9070, 0, 5863, 0, 9656, 0, 1920, 0, 8339, 0, 5825, 0, 5362, 0, 1655, 0, 2713, 0, 2392, 0, 3407, 0, 242, 0, 7729, 0, 1126, 0, 7508, 0, 2160, 0, 9972, 0, 8972, 0, 1147, 0, 8600, 0, 5840, 0, 5732, 0, 3141, 0, 5213, 0, 6483, 0, 540, 0, 7423, 0, 687, 0, 2360, 0, 4192, 0, 734, 0, 9793, 0, 6569, 0, 9082, 0, 7625, 0, 7004, 0, 6986, 0, 8005, 0, 570, 0, 4357, 0, 1379, 0, 9703, 0, 5221, 0, 7725, 0, 8499, 0, 2868, 0, 6146, 0, 2398, 0, 870, 0, 7728, 0, 7403, 0, 1839, 0, 8933, 0, 4395, 0, 6428, 0, 2291, 0, 805, 0, 9262, 0, 1570, 0, 2306, 0, 7243, 0, 8561, 0, 8550, 0, 3711, 0, 6168, 0, 5228, 0, 5383, 0, 444, 0, 9272, 0, 8619, 0, 1742, 0, 4423, 0, 6095, 0, 1335, 0, 3202, 0, 5634, 0, 8119, 0, 6418, 0, 3112, 0, 4965, 0, 9708, 0, 1095, 0, 9003, 0, 1794, 0, 4472, 0, 9735, 0, 6031, 0, 4869, 0, 8958, 0, 3865, 0, 7011, 0, 770, 0, 5764, 0, 703, 0, 2118, 0, 3634, 0, 6238, 0, 2086, 0, 9472, 0, 829, 0, 9726, 0, 8839, 0, 4819, 0, 5359, 0, 1822, 0, 5704, 0, 3443, 0, 8337, 0, 9984, 0, 8725, 0, 7265, 0, 736, 0, 8888, 0, 6822, 0, 515, 0, 8366, 0, 1552, 0, 2114, 0, 3287, 0, 653, 0, 6497, 0, 9058, 0, 3675, 0, 3696, 0, 3735, 0, 3210, 0, 4833, 0, 6843, 0, 6850, 0, 6205, 0, 4808, 0, 9067, 0, 4936, 0, 6224, 0, 3314, 0, 3339, 0, 6318, 0, 6450, 0, 6390, 0, 4106, 0, 1826, 0, 1751, 0, 887, 0, 5206, 0, 9562, 0, 2631, 0, 6717, 0, 3586, 0, 783, 0, 8160, 0, 4990, 0, 8155, 0, 3939, 0, 8257, 0, 7381, 0, 6372, 0, 6237, 0, 8734, 0, 8304, 0, 3447, 0, 2845, 0, 3016, 0, 2837, 0, 1335, 0, 7191, 0, 4624, 0, 5713, 0, 8696, 0, 901, 0, 7947, 0, 6864, 0, 3197, 0, 514, 0, 2835, 0, 5637, 0, 1658, 0, 1828, 0, 3061, 0, 3915, 0, 4785, 0, 106, 0, 6660, 0, 3331, 0, 914, 0, 6768, 0, 1672, 0, 2846, 0, 1324, 0, 3092, 0, 7475, 0, 3745, 0, 3489, 0, 493, 0, 5468, 0, 1920, 0, 9807, 0, 2221, 0, 9055, 0, 2847, 0, 4940, 0, 6880, 0, 9911, 0, 8257, 0, 559, 0, 1107, 0, 539, 0, 4321, 0, 9122, 0, 673, 0, 2091, 0, 8785, 0, 3789, 0, 7557, 0, 8518, 0, 8571, 0, 9523, 0, 3568, 0, 6875, 0, 8121, 0, 9999, 0, 2820, 0, 1345, 0, 4125, 0, 7760, 0, 9121, 0, 9416, 0, 9865, 0, 2983, 0, 9279, 0, 9201, 0, 4044, 0, 3070, 0, 5918, 0, 4317, 0, 3382, 0, 4714, 0, 6745, 0, 4594, 0, 6277, 0, 3244, 0, 8525, 0, 9338, 0, 1718, 0, 8305, 0, 1075, 0, 6040, 0, 5131, 0, 8207, 0, 7863, 0, 21, 0, 4125, 0, 1966, 0, 5758, 0, 4193, 0, 4616, 0, 8592, 0, 1773, 0, 6399, 0, 4612, 0, 4592, 0, 444, 0, 544, 0, 8796, 0, 1295, 0, 2162, 0, 5629, 0, 1529, 0, 4975, 0, 726, 0, 4816, 0, 6420, 0, 1524, 0, 3518, 0, 180, 0, 8259, 0, 3865, 0, 4790, 0, 3080, 0, 1147, 0, 427, 0, 5755, 0, 7825, 0, 3224, 0, 6723, 0, 1575, 0, 2159, 0, 1126, 0, 8592, 0, 9228, 0, 7324, 0, 333, 0, 1491, 0, 3754, 0, 2822, 0, 1834, 0, 9773, 0, 3421
    };
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
//    SET(dp);
    repI(cs,t)
    {
        getI(n);
        printf("%d\n",ans[n]%mod);
//        n=cs;
//        if(n%2)
//        {
//            printf("0, ");
//            continue;
//        }
//        int ans=call(n,0,0,0,0,0,0);
//        printf("%d, ",ans%mod);
    }

    return 0;
}