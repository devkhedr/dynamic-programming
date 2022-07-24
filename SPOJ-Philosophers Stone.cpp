#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

int h,w;
int a[101][101], dp[101][101];
bool valid(int i, int j)
{
    return i<h&&j<w&&i>=0&&j>=0;
}
int solve(int i, int j)
{
    if(!valid(i, j) || i == h)
        return 0;
    int &ret = dp[i][j];
    if(~ret)return ret;
    for(int x=-1;x<=1;x++)
        ret = max(ret, a[i][j] + solve(i+1, j+x));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        clr(dp, -1);
        cin >> h >> w;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin >> a[i][j];
        int mx = 0;
        for(int i=0;i<w;i++)
            mx = max(mx, solve(0, i));
        cout << mx << '\n';
    }
    return 0;
}
