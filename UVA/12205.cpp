#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define SET(n) memset(n, -1, sizeof(n))
#define vi vector <int>
#define vii vector < vi >
#define ALL(p) p.begin(), p.end()
const int INF = INT_MAX;

struct data
{
    int s,d,strt,end;
};

bool comp(const data &a, const data &b)
{
    if(a.end < b.end) return true;
    if(a.end == b.end) return a.strt <= b.strt;
    return false;
}

vector <data> vd;



int main()
{
//    freopen("in.txt","r", stdin);

    int n,m;
    while(cin >> n >> m)
    {
        if(n==0 && m==0) break;
        vd.clear();
        FOR(i,1,n)
        {
            data d;
            cin >> d.s >> d.d >> d.strt >> d.end;
            d.end = d.strt + d.end - 1;
            //cout << d.strt << " " << d.end << endl;
            vd.push_back(d);
        }

        sort(ALL(vd), comp);

        FOR(i,1,m)
        {
            int strt, end;
            cin >> strt >> end;
            end = strt + end - 1;

            int cnt = 0;
            int now = -1;
            FOR(j,0,n-1)
            {
                if(vd[j].end < strt || vd[j].strt > end)
                {
                    //cout << strt << " " << end << " " << vd[j].strt << " " << vd[j].end << endl;
                }
                else
                {
                    cnt++;
                    int nowStrt = max(vd[j].strt, strt);
                    //cout << " now " << nowStrt << " " << now << endl;
                    if(nowStrt > now)
                    {
                        now = vd[j].end;
                    }
                    else
                    {
//                        cout << j << endl;
//                        cnt++;
                        now = vd[j].end;
                    }
                }
            }
            if(now == -1) cnt = 0;
            cout <<  cnt << endl;
        }
    }
}

