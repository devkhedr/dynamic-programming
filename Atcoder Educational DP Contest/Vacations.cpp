#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

int n;
ll a[N][4], dp[N][4];
ll solve(int i, int prev)
{
    if(i==n)
        return 0;
    ll choice1 =0, choice2 = 0, choice3=0;
    ll &ret = dp[i][prev];
    if(ret != -1)return ret;
    for(int j=1;j<=3;j++)
    {
        if(j != prev)
            ret = max(ret, solve(i+1, j)+a[i][j]);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp,-1);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=3;j++)
            cin >> a[i][j];
    }
    cout << solve(0,0);
    return 0;
}
