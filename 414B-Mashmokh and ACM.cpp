#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3+4, mod = 1e9+7;

int n,k;
int dp[N][N];
int solve(int i, int prev)
{
    if(i == k) return 1;
    int &ret = dp[i][prev];
    if(~ret)
        return ret;
    ret = 0;
    for(int next=prev; next<=n; next+=prev)
        ret += solve(i+ 1, next);
    return ret;
}
int32_t main()
{       
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp , -1, sizeof dp);
    cin >> n >> k;
    cout << solve(0, 1);
    return 0;
}
